/*******************************************************************************
* File Name: LidarMotorControl.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the LidarMotorControl
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LidarMotorControl.h"

/** Indicates whether or not the LidarMotorControl has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  LidarMotorControl_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the LidarMotorControl_Start() routine.
*/
uint8_t LidarMotorControl_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated LidarMotorControl_Init() function.
*/ 
cy_stc_tcpwm_pwm_config_t const LidarMotorControl_config =
{
    .pwmMode = 4UL,
    .clockPrescaler = 0UL,
    .pwmAlignment = 0UL,
    .deadTimeClocks = 0UL,
    .runMode = 0UL,
    .period0 = 100UL,
    .period1 = 32768UL,
    .enablePeriodSwap = false,
    .compare0 = 0UL,
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
* Function Name: LidarMotorControl_Start
****************************************************************************//**
*
*  Calls the LidarMotorControl_Init() when called the first time and enables 
*  the LidarMotorControl. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref LidarMotorControl_initVar
*
*******************************************************************************/
void LidarMotorControl_Start(void)
{
    if (0U == LidarMotorControl_initVar)
    {
        (void) Cy_TCPWM_PWM_Init(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, &LidarMotorControl_config);

        LidarMotorControl_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(LidarMotorControl_HW, LidarMotorControl_CNT_MASK);
    
    #if (LidarMotorControl_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(LidarMotorControl_HW, LidarMotorControl_CNT_MASK);
    #endif /* (LidarMotorControl_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
