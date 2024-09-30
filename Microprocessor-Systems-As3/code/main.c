/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/
#include <cmsis_os2.h>
#include "fsl_debug_console.h"  
#include "ELEC422.h"
#include "board.h"
#include <string.h>
#include "fsl_adc16.h"
#include <stdio.h>

#define DEMO_ADC16_BASE          		ADC0
#define DEMO_ADC16_CHANNEL_GROUP 		0U
#define DEMO_ADC16_USER_CHANNEL  		12U /* PTB2, ADC0_SE12 */ /* Pot_1*/
#define DEMO_ADC16_USER_CHANNEL_2  	13U /* PTB3, ADC0_SE13 */ /* Pot_2*/
        
//define the threads allow two switches (SW3, SW2) and LEDswitch(LEDs)
osThreadId_t app_mainid,T_SW3,T_SW2,T_LEDs;	

//ADC2 thread and ADCMutex
osThreadId_t T_ADC2;
osMutexId_t ADCMutex;	

typedef struct {
    uint8_t 	canData[128];
} message_t;
osMemoryPoolId_t memblock, memblock_sampleperiod;
osMessageQueueId_t msgqueue, queue_sampleperiod;

void printstr (char *status)
{		
		message_t *message;	
		message = (message_t *)osMemoryPoolAlloc(memblock,osWaitForever);				//Allocate a memory block
		strcpy((char *)message->canData,(status));															//Copy status to canData at index 0						
		
		osMessageQueuePut(msgqueue, &message, NULL, osWaitForever);							//Post pointer to memory block
}

void printchar(char c) {
    char str[2]; // String to hold the character and null terminator
    str[0] = c;
    str[1] = '\0'; // Null terminator
    
    printstr(str); // Call printstr with the character converted to a string
}

uint32_t readnumber(void)
{		uint32_t number = 0;
		char c;
//	char buffer[128];
		c = GETCHAR();										
		printchar(c);	
		if(c == ' ')
			{
				c = GETCHAR();																												
				printchar(c);	
					while ((c >= '0' && c <= '9')|| c == 127) 
						{
//							sprintf(buffer, "\n\rASCII = %d\n\r", c);
//							printstr(buffer);
							
							if(c==127)
								number = number / 10 ;
							else
								number = number * 10 + (c - '0');
							c = GETCHAR();																												
							printchar(c);	
						}
//						sprintf(buffer, "\n\rNumber = %d\n\r", number);
//						printstr(buffer);
				}
			return number;
}
/*----------------------------------------------------------------------------
	Thread1: Producer thread for mailbox
 *---------------------------------------------------------------------------*/
static const osThreadAttr_t ThreadAttr_producer = {.name = "producer",};
__NO_RETURN void producer_thread (void  *args) {
message_t *message;																													//Define pointer for memory block
char c;
int sample_period;
	
	while (1)
		{	
			c = GETCHAR();																												//Wait for the user to input a character
			printchar(c);			
			if (c == '1'){
				sample_period = readnumber();
			}
			
			/* Check that time change more than 0*/	
			if(sample_period > 0)					
					osMessageQueuePut(queue_sampleperiod, &sample_period, NULL, osWaitForever);
						
			/* Check condition of c and set flags. */
			if (c == 'R')
					osThreadFlagsSet (T_LEDs,0x01);	
			else if	(c == 'r')
					osThreadFlagsSet (T_LEDs,0x02);	
			else if	(c == 'G')
					osThreadFlagsSet (T_LEDs,0x04);	
			else if	(c == 'g')
					osThreadFlagsSet (T_LEDs,0x08);	
			else if	(c == 'B')
					osThreadFlagsSet (T_LEDs,0x10);	
			else if	(c == 'b')
					osThreadFlagsSet (T_LEDs,0x20);	
			else if	(c == '2')
					osThreadFlagsSet (T_ADC2,0x01);
	}
}

