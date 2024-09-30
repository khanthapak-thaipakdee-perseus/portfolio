/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_debug_console.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_common.h"
#include "fsl_adc16.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_SW_GPIO        GPIOB
#define BOARD_SW_PORT        PORTB
#define BOARD_SW_GPIO_PIN    10U
#define BOARD_SW_IRQ         PORTB_IRQn
#define BOARD_SW_IRQ_HANDLER PORTB_IRQHandler
#define BOARD_SW_NAME        "SW_UP"

#define DEMO_ADC16_BASE          ADC0
#define DEMO_ADC16_CHANNEL_GROUP 0U
#define DEMO_ADC16_USER_CHANNEL  12U /* PTB2, ADC0_SE12 */ /* Pot_1*/
#define DEMO_ADC16_USER_CHANNEL_2  13U /* PTB3, ADC0_SE13 */ /* Pot_2*/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
 
 /*******************************************************************************
 * Variables
 ******************************************************************************/
 
const uint32_t g_Adc16_12bitFullRange = 4096U;

/*******************************************************************************
 * Code
 ******************************************************************************/
 
 void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 60000000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

/*!
 * @brief Interrupt service function of switch.
 *
 */
void BOARD_SW_IRQ_HANDLER(void)
{
#if (defined(FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && FSL_FEATURE_PORT_HAS_NO_INTERRUPT)
    /* Clear external interrupt flag. */
    GPIO_GpioClearInterruptFlags(BOARD_SW_GPIO, 1U << BOARD_SW_GPIO_PIN);
#else
    /* Clear external interrupt flag. */
    GPIO_PortClearInterruptFlags(BOARD_SW_GPIO, 1U << BOARD_SW_GPIO_PIN);
#endif
   
		/* ADC Config */
		adc16_config_t adc16ConfigStruct;
    adc16_channel_config_t adc16ChannelConfigStruct;
	
		/* Set Channel_2 of ADC16 */
		adc16ChannelConfigStruct.channelNumber                       = DEMO_ADC16_USER_CHANNEL_2;
		adc16ChannelConfigStruct.enableInterruptOnConversionCompleted = false;
		
		DisableIRQ(BOARD_SW_IRQ);
	
		ADC16_SetChannelConfig(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP, &adc16ChannelConfigStruct);
		while (0U == (kADC16_ChannelConversionDoneFlag &
					ADC16_GetChannelStatusFlags(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP)))
			{
			}
		
		int g_Adc16ConversionValue_ch2;
			
		/* Read value from Pot_2*/
		g_Adc16ConversionValue_ch2 = ADC16_GetChannelConversionValue(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP);
		
		EnableIRQ(BOARD_SW_IRQ);
			
		PRINTF(" %s is pressed \r\n Pot_2 = %.2f V \r\n\n", BOARD_SW_NAME,3.3/4096*g_Adc16ConversionValue_ch2);	
    SDK_ISR_EXIT_BARRIER;
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Define the init structure for the input switch pin */
    gpio_pin_config_t sw_config = {
        kGPIO_DigitalInput,
        0,
    };

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    /* Print a note to terminal. */
    PRINTF("\r\n ADC16 Pot 1 and Pot 2\r\n");
    PRINTF("\r\n Press %s to read and display value from Pot 2\r\n", BOARD_SW_NAME);

		/* Set input switch GPIO as Pin Interrupt. */
#if (defined(FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && FSL_FEATURE_PORT_HAS_NO_INTERRUPT)
    GPIO_SetPinInterruptConfig(BOARD_SW_GPIO, BOARD_SW_GPIO_PIN, kGPIO_InterruptFallingEdge);
#else
    PORT_SetPinInterruptConfig(BOARD_SW_PORT, BOARD_SW_GPIO_PIN, kPORT_InterruptFallingEdge);
#endif
		
    /* Init input switch GPIO. */
    GPIO_PinInit(BOARD_SW_GPIO, BOARD_SW_GPIO_PIN, &sw_config);
		
		/* ADC Config */
		adc16_config_t adc16ConfigStruct;
    adc16_channel_config_t adc16ChannelConfigStruct;
		
		ADC16_GetDefaultConfig(&adc16ConfigStruct);
#ifdef BOARD_ADC_USE_ALT_VREF
    adc16ConfigStruct.referenceVoltageSource = kADC16_ReferenceVoltageSourceValt;
#endif

		/* Initializes the ADC16 module. */
    ADC16_Init(DEMO_ADC16_BASE, &adc16ConfigStruct);
    ADC16_EnableHardwareTrigger(DEMO_ADC16_BASE, false); /* Make sure the software trigger is used. */
		

		/* Calibration */
#if defined(FSL_FEATURE_ADC16_HAS_CALIBRATION) && FSL_FEATURE_ADC16_HAS_CALIBRATION
    if (kStatus_Success == ADC16_DoAutoCalibration(DEMO_ADC16_BASE))
    {
        PRINTF(" ADC16_DoAutoCalibration() Done.\r\n");
    }
    else
    {
        PRINTF(" ADC16_DoAutoCalibration() Failed.\r\n");
    }
#endif /* FSL_FEATURE_ADC16_HAS_CALIBRATION */

    PRINTF(" ADC Full Range: %d\r\n", g_Adc16_12bitFullRange);	

		
#if defined(FSL_FEATURE_ADC16_HAS_DIFF_MODE) && FSL_FEATURE_ADC16_HAS_DIFF_MODE
    adc16ChannelConfigStruct.enableDifferentialConversion = false;
#endif /* FSL_FEATURE_ADC16_HAS_DIFF_MODE */

	EnableIRQ(BOARD_SW_IRQ);
		
    while (1)
    {		/* Set Channel_1 of ADC16 */
				adc16ChannelConfigStruct.channelNumber                       = DEMO_ADC16_USER_CHANNEL;
				adc16ChannelConfigStruct.enableInterruptOnConversionCompleted = false;

				DisableIRQ(BOARD_SW_IRQ);
			
				ADC16_SetChannelConfig(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP, &adc16ChannelConfigStruct);
			
        while (0U == (kADC16_ChannelConversionDoneFlag &
                      ADC16_GetChannelStatusFlags(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP)))
        {
        }
				
				int g_Adc16ConversionValue_ch1;
				g_Adc16ConversionValue_ch1 = ADC16_GetChannelConversionValue(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP);
				
				EnableIRQ(BOARD_SW_IRQ);
				
				/* Read value from Pot_1*/
        PRINTF(" Pot_1: %.2f V\r\n\n", 3.3/4096*g_Adc16ConversionValue_ch1);
				
				delay();
    }
}
