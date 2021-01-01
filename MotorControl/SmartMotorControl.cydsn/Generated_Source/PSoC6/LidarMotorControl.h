/*******************************************************************************
* File Name: LidarMotorControl.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the LidarMotorControl
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(LidarMotorControl_CY_TCPWM_PWM_PDL_H)
#define LidarMotorControl_CY_TCPWM_PWM_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_pwm.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  LidarMotorControl_initVar;
extern cy_stc_tcpwm_pwm_config_t const LidarMotorControl_config;
/** @} group_globals */


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void LidarMotorControl_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t LidarMotorControl_Init(cy_stc_tcpwm_pwm_config_t const *config);
__STATIC_INLINE void LidarMotorControl_DeInit(void);
__STATIC_INLINE void LidarMotorControl_Enable(void);
__STATIC_INLINE void LidarMotorControl_Disable(void);
__STATIC_INLINE uint32_t LidarMotorControl_GetStatus(void);
__STATIC_INLINE void LidarMotorControl_SetCompare0(uint32_t compare0);
__STATIC_INLINE uint32_t LidarMotorControl_GetCompare0(void);
__STATIC_INLINE void LidarMotorControl_SetCompare1(uint32_t compare1);
__STATIC_INLINE uint32_t LidarMotorControl_GetCompare1(void);
__STATIC_INLINE void LidarMotorControl_EnableCompareSwap(bool enable);
__STATIC_INLINE void LidarMotorControl_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t LidarMotorControl_GetCounter(void);
__STATIC_INLINE void LidarMotorControl_SetPeriod0(uint32_t period0);
__STATIC_INLINE uint32_t LidarMotorControl_GetPeriod0(void);
__STATIC_INLINE void LidarMotorControl_SetPeriod1(uint32_t period1);
__STATIC_INLINE uint32_t LidarMotorControl_GetPeriod1(void);
__STATIC_INLINE void LidarMotorControl_EnablePeriodSwap(bool enable);
__STATIC_INLINE void LidarMotorControl_TriggerStart(void);
__STATIC_INLINE void LidarMotorControl_TriggerReload(void);
__STATIC_INLINE void LidarMotorControl_TriggerKill(void);
__STATIC_INLINE void LidarMotorControl_TriggerSwap(void);
__STATIC_INLINE uint32_t LidarMotorControl_GetInterruptStatus(void);
__STATIC_INLINE void LidarMotorControl_ClearInterrupt(uint32_t source);
__STATIC_INLINE void LidarMotorControl_SetInterrupt(uint32_t source);
__STATIC_INLINE void LidarMotorControl_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t LidarMotorControl_GetInterruptMask(void);
__STATIC_INLINE uint32_t LidarMotorControl_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define LidarMotorControl_HW                 (LidarMotorControl_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define LidarMotorControl_CNT_HW             (LidarMotorControl_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define LidarMotorControl_CNT_NUM            (LidarMotorControl_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define LidarMotorControl_CNT_MASK           (1UL << LidarMotorControl_CNT_NUM)
/** @} group_macros */

#define LidarMotorControl_INPUT_MODE_MASK    (0x3U)
#define LidarMotorControl_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: LidarMotorControl_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t LidarMotorControl_Init(cy_stc_tcpwm_pwm_config_t const *config)
{
    return(Cy_TCPWM_PWM_Init(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: LidarMotorControl_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_DeInit(void)                   
{
    Cy_TCPWM_PWM_DeInit(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, &LidarMotorControl_config);
}

/*******************************************************************************
* Function Name: LidarMotorControl_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(LidarMotorControl_HW, LidarMotorControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: LidarMotorControl_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(LidarMotorControl_HW, LidarMotorControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: LidarMotorControl_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarMotorControl_GetStatus(void)                
{
    return(Cy_TCPWM_PWM_GetStatus(LidarMotorControl_HW, LidarMotorControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: LidarMotorControl_SetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_SetCompare0(uint32_t compare0)      
{
    Cy_TCPWM_PWM_SetCompare0(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, compare0);
}


/*******************************************************************************
* Function Name: LidarMotorControl_GetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarMotorControl_GetCompare0(void)              
{
    return(Cy_TCPWM_PWM_GetCompare0(LidarMotorControl_HW, LidarMotorControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: LidarMotorControl_SetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_SetCompare1(uint32_t compare1)      
{
    Cy_TCPWM_PWM_SetCompare1(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, compare1);
}


/*******************************************************************************
* Function Name: LidarMotorControl_GetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarMotorControl_GetCompare1(void)              
{
    return(Cy_TCPWM_PWM_GetCompare1(LidarMotorControl_HW, LidarMotorControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: LidarMotorControl_EnableCompareSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnableCompareSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_EnableCompareSwap(bool enable)  
{
    Cy_TCPWM_PWM_EnableCompareSwap(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: LidarMotorControl_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_SetCounter(uint32_t count)          
{
    Cy_TCPWM_PWM_SetCounter(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: LidarMotorControl_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarMotorControl_GetCounter(void)               
{
    return(Cy_TCPWM_PWM_GetCounter(LidarMotorControl_HW, LidarMotorControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: LidarMotorControl_SetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_SetPeriod0(uint32_t period0)          
{
    Cy_TCPWM_PWM_SetPeriod0(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, period0);
}


/*******************************************************************************
* Function Name: LidarMotorControl_GetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarMotorControl_GetPeriod0(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod0(LidarMotorControl_HW, LidarMotorControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: LidarMotorControl_SetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_SetPeriod1(uint32_t period1)
{
    Cy_TCPWM_PWM_SetPeriod1(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, period1);
}


/*******************************************************************************
* Function Name: LidarMotorControl_GetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarMotorControl_GetPeriod1(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod1(LidarMotorControl_HW, LidarMotorControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: LidarMotorControl_EnablePeriodSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnablePeriodSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_EnablePeriodSwap(bool enable)
{
    Cy_TCPWM_PWM_EnablePeriodSwap(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: LidarMotorControl_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(LidarMotorControl_HW, LidarMotorControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: LidarMotorControl_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(LidarMotorControl_HW, LidarMotorControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: LidarMotorControl_TriggerKill
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_TriggerKill(void)
{
    Cy_TCPWM_TriggerStopOrKill(LidarMotorControl_HW, LidarMotorControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: LidarMotorControl_TriggerSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_TriggerSwap(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(LidarMotorControl_HW, LidarMotorControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: LidarMotorControl_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarMotorControl_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(LidarMotorControl_HW, LidarMotorControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: LidarMotorControl_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: LidarMotorControl_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: LidarMotorControl_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarMotorControl_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(LidarMotorControl_HW, LidarMotorControl_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: LidarMotorControl_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarMotorControl_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(LidarMotorControl_HW, LidarMotorControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: LidarMotorControl_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarMotorControl_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(LidarMotorControl_HW, LidarMotorControl_CNT_NUM));
}

#endif /* LidarMotorControl_CY_TCPWM_PWM_PDL_H */


/* [] END OF FILE */