/*----------------------------------------------------------------------------
  Thread2: Consumer thread for mailbox
 *---------------------------------------------------------------------------*/
static const osThreadAttr_t ThreadAttr_consumer = {.name = "consumer",};
__NO_RETURN void consumer_thread (void  *args){
message_t *message;

	while (1) {
		osMessageQueueGet(msgqueue, &message, NULL, osWaitForever);	
		PRINTF("%s",message->canData);																						//PRINTF message to PC
		osMemoryPoolFree(memblock, message);																			//Release the memblock
	}
}

/*----------------------------------------------------------------------------
  SW2_IRQ 
 *---------------------------------------------------------------------------*/
void BOARD_SW2_IRQ_HANDLER(void)
{
    /* Clear external interrupt flag. */
    GPIO_PortClearInterruptFlags(BOARD_SW2_GPIO, 1U << BOARD_SW2_GPIO_PIN);
		
		/* Read SW2 pin.*/
		uint32_t sw2_value;
		sw2_value = GPIO_PinRead(BOARD_SW2_GPIO, BOARD_SW2_GPIO_PIN);	
	
		/* Set either flag0 or flag1. */
		if (sw2_value == 0)
		{
		osThreadFlagsSet	(T_SW2,0x01);
		}
		else if(sw2_value == 1)
			{
		osThreadFlagsSet	(T_SW2,0x02);
		}
}

/*----------------------------------------------------------------------------
  SW3_IRQ
 *---------------------------------------------------------------------------*/
void BOARD_SW3_IRQ_HANDLER(void)
{
    /* Clear external interrupt flag. */
    GPIO_PortClearInterruptFlags(BOARD_SW3_GPIO, 1U << BOARD_SW3_GPIO_PIN);
	
		/* Read SW3 pin.*/
		uint32_t sw3_value;
		sw3_value = GPIO_PinRead(BOARD_SW3_GPIO, BOARD_SW3_GPIO_PIN);	
	
		/* Set either flag0 or flag1 */
		if (sw3_value == 0)
		{
		osThreadFlagsSet	(T_SW3,0x01);
		}
		else if(sw3_value == 1)
		{
		osThreadFlagsSet	(T_SW3,0x02);
		}
}

/*----------------------------------------------------------------------------
  SW2_status , SW3_status Threads (Thread3, Thread4)
 *---------------------------------------------------------------------------*/
static const osThreadAttr_t ThreadAttr_SW3_IR = {	.name = 	"SW3",	};
static const osThreadAttr_t ThreadAttr_SW2_IR = { .name = 	"SW2",	};

__NO_RETURN void SW2_status (void  *argument) {
	for (;;) {
		char str1[128] = "\n\rSW2_pressed\n\r";
		char str2[128] = "\n\rSW2_released\n\r";
		char status[128];
			
		/* Wait for flag and check flag. */
		uint8_t flag;
		flag = osThreadFlagsWait (0x03,osFlagsWaitAny,osWaitForever);
		/* Check value of flag */
		if (flag == 0x01){
			strcpy(status, str1);
		}
		else if(flag == 0x02) {
			strcpy(status, str2);
		}
		printstr(status);		// Call printstr function	
	}
}

__NO_RETURN void SW3_status (void  *argument) {
	for (;;) {
		uint8_t index;
		char str1[128] = "\n\rSW3_pressed\n\r";
		char str2[128] = "\n\rSW3_released\n\r";
		char status[128];
		
		/* Wait for flag and check flag. */
		uint8_t flag;
		flag = osThreadFlagsWait (0x03,osFlagsWaitAny,osWaitForever);
		/* Check value of flag */
		if (flag == 0x01){
			strcpy(status, str1);
		}
		else if(flag == 0x02){
			strcpy(status, str2);
		}
		printstr(status);			// Call printstr function	
	}
}

/*----------------------------------------------------------------------------
  LEDs_Swicher Thread (Thread5)
 *---------------------------------------------------------------------------*/
