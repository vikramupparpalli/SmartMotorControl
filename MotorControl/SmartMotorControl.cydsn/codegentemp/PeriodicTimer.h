/*******************************************************************************
* File Name: PeriodicTimer.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the PeriodicTimer
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(PeriodicTimer_CY_TCPWM_COUNTER_PDL_H)
#define PeriodicTimer_CY_TCPWM_COUNTER_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_counter.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  PeriodicTimer_initVar;
extern cy_stc_tcpwm_counter_config_t const PeriodicTimer_config;
/** @} group_globals */


/***************************************
*  Conditional Compilation Parameters
***************************************/

#define PeriodicTimer_INIT_COMPARE_OR_CAPTURE    (2UL)


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void PeriodicTimer_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t PeriodicTimer_Init(cy_stc_tcpwm_counter_config_t const *config);
__STATIC_INLINE void PeriodicTimer_DeInit(void);
__STATIC_INLINE void PeriodicTimer_Enable(void);
__STATIC_INLINE void PeriodicTimer_Disable(void);
__STATIC_INLINE uint32_t PeriodicTimer_GetStatus(void);

#if(CY_TCPWM_COUNTER_MODE_CAPTURE == PeriodicTimer_INIT_COMPARE_OR_CAPTURE)
    __STATIC_INLINE uint32_t PeriodicTimer_GetCapture(void);
    __STATIC_INLINE uint32_t PeriodicTimer_GetCaptureBuf(void);
#else
    __STATIC_INLINE void PeriodicTimer_SetCompare0(uint32_t compare0);
    __STATIC_INLINE uint32_t PeriodicTimer_GetCompare0(void);
    __STATIC_INLINE void PeriodicTimer_SetCompare1(uint32_t compare1);
    __STATIC_INLINE uint32_t PeriodicTimer_GetCompare1(void);
    __STATIC_INLINE void PeriodicTimer_EnableCompareSwap(bool enable);
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == PeriodicTimer_INIT_COMPARE_OR_CAPTURE) */

