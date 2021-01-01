/*******************************************************************************
* File Name: MotorSpeedControl.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the MotorSpeedControl
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(MotorSpeedControl_CY_TCPWM_PWM_PDL_H)
#define MotorSpeedControl_CY_TCPWM_PWM_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_pwm.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  MotorSpeedControl_initVar;
extern cy_stc_tcpwm_pwm_config_t const MotorSpeedControl_config;
/** @} group_globals */


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void MotorSpeedControl_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t MotorSpeedControl_Init(cy_stc_tcpwm_pwm_config_t const *config);
__STATIC_INLINE void MotorSpeedControl_DeInit(void);
__STATIC_INLINE void MotorSpeedControl_Enable(void);
__STATIC_INLINE void MotorSpeedControl_Disable(void);
__STATIC_INLINE uint32_t MotorSpeedControl_GetStatus(void);
__STATIC_INLINE void MotorSpeedControl_SetCompare0(uint32_t compare0);
__STATIC_INLINE uint32_t MotorSpeedControl_GetCompare0(void);
__STATIC_INLINE void MotorSpeedControl_SetCompare1(uint32_t compare1);
__STATIC_INLINE uint32_t MotorSpeedControl_GetCompare1(void);
__STATIC_INLINE void MotorSpeedControl_EnableCompareSwap(bool enable);
__STATIC_INLINE void MotorSpeedControl_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t MotorSpeedControl_GetCounter(void);
__STATIC_INLINE void MotorSpeedControl_SetPeriod0(uint32_t period0);
__STATIC_INLINE uint32_t MotorSpeedControl_GetPeriod0(void);
__STATIC_INLINE void MotorSpeedControl_SetPeriod1(uint32_t period1);
__STATIC_INLINE uint32_t MotorSpeedControl_GetPeriod1(void);
__STATIC_INLINE void MotorSpeedControl_EnablePeriodSwap(bool enable);
__STATIC_INLINE void MotorSpeedControl_TriggerStart(void);
__STATIC_INLINE void MotorSpeedControl_TriggerReload(void);
__STATIC_INLINE void MotorSpeedControl_TriggerKill(void);
__STATIC_INLINE void MotorSpeedControl_TriggerSwap(void);
__STATIC_INLINE uint32_t MotorSpeedControl_GetInterruptStatus(void);
__STATIC_INLINE void MotorSpeedControl_ClearInterrupt(uint32_t source);
__STATIC_INLINE void MotorSpeedControl_SetInterrupt(uint32_t source);
__STATIC_INLINE void MotorSpeedControl_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t MotorSpeedControl_GetInterruptMask(void);
__STATIC_INLINE uint32_t MotorSpeedControl_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define MotorSpeedControl_HW                 (MotorSpeedControl_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define MotorSpeedControl_CNT_HW             (MotorSpeedControl_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define MotorSpeedControl_CNT_NUM            (MotorSpeedControl_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define MotorSpeedControl_CNT_MASK           (1UL << MotorSpeedControl_CNT_NUM)
/** @} group_macros */

#define MotorSpeedControl_INPUT_MODE_MASK    (0x3U)
#define MotorSpeedControl_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: MotorSpeedControl_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t MotorSpeedControl_Init(cy_stc_tcpwm_pwm_config_t const *config)
{
    return(Cy_TCPWM_PWM_Init(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: MotorSpeedControl_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_DeInit(void)                   
{
    Cy_TCPWM_PWM_DeInit(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, &MotorSpeedControl_config);
}

/*******************************************************************************
* Function Name: MotorSpeedControl_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(MotorSpeedControl_HW, MotorSpeedControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(MotorSpeedControl_HW, MotorSpeedControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorSpeedControl_GetStatus(void)                
{
    return(Cy_TCPWM_PWM_GetStatus(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorSpeedControl_SetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_SetCompare0(uint32_t compare0)      
{
    Cy_TCPWM_PWM_SetCompare0(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, compare0);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_GetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorSpeedControl_GetCompare0(void)              
{
    return(Cy_TCPWM_PWM_GetCompare0(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorSpeedControl_SetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_SetCompare1(uint32_t compare1)      
{
    Cy_TCPWM_PWM_SetCompare1(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, compare1);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_GetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorSpeedControl_GetCompare1(void)              
{
    return(Cy_TCPWM_PWM_GetCompare1(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorSpeedControl_EnableCompareSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnableCompareSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_EnableCompareSwap(bool enable)  
{
    Cy_TCPWM_PWM_EnableCompareSwap(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_SetCounter(uint32_t count)          
{
    Cy_TCPWM_PWM_SetCounter(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorSpeedControl_GetCounter(void)               
{
    return(Cy_TCPWM_PWM_GetCounter(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorSpeedControl_SetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_SetPeriod0(uint32_t period0)          
{
    Cy_TCPWM_PWM_SetPeriod0(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, period0);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_GetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorSpeedControl_GetPeriod0(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod0(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorSpeedControl_SetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_SetPeriod1(uint32_t period1)
{
    Cy_TCPWM_PWM_SetPeriod1(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, period1);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_GetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorSpeedControl_GetPeriod1(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod1(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorSpeedControl_EnablePeriodSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnablePeriodSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_EnablePeriodSwap(bool enable)
{
    Cy_TCPWM_PWM_EnablePeriodSwap(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(MotorSpeedControl_HW, MotorSpeedControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(MotorSpeedControl_HW, MotorSpeedControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_TriggerKill
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_TriggerKill(void)
{
    Cy_TCPWM_TriggerStopOrKill(MotorSpeedControl_HW, MotorSpeedControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_TriggerSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_TriggerSwap(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(MotorSpeedControl_HW, MotorSpeedControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorSpeedControl_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorSpeedControl_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorSpeedControl_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: MotorSpeedControl_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorSpeedControl_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorSpeedControl_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorSpeedControl_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(MotorSpeedControl_HW, MotorSpeedControl_CNT_NUM));
}

#endif /* MotorSpeedControl_CY_TCPWM_PWM_PDL_H */


/* [] END OF FILE */
