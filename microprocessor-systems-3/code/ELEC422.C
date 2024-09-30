#include "fsl_debug_console.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_common.h"
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "cmsis_os2.h"
#include "ELEC422.h"
#include "fsl_adc16.h"         

#define DEMO_ADC16_BASE          		ADC0

void elec422_startup(void)
{
	   /* Define the init structure for the input switch pin */
    gpio_pin_config_t sw_config_SW2 = {kGPIO_DigitalInput, 0,};
    gpio_pin_config_t sw_config_SW3 = {kGPIO_DigitalInput, 0,};
	
    /* Define the init structure for the output LED pin */
    gpio_pin_config_t led_red_config = {kGPIO_DigitalOutput, 0,};
		gpio_pin_config_t led_blue_config = {kGPIO_DigitalOutput, 0,};
		gpio_pin_config_t led_green_config = {kGPIO_DigitalOutput, 0,};
		
		/* Initialise the input pins set the clock and initialise the VCP */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* Init input switch SW2 GPIO. */
    PORT_SetPinInterruptConfig(BOARD_SW2_PORT, BOARD_SW2_GPIO_PIN, kPORT_InterruptEitherEdge); //Change to EitherEdge
    EnableIRQ(BOARD_SW2_IRQ);
    GPIO_PinInit(BOARD_SW2_GPIO, BOARD_SW2_GPIO_PIN, &sw_config_SW2);
	
    /* Init input switch SW3 GPIO. */
    PORT_SetPinInterruptConfig(BOARD_SW3_PORT, BOARD_SW3_GPIO_PIN, kPORT_InterruptEitherEdge); //Change to EitherEdge
    EnableIRQ(BOARD_SW3_IRQ);
    GPIO_PinInit(BOARD_SW3_GPIO, BOARD_SW3_GPIO_PIN, &sw_config_SW3);

    /* Init output LED GPIO. */
    GPIO_PinInit(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, &led_red_config);
		GPIO_PinInit(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, &led_blue_config);
		GPIO_PinInit(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, &led_green_config);
		
		/* Switch off the LEDs */
		LED_Off(0);
		LED_Off(1);
		LED_Off(2);
		
		/* ADC Config */
		adc16_config_t adc16ConfigStruct;
		ADC16_GetDefaultConfig(&adc16ConfigStruct);
		
		/* Initializes the ADC16 module. */
    ADC16_Init(DEMO_ADC16_BASE, &adc16ConfigStruct);
    ADC16_EnableHardwareTrigger(DEMO_ADC16_BASE, false); 
		
		/* Calibration */
		 if (kStatus_Success == ADC16_DoAutoCalibration(DEMO_ADC16_BASE))
    {
        PRINTF("ADC16_DoAutoCalibration() Done.\r\n");
    }
    else
    {
        PRINTF("ADC16_DoAutoCalibration() Failed.\r\n");
    }
}
/* Routine to switch off a LED */
void LED_Off(int led)
{
	switch (led)
	{
		case 0:
			GPIO_PortSet(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN);
			break;
		case 1:
			GPIO_PortSet(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN);
			break;		
		case 2:
			GPIO_PortSet(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN);
			break;
	}
}
/* Routine to switch on a LED */
void LED_On(int led)
{
	switch (led)
	{
		case 0:
			GPIO_PortClear(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN);
			break;
		case 1:
			GPIO_PortClear(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN);
			break;		
		case 2:
			GPIO_PortClear(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN);
			break;
	}
}
/* Routine to Toggle a LED */
void LED_Toggle(int led)
{
	switch (led)
	{
		case 0:
			GPIO_PortToggle(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN);
			break;
		case 1:
			GPIO_PortToggle(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN);
			break;		
		case 2:
			GPIO_PortToggle(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN);
			break;
	}
}
/* Generic Delay to use CPU time */
void delay (int count)
{
unsigned int index;
	for(index =0;index<count;index++)
	{
		;
	}
}
