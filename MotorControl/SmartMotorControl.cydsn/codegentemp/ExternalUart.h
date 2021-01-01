/***************************************************************************//**
* \file ExternalUart.h
* \version 2.0
*
*  This file provides constants and parameter values for the UART component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(ExternalUart_CY_SCB_UART_PDL_H)
#define ExternalUart_CY_SCB_UART_PDL_H

#include "cyfitter.h"
#include "scb/cy_scb_uart.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*   Initial Parameter Constants
****************************************/

#define ExternalUart_DIRECTION  (3U)
#define ExternalUart_ENABLE_RTS (0U)
#define ExternalUart_ENABLE_CTS (0U)

/* UART direction enum */
#define ExternalUart_RX    (0x1U)
#define ExternalUart_TX    (0x2U)

#define ExternalUart_ENABLE_RX  (0UL != (ExternalUart_DIRECTION & ExternalUart_RX))
#define ExternalUart_ENABLE_TX  (0UL != (ExternalUart_DIRECTION & ExternalUart_TX))


/***************************************
*        Function Prototypes
***************************************/
/**
* \addtogroup group_general
* @{
*/
/* Component specific functions. */
void ExternalUart_Start(void);

/* Basic functions */
__STATIC_INLINE cy_en_scb_uart_status_t ExternalUart_Init(cy_stc_scb_uart_config_t const *config);
__STATIC_INLINE void ExternalUart_DeInit(void);
__STATIC_INLINE void ExternalUart_Enable(void);
__STATIC_INLINE void ExternalUart_Disable(void);

/* Register callback. */
__STATIC_INLINE void ExternalUart_RegisterCallback(cy_cb_scb_uart_handle_events_t callback);

/* Configuration change. */
#if (ExternalUart_ENABLE_CTS)
__STATIC_INLINE void ExternalUart_EnableCts(void);
__STATIC_INLINE void ExternalUart_DisableCts(void);
#endif /* (ExternalUart_ENABLE_CTS) */

#if (ExternalUart_ENABLE_RTS)
__STATIC_INLINE void     ExternalUart_SetRtsFifoLevel(uint32_t level);
__STATIC_INLINE uint32_t ExternalUart_GetRtsFifoLevel(void);
#endif /* (ExternalUart_ENABLE_RTS) */

__STATIC_INLINE void ExternalUart_EnableSkipStart(void);
__STATIC_INLINE void ExternalUart_DisableSkipStart(void);

#if (ExternalUart_ENABLE_RX)
/* Low level: Receive direction. */
__STATIC_INLINE uint32_t ExternalUart_Get(void);
__STATIC_INLINE uint32_t ExternalUart_GetArray(void *buffer, uint32_t size);
__STATIC_INLINE void     ExternalUart_GetArrayBlocking(void *buffer, uint32_t size);
__STATIC_INLINE uint32_t ExternalUart_GetRxFifoStatus(void);
__STATIC_INLINE void     ExternalUart_ClearRxFifoStatus(uint32_t clearMask);
__STATIC_INLINE uint32_t ExternalUart_GetNumInRxFifo(void);
__STATIC_INLINE void     ExternalUart_ClearRxFifo(void);
#endif /* (ExternalUart_ENABLE_RX) */

#if (ExternalUart_ENABLE_TX)
/* Low level: Transmit direction. */
__STATIC_INLINE uint32_t ExternalUart_Put(uint32_t data);
__STATIC_INLINE uint32_t ExternalUart_PutArray(void *buffer, uint32_t size);
__STATIC_INLINE void     ExternalUart_PutArrayBlocking(void *buffer, uint32_t size);
__STATIC_INLINE void     ExternalUart_PutString(char_t const string[]);
__STATIC_INLINE void     ExternalUart_SendBreakBlocking(uint32_t breakWidth);
__STATIC_INLINE uint32_t ExternalUart_GetTxFifoStatus(void);
__STATIC_INLINE void     ExternalUart_ClearTxFifoStatus(uint32_t clearMask);
__STATIC_INLINE uint32_t ExternalUart_GetNumInTxFifo(void);
__STATIC_INLINE bool     ExternalUart_IsTxComplete(void);
__STATIC_INLINE void     ExternalUart_ClearTxFifo(void);
#endif /* (ExternalUart_ENABLE_TX) */