__STATIC_INLINE void PeriodicTimer_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t PeriodicTimer_GetCounter(void);
__STATIC_INLINE void PeriodicTimer_SetPeriod(uint32_t period);
__STATIC_INLINE uint32_t PeriodicTimer_GetPeriod(void);
__STATIC_INLINE void PeriodicTimer_TriggerStart(void);
__STATIC_INLINE void PeriodicTimer_TriggerReload(void);
__STATIC_INLINE void PeriodicTimer_TriggerStop(void);
__STATIC_INLINE void PeriodicTimer_TriggerCapture(void);
__STATIC_INLINE uint32_t PeriodicTimer_GetInterruptStatus(void);
__STATIC_INLINE void PeriodicTimer_ClearInterrupt(uint32_t source);
__STATIC_INLINE void PeriodicTimer_SetInterrupt(uint32_t source);
__STATIC_INLINE void PeriodicTimer_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t PeriodicTimer_GetInterruptMask(void);
__STATIC_INLINE uint32_t PeriodicTimer_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define PeriodicTimer_HW                 (PeriodicTimer_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define PeriodicTimer_CNT_HW             (PeriodicTimer_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define PeriodicTimer_CNT_NUM            (PeriodicTimer_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define PeriodicTimer_CNT_MASK           (1UL << PeriodicTimer_CNT_NUM)
/** @} group_macros */

#define PeriodicTimer_INPUT_MODE_MASK    (0x3U)
#define PeriodicTimer_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: PeriodicTimer_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t PeriodicTimer_Init(cy_stc_tcpwm_counter_config_t const *config)
{
    return(Cy_TCPWM_Counter_Init(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: PeriodicTimer_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_DeInit(void)                   
{
    Cy_TCPWM_Counter_DeInit(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, &PeriodicTimer_config);
}

/*******************************************************************************
* Function Name: PeriodicTimer_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(PeriodicTimer_HW, PeriodicTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: PeriodicTimer_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(PeriodicTimer_HW, PeriodicTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: PeriodicTimer_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t PeriodicTimer_GetStatus(void)                
{
    return(Cy_TCPWM_Counter_GetStatus(PeriodicTimer_HW, PeriodicTimer_CNT_NUM));
}


#if(CY_TCPWM_COUNTER_MODE_CAPTURE == PeriodicTimer_INIT_COMPARE_OR_CAPTURE)
    /*******************************************************************************
    * Function Name: PeriodicTimer_GetCapture
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCapture() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t PeriodicTimer_GetCapture(void)               
    {
        return(Cy_TCPWM_Counter_GetCapture(PeriodicTimer_HW, PeriodicTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: PeriodicTimer_GetCaptureBuf
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCaptureBuf() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t PeriodicTimer_GetCaptureBuf(void)            
    {
        return(Cy_TCPWM_Counter_GetCaptureBuf(PeriodicTimer_HW, PeriodicTimer_CNT_NUM));
    }
#else
    /*******************************************************************************
    * Function Name: PeriodicTimer_SetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void PeriodicTimer_SetCompare0(uint32_t compare0)      
    {
        Cy_TCPWM_Counter_SetCompare0(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, compare0);
    }


    /*******************************************************************************
    * Function Name: PeriodicTimer_GetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t PeriodicTimer_GetCompare0(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare0(PeriodicTimer_HW, PeriodicTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: PeriodicTimer_SetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void PeriodicTimer_SetCompare1(uint32_t compare1)      
    {
        Cy_TCPWM_Counter_SetCompare1(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, compare1);
    }


    /*******************************************************************************
    * Function Name: PeriodicTimer_GetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t PeriodicTimer_GetCompare1(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare1(PeriodicTimer_HW, PeriodicTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: PeriodicTimer_EnableCompareSwap
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_EnableCompareSwap() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void PeriodicTimer_EnableCompareSwap(bool enable)  
    {
        Cy_TCPWM_Counter_EnableCompareSwap(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, enable);
    }
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == PeriodicTimer_INIT_COMPARE_OR_CAPTURE) */


/*******************************************************************************
* Function Name: PeriodicTimer_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_SetCounter(uint32_t count)          
{
    Cy_TCPWM_Counter_SetCounter(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: PeriodicTimer_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t PeriodicTimer_GetCounter(void)               
{
    return(Cy_TCPWM_Counter_GetCounter(PeriodicTimer_HW, PeriodicTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: PeriodicTimer_SetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_SetPeriod(uint32_t period)          
{
    Cy_TCPWM_Counter_SetPeriod(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, period);
}


/*******************************************************************************
* Function Name: PeriodicTimer_GetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t PeriodicTimer_GetPeriod(void)                
{
    return(Cy_TCPWM_Counter_GetPeriod(PeriodicTimer_HW, PeriodicTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: PeriodicTimer_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(PeriodicTimer_HW, PeriodicTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: PeriodicTimer_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(PeriodicTimer_HW, PeriodicTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: PeriodicTimer_TriggerStop
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_TriggerStop(void)
{
    Cy_TCPWM_TriggerStopOrKill(PeriodicTimer_HW, PeriodicTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: PeriodicTimer_TriggerCapture
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_TriggerCapture(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(PeriodicTimer_HW, PeriodicTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: PeriodicTimer_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t PeriodicTimer_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(PeriodicTimer_HW, PeriodicTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: PeriodicTimer_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: PeriodicTimer_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: PeriodicTimer_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void PeriodicTimer_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: PeriodicTimer_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t PeriodicTimer_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(PeriodicTimer_HW, PeriodicTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: PeriodicTimer_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t PeriodicTimer_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(PeriodicTimer_HW, PeriodicTimer_CNT_NUM));
}

#endif /* PeriodicTimer_CY_TCPWM_COUNTER_PDL_H */


/* [] END OF FILE */
