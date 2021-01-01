/*******************************************************************************
* File Name: ServoControl.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the ServoControl
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(ServoControl_CY_TCPWM_PWM_PDL_H)
#define ServoControl_CY_TCPWM_PWM_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_pwm.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  ServoControl_initVar;
extern cy_stc_tcpwm_pwm_config_t const ServoControl_config;
/** @} group_globals */


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void ServoControl_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t ServoControl_Init(cy_stc_tcpwm_pwm_config_t const *config);
__STATIC_INLINE void ServoControl_DeInit(void);
__STATIC_INLINE void ServoControl_Enable(void);
__STATIC_INLINE void ServoControl_Disable(void);
__STATIC_INLINE uint32_t ServoControl_GetStatus(void);
__STATIC_INLINE void ServoControl_SetCompare0(uint32_t compare0);
__STATIC_INLINE uint32_t ServoControl_GetCompare0(void);
__STATIC_INLINE void ServoControl_SetCompare1(uint32_t compare1);
__STATIC_INLINE uint32_t ServoControl_GetCompare1(void);
__STATIC_INLINE void ServoControl_EnableCompareSwap(bool enable);
__STATIC_INLINE void ServoControl_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t ServoControl_GetCounter(void);
__STATIC_INLINE void ServoControl_SetPeriod0(uint32_t period0);
__STATIC_INLINE uint32_t ServoControl_GetPeriod0(void);
__STATIC_INLINE void ServoControl_SetPeriod1(uint32_t period1);
__STATIC_INLINE uint32_t ServoControl_GetPeriod1(void);
__STATIC_INLINE void ServoControl_EnablePeriodSwap(bool enable);
__STATIC_INLINE void ServoControl_TriggerStart(void);
__STATIC_INLINE void ServoControl_TriggerReload(void);
__STATIC_INLINE void ServoControl_TriggerKill(void);
__STATIC_INLINE void ServoControl_TriggerSwap(void);
__STATIC_INLINE uint32_t ServoControl_GetInterruptStatus(void);
__STATIC_INLINE void ServoControl_ClearInterrupt(uint32_t source);
__STATIC_INLINE void ServoControl_SetInterrupt(uint32_t source);
__STATIC_INLINE void ServoControl_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t ServoControl_GetInterruptMask(void);
__STATIC_INLINE uint32_t ServoControl_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define ServoControl_HW                 (ServoControl_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define ServoControl_CNT_HW             (ServoControl_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define ServoControl_CNT_NUM            (ServoControl_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define ServoControl_CNT_MASK           (1UL << ServoControl_CNT_NUM)
/** @} group_macros */

#define ServoControl_INPUT_MODE_MASK    (0x3U)
#define ServoControl_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: ServoControl_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t ServoControl_Init(cy_stc_tcpwm_pwm_config_t const *config)
{
    return(Cy_TCPWM_PWM_Init(ServoControl_HW, ServoControl_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: ServoControl_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_DeInit(void)                   
{
    Cy_TCPWM_PWM_DeInit(ServoControl_HW, ServoControl_CNT_NUM, &ServoControl_config);
}

/*******************************************************************************
* Function Name: ServoControl_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(ServoControl_HW, ServoControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: ServoControl_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(ServoControl_HW, ServoControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: ServoControl_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ServoControl_GetStatus(void)                
{
    return(Cy_TCPWM_PWM_GetStatus(ServoControl_HW, ServoControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: ServoControl_SetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_SetCompare0(uint32_t compare0)      
{
    Cy_TCPWM_PWM_SetCompare0(ServoControl_HW, ServoControl_CNT_NUM, compare0);
}


/*******************************************************************************
* Function Name: ServoControl_GetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ServoControl_GetCompare0(void)              
{
    return(Cy_TCPWM_PWM_GetCompare0(ServoControl_HW, ServoControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: ServoControl_SetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_SetCompare1(uint32_t compare1)      
{
    Cy_TCPWM_PWM_SetCompare1(ServoControl_HW, ServoControl_CNT_NUM, compare1);
}


/*******************************************************************************
* Function Name: ServoControl_GetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ServoControl_GetCompare1(void)              
{
    return(Cy_TCPWM_PWM_GetCompare1(ServoControl_HW, ServoControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: ServoControl_EnableCompareSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnableCompareSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_EnableCompareSwap(bool enable)  
{
    Cy_TCPWM_PWM_EnableCompareSwap(ServoControl_HW, ServoControl_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: ServoControl_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_SetCounter(uint32_t count)          
{
    Cy_TCPWM_PWM_SetCounter(ServoControl_HW, ServoControl_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: ServoControl_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ServoControl_GetCounter(void)               
{
    return(Cy_TCPWM_PWM_GetCounter(ServoControl_HW, ServoControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: ServoControl_SetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_SetPeriod0(uint32_t period0)          
{
    Cy_TCPWM_PWM_SetPeriod0(ServoControl_HW, ServoControl_CNT_NUM, period0);
}


/*******************************************************************************
* Function Name: ServoControl_GetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ServoControl_GetPeriod0(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod0(ServoControl_HW, ServoControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: ServoControl_SetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_SetPeriod1(uint32_t period1)
{
    Cy_TCPWM_PWM_SetPeriod1(ServoControl_HW, ServoControl_CNT_NUM, period1);
}


/*******************************************************************************
* Function Name: ServoControl_GetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ServoControl_GetPeriod1(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod1(ServoControl_HW, ServoControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: ServoControl_EnablePeriodSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnablePeriodSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_EnablePeriodSwap(bool enable)
{
    Cy_TCPWM_PWM_EnablePeriodSwap(ServoControl_HW, ServoControl_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: ServoControl_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(ServoControl_HW, ServoControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: ServoControl_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(ServoControl_HW, ServoControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: ServoControl_TriggerKill
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_TriggerKill(void)
{
    Cy_TCPWM_TriggerStopOrKill(ServoControl_HW, ServoControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: ServoControl_TriggerSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_TriggerSwap(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(ServoControl_HW, ServoControl_CNT_MASK);
}


/*******************************************************************************
* Function Name: ServoControl_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ServoControl_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(ServoControl_HW, ServoControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: ServoControl_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(ServoControl_HW, ServoControl_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: ServoControl_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(ServoControl_HW, ServoControl_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: ServoControl_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ServoControl_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(ServoControl_HW, ServoControl_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: ServoControl_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ServoControl_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(ServoControl_HW, ServoControl_CNT_NUM));
}


/*******************************************************************************
* Function Name: ServoControl_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ServoControl_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(ServoControl_HW, ServoControl_CNT_NUM));
}

#endif /* ServoControl_CY_TCPWM_PWM_PDL_H */


/* [] END OF FILE */