static const osThreadAttr_t ThreadAttr_LEDswitcher = { .name = 	"LEDswitcher",	};

__NO_RETURN void LEDs_switcher(void  *argument) {
	for (;;) {
		/* Wait for flag and check flag. */
		uint8_t flag;
		flag = osThreadFlagsWait(0x3F,osFlagsWaitAny,osWaitForever); 	
		if (flag	== 0x01)
			{
			LED_On(0);
			}
		else if (flag == 0x02)
			{
			LED_Off(0);
			}
		else if (flag ==  0x04)
			{
			LED_On(1);
			}
		else if (flag ==  0x08)
			{
			LED_Off(1);
			}
		else if (flag ==  0x10)
			{
			LED_On(2);
			}
		else if (flag ==  0x20)
			{
			LED_Off(2);
			}
	}
}

/*----------------------------------------------------------------------------
	Callback function of Thread6
 *---------------------------------------------------------------------------*/
 
void ADC1_callback (void  *argument) {
		static uint32_t tick = 0U;
		tick = osKernelGetTickCount();
		//Assign channe1_1 to adc16 struct.
		adc16_channel_config_t adc16ChannelConfigStruct;
		adc16ChannelConfigStruct.channelNumber                       		= DEMO_ADC16_USER_CHANNEL;
		adc16ChannelConfigStruct.enableDifferentialConversion 					= false;
		
		//Ask for Mutex to prevent a collusion in ADC conversion.
		osMutexAcquire(ADCMutex, osWaitForever);
		
		//ADC Conversion
		ADC16_SetChannelConfig(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP, &adc16ChannelConfigStruct);
		
		while (0U == (kADC16_ChannelConversionDoneFlag & ADC16_GetChannelStatusFlags(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP)))
			{
      }
		int g_Adc16ConversionValue_ch1;
		g_Adc16ConversionValue_ch1 = ADC16_GetChannelConversionValue(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP);
			
		//Release Mutex after finishing ADC conversion.
		osMutexRelease(ADCMutex);
			
		float Adc_value_ch1;
		Adc_value_ch1 = 3.3*g_Adc16ConversionValue_ch1/4096;

		char buffer[128];
		// Format the string "ADC1 = <value>" and store it in buffer
		sprintf(buffer, "\n\rADC1 = %.2f V\n\r", Adc_value_ch1);

		// Call printstr function	
		printstr(buffer);
			
		sprintf(buffer, "Time = %u\n\r", tick);
		printstr(buffer);
}

/*----------------------------------------------------------------------------
	Thread 6: ADC1
 *---------------------------------------------------------------------------*/
//ADC1 timer thread
osTimerId_t T_ADC1_periodic; 

static const  osTimerAttr_t timerAttr_timerADC1 = {.name = "timer_ADC1",};
static const osThreadAttr_t ThreadAttr_ADC1 = {.name = "ADC1",};
__NO_RETURN void ADC1_Thread6 (void  *argument) {
	
	T_ADC1_periodic = osTimerNew(&ADC1_callback, osTimerPeriodic,(void *)0, &timerAttr_timerADC1); //callback function of Thread6
	uint32_t interval_ms = 1000000; //10000ms = 10s
	osTimerStart(T_ADC1_periodic , interval_ms);
	
	while(1){
			uint32_t newperiod;
			osMessageQueueGet(queue_sampleperiod, &newperiod, NULL, osWaitForever);
			osTimerStop(T_ADC1_periodic);
			osTimerStart(T_ADC1_periodic , newperiod);
	}
}

/*----------------------------------------------------------------------------
	Thread 7: ADC2 to read value of ADC2
 *---------------------------------------------------------------------------*/
