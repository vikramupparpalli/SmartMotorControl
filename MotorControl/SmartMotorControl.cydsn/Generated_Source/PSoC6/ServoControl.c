/*******************************************************************************
* File Name: ServoControl.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the ServoControl
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ServoControl.h"

/** Indicates whether or not the ServoControl has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  ServoControl_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the ServoControl_Start() routine.
*/
uint8_t ServoControl_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated ServoControl_Init() function.
*/ 
cy_stc_tcpwm_pwm_config_t const ServoControl_config =
{
    .pwmMode = 4UL,
    .clockPrescaler = 0UL,
    .pwmAlignment = 2UL,
    .deadTimeClocks = 0UL,
    .runMode = 0UL,
    .period0 = 4800UL,
    .period1 = 32768UL,
    .enablePeriodSwap = false,
    .compare0 = 4520UL,
    .compare1 = 16384UL,
    .enableCompareSwap = false,
    .interruptSources = 0UL,
    .invertPWMOut = 0UL,
    .invertPWMOutN = 0UL,
    .killMode = 2UL,
    .swapInputMode = 3UL,
    .swapInput = CY_TCPWM_INPUT_CREATOR,
    .reloadInputMode = 3UL,
    .reloadInput = CY_TCPWM_INPUT_CREATOR,
    .startInputMode = 3UL,
    .startInput = CY_TCPWM_INPUT_CREATOR,
    .killInputMode = 3UL,
    .killInput = CY_TCPWM_INPUT_CREATOR,
    .countInputMode = 3UL,
    .countInput = CY_TCPWM_INPUT_CREATOR,
};


/*******************************************************************************
* Function Name: ServoControl_Start
****************************************************************************//**
*
*  Calls the ServoControl_Init() when called the first time and enables 
*  the ServoControl. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref ServoControl_initVar
*
*******************************************************************************/
void ServoControl_Start(void)
{
    if (0U == ServoControl_initVar)
    {
        (void) Cy_TCPWM_PWM_Init(ServoControl_HW, ServoControl_CNT_NUM, &ServoControl_config);

        ServoControl_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(ServoControl_HW, ServoControl_CNT_MASK);
    
    #if (ServoControl_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(ServoControl_HW, ServoControl_CNT_MASK);
    #endif /* (ServoControl_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