#if (ExternalUart_ENABLE_RX)
/* High level: Ring buffer functions. */
__STATIC_INLINE void     ExternalUart_StartRingBuffer(void *buffer, uint32_t size);
__STATIC_INLINE void     ExternalUart_StopRingBuffer(void);
__STATIC_INLINE void     ExternalUart_ClearRingBuffer(void);
__STATIC_INLINE uint32_t ExternalUart_GetNumInRingBuffer(void);

/* High level: Receive direction functions. */
__STATIC_INLINE cy_en_scb_uart_status_t ExternalUart_Receive(void *buffer, uint32_t size);
__STATIC_INLINE void     ExternalUart_AbortReceive(void);
__STATIC_INLINE uint32_t ExternalUart_GetReceiveStatus(void);
__STATIC_INLINE uint32_t ExternalUart_GetNumReceived(void);
#endif /* (ExternalUart_ENABLE_RX) */

#if (ExternalUart_ENABLE_TX)
/* High level: Transmit direction functions. */
__STATIC_INLINE cy_en_scb_uart_status_t ExternalUart_Transmit(void *buffer, uint32_t size);
__STATIC_INLINE void     ExternalUart_AbortTransmit(void);
__STATIC_INLINE uint32_t ExternalUart_GetTransmitStatus(void);
__STATIC_INLINE uint32_t ExternalUart_GetNumLeftToTransmit(void);
#endif /* (ExternalUart_ENABLE_TX) */

/* Interrupt handler */
__STATIC_INLINE void ExternalUart_Interrupt(void);
/** @} group_general */


/***************************************
*    Variables with External Linkage
***************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t ExternalUart_initVar;
extern cy_stc_scb_uart_config_t const ExternalUart_config;
extern cy_stc_scb_uart_context_t ExternalUart_context;
/** @} group_globals */


/***************************************
*         Preprocessor Macros
***************************************/
/**
* \addtogroup group_macros
* @{
*/
/** The pointer to the base address of the hardware */
#define ExternalUart_HW     ((CySCB_Type *) ExternalUart_SCB__HW)
/** @} group_macros */