static const osThreadAttr_t ThreadAttr_ADC2 = {.name = "ADC2",};
__NO_RETURN void ADC2_Thread7 (void  *argument) {
	for(;;){
		osThreadFlagsWait(0x01,osFlagsWaitAny,osWaitForever); 	
		
		//Assign channel_2 to adc16 struct
		adc16_channel_config_t adc16ChannelConfigStruct;
		adc16ChannelConfigStruct.channelNumber                       		= DEMO_ADC16_USER_CHANNEL_2;
		adc16ChannelConfigStruct.enableDifferentialConversion 					= false;
		
		//Ask for Mutex to prevent a collusion in ADC conversion.
		osMutexAcquire(ADCMutex, osWaitForever);
		
		//ADC Conversion
		ADC16_SetChannelConfig(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP, &adc16ChannelConfigStruct);
		
		while (0U == (kADC16_ChannelConversionDoneFlag & ADC16_GetChannelStatusFlags(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP)))
			{
      }
		int g_Adc16ConversionValue_ch2;
		g_Adc16ConversionValue_ch2 = ADC16_GetChannelConversionValue(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP);
			
		//Release Mutex after finishing ADC conversion.
		osMutexRelease(ADCMutex);
		
		float Adc_value_ch2;			
		Adc_value_ch2 = 3.3*g_Adc16ConversionValue_ch2/4096;
			
		char buffer[128];
		// Format the string "ADC2 = <value>" and store it in buffer
		sprintf(buffer, "\n\rADC2 = %.2f V\n\r", Adc_value_ch2);

		// Call printstr function	
		printstr(buffer);	
	}
}

 /*----------------------------------------------------------------------------
 Start the RTOS
 *---------------------------------------------------------------------------*/
static const osMemoryPoolAttr_t memorypoolAttr_memblock ={.name = "memory_pool",};
static const osMemoryPoolAttr_t memorypoolAttr_mem_sampleperiod ={.name = "memory_sampleperiod",};
static const osThreadAttr_t ThreadAttr_main = {.name = "main",};
static const osThreadAttr_t ThreadAttr_app_main = {	.name = "app_main",	};
static const osMutexAttr_t MutexAttr_ADCMutex = {.name = "ADCMutex",};


void app_main (void *argument) {
    memblock = osMemoryPoolNew(16, sizeof(message_t),&memorypoolAttr_memblock );
    msgqueue = osMessageQueueNew(16, 4, NULL);
    queue_sampleperiod = osMessageQueueNew(16, 4, NULL);
	
		osThreadNew(producer_thread, NULL, &ThreadAttr_producer); 						//Thread1: Producer
    osThreadNew(consumer_thread, NULL, &ThreadAttr_consumer);							//Thread2: Consumer
	
		T_SW2 = osThreadNew(SW2_status, NULL, &ThreadAttr_SW2_IR);						//Thread3: SW2_status
		T_SW3 = osThreadNew(SW3_status, NULL, &ThreadAttr_SW3_IR);						//Thread4: SW3_status
	
		T_LEDs = osThreadNew(LEDs_switcher, NULL, &ThreadAttr_LEDswitcher);		//Thread5: LEDs_switcher
	
		ADCMutex = osMutexNew(&MutexAttr_ADCMutex );													//Mutex is used to prevent ADC conversion collision
	
		osThreadNew(ADC1_Thread6, NULL, &ThreadAttr_ADC1);										//Thread6: ADC1
		T_ADC2 = osThreadNew(ADC2_Thread7, NULL, &ThreadAttr_ADC2);						//Thread7: ADC2	

		app_mainid = osThreadGetId();
		osThreadTerminate(app_mainid);
}

	int main (void) {
	char c;
  SystemCoreClockUpdate();
  elec422_startup();
	PRINTF("Started\n\r");
  osKernelInitialize();                 									// Initialize CMSIS-RTOS
  osThreadNew(app_main, NULL, &ThreadAttr_main);    			// Create application main thread
  if (osKernelGetState() == osKernelReady) 
	{
    osKernelStart();                    									// Start thread execution
  }
  while(1);
}