/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: ExternalUart_Init
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t ExternalUart_Init(cy_stc_scb_uart_config_t const *config)
{
   return Cy_SCB_UART_Init(ExternalUart_HW, config, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_DeInit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_DeInit(void)
{
    Cy_SCB_UART_DeInit(ExternalUart_HW);
}


/*******************************************************************************
* Function Name: ExternalUart_Enable
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Enable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_Enable(void)
{
    Cy_SCB_UART_Enable(ExternalUart_HW);
}


/*******************************************************************************
* Function Name: ExternalUart_Disable
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Disable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_Disable(void)
{
    Cy_SCB_UART_Disable(ExternalUart_HW, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_RegisterCallback
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_RegisterCallback() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_RegisterCallback(cy_cb_scb_uart_handle_events_t callback)
{
    Cy_SCB_UART_RegisterCallback(ExternalUart_HW, callback, &ExternalUart_context);
}


#if (ExternalUart_ENABLE_CTS)
/*******************************************************************************
* Function Name: ExternalUart_EnableCts
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_EnableCts() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_EnableCts(void)
{
    Cy_SCB_UART_EnableCts(ExternalUart_HW);
}


/*******************************************************************************
* Function Name: Cy_SCB_UART_DisableCts
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DisableCts() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_DisableCts(void)
{
    Cy_SCB_UART_DisableCts(ExternalUart_HW);
}
#endif /* (ExternalUart_ENABLE_CTS) */


#if (ExternalUart_ENABLE_RTS)
/*******************************************************************************
* Function Name: ExternalUart_SetRtsFifoLevel
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_SetRtsFifoLevel() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_SetRtsFifoLevel(uint32_t level)
{
    Cy_SCB_UART_SetRtsFifoLevel(ExternalUart_HW, level);
}


/*******************************************************************************
* Function Name: ExternalUart_GetRtsFifoLevel
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetRtsFifoLevel() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetRtsFifoLevel(void)
{
    return Cy_SCB_UART_GetRtsFifoLevel(ExternalUart_HW);
}
#endif /* (ExternalUart_ENABLE_RTS) */


/*******************************************************************************
* Function Name: ExternalUart_EnableSkipStart
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_EnableSkipStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_EnableSkipStart(void)
{
    Cy_SCB_UART_EnableSkipStart(ExternalUart_HW);
}


/*******************************************************************************
* Function Name: ExternalUart_DisableSkipStart
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DisableSkipStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_DisableSkipStart(void)
{
    Cy_SCB_UART_DisableSkipStart(ExternalUart_HW);
}


#if (ExternalUart_ENABLE_RX)
/*******************************************************************************
* Function Name: ExternalUart_Get
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Get() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_Get(void)
{
    return Cy_SCB_UART_Get(ExternalUart_HW);
}


/*******************************************************************************
* Function Name: ExternalUart_GetArray
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetArray() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetArray(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_GetArray(ExternalUart_HW, buffer, size);
}


/*******************************************************************************
* Function Name: ExternalUart_GetArrayBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetArrayBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_GetArrayBlocking(void *buffer, uint32_t size)
{
    Cy_SCB_UART_GetArrayBlocking(ExternalUart_HW, buffer, size);
}


/*******************************************************************************
* Function Name: ExternalUart_GetRxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetRxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetRxFifoStatus(void)
{
    return Cy_SCB_UART_GetRxFifoStatus(ExternalUart_HW);
}


/*******************************************************************************
* Function Name: ExternalUart_ClearRxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_ClearRxFifoStatus(uint32_t clearMask)
{
    Cy_SCB_UART_ClearRxFifoStatus(ExternalUart_HW, clearMask);
}


/*******************************************************************************
* Function Name: ExternalUart_GetNumInRxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInRxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetNumInRxFifo(void)
{
    return Cy_SCB_UART_GetNumInRxFifo(ExternalUart_HW);
}


/*******************************************************************************
* Function Name: ExternalUart_ClearRxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_ClearRxFifo(void)
{
    Cy_SCB_UART_ClearRxFifo(ExternalUart_HW);
}
#endif /* (ExternalUart_ENABLE_RX) */


#if (ExternalUart_ENABLE_TX)
/*******************************************************************************
* Function Name: ExternalUart_Put
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Put() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_Put(uint32_t data)
{
    return Cy_SCB_UART_Put(ExternalUart_HW,data);
}


/*******************************************************************************
* Function Name: ExternalUart_PutArray
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutArray() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_PutArray(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_PutArray(ExternalUart_HW, buffer, size);
}


/*******************************************************************************
* Function Name: ExternalUart_PutArrayBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutArrayBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_PutArrayBlocking(void *buffer, uint32_t size)
{
    Cy_SCB_UART_PutArrayBlocking(ExternalUart_HW, buffer, size);
}


/*******************************************************************************
* Function Name: ExternalUart_PutString
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutString() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_PutString(char_t const string[])
{
    Cy_SCB_UART_PutString(ExternalUart_HW, string);
}


/*******************************************************************************
* Function Name: ExternalUart_SendBreakBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_SendBreakBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_SendBreakBlocking(uint32_t breakWidth)
{
    Cy_SCB_UART_SendBreakBlocking(ExternalUart_HW, breakWidth);
}


/*******************************************************************************
* Function Name: ExternalUart_GetTxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetTxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetTxFifoStatus(void)
{
    return Cy_SCB_UART_GetTxFifoStatus(ExternalUart_HW);
}


/*******************************************************************************
* Function Name: ExternalUart_ClearTxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearTxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_ClearTxFifoStatus(uint32_t clearMask)
{
    Cy_SCB_UART_ClearTxFifoStatus(ExternalUart_HW, clearMask);
}


/*******************************************************************************
* Function Name: ExternalUart_GetNumInTxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInTxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetNumInTxFifo(void)
{
    return Cy_SCB_UART_GetNumInTxFifo(ExternalUart_HW);
}


/*******************************************************************************
* Function Name: ExternalUart_IsTxComplete
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_IsTxComplete() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE bool ExternalUart_IsTxComplete(void)
{
    return Cy_SCB_UART_IsTxComplete(ExternalUart_HW);
}


/*******************************************************************************
* Function Name: ExternalUart_ClearTxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearTxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_ClearTxFifo(void)
{
    Cy_SCB_UART_ClearTxFifo(ExternalUart_HW);
}
#endif /* (ExternalUart_ENABLE_TX) */


#if (ExternalUart_ENABLE_RX)
/*******************************************************************************
* Function Name: ExternalUart_StartRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_StartRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_StartRingBuffer(void *buffer, uint32_t size)
{
    Cy_SCB_UART_StartRingBuffer(ExternalUart_HW, buffer, size, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_StopRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_StopRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_StopRingBuffer(void)
{
    Cy_SCB_UART_StopRingBuffer(ExternalUart_HW, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_ClearRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_ClearRingBuffer(void)
{
    Cy_SCB_UART_ClearRingBuffer(ExternalUart_HW, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_GetNumInRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetNumInRingBuffer(void)
{
    return Cy_SCB_UART_GetNumInRingBuffer(ExternalUart_HW, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_Receive
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Receive() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t ExternalUart_Receive(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_Receive(ExternalUart_HW, buffer, size, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_GetReceiveStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetReceiveStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetReceiveStatus(void)
{
    return Cy_SCB_UART_GetReceiveStatus(ExternalUart_HW, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_AbortReceive
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_AbortReceive() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_AbortReceive(void)
{
    Cy_SCB_UART_AbortReceive(ExternalUart_HW, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_GetNumReceived
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumReceived() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetNumReceived(void)
{
    return Cy_SCB_UART_GetNumReceived(ExternalUart_HW, &ExternalUart_context);
}
#endif /* (ExternalUart_ENABLE_RX) */


#if (ExternalUart_ENABLE_TX)
/*******************************************************************************
* Function Name: ExternalUart_Transmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Transmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t ExternalUart_Transmit(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_Transmit(ExternalUart_HW, buffer, size, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_GetTransmitStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetTransmitStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetTransmitStatus(void)
{
    return Cy_SCB_UART_GetTransmitStatus(ExternalUart_HW, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_AbortTransmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_AbortTransmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_AbortTransmit(void)
{
    Cy_SCB_UART_AbortTransmit(ExternalUart_HW, &ExternalUart_context);
}


/*******************************************************************************
* Function Name: ExternalUart_GetNumLeftToTransmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumLeftToTransmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ExternalUart_GetNumLeftToTransmit(void)
{
    return Cy_SCB_UART_GetNumLeftToTransmit(ExternalUart_HW, &ExternalUart_context);
}
#endif /* (ExternalUart_ENABLE_TX) */


/*******************************************************************************
* Function Name: ExternalUart_Interrupt
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Interrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ExternalUart_Interrupt(void)
{
    Cy_SCB_UART_Interrupt(ExternalUart_HW, &ExternalUart_context);
}

#if defined(__cplusplus)
}
#endif

#endif /* ExternalUart_CY_SCB_UART_PDL_H */


/* [] END OF FILE */
