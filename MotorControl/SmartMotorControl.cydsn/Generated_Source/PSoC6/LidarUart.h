/***************************************************************************//**
* \file LidarUart.h
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

#if !defined(LidarUart_CY_SCB_UART_PDL_H)
#define LidarUart_CY_SCB_UART_PDL_H

#include "cyfitter.h"
#include "scb/cy_scb_uart.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*   Initial Parameter Constants
****************************************/

#define LidarUart_DIRECTION  (3U)
#define LidarUart_ENABLE_RTS (0U)
#define LidarUart_ENABLE_CTS (0U)

/* UART direction enum */
#define LidarUart_RX    (0x1U)
#define LidarUart_TX    (0x2U)

#define LidarUart_ENABLE_RX  (0UL != (LidarUart_DIRECTION & LidarUart_RX))
#define LidarUart_ENABLE_TX  (0UL != (LidarUart_DIRECTION & LidarUart_TX))


/***************************************
*        Function Prototypes
***************************************/
/**
* \addtogroup group_general
* @{
*/
/* Component specific functions. */
void LidarUart_Start(void);

/* Basic functions */
__STATIC_INLINE cy_en_scb_uart_status_t LidarUart_Init(cy_stc_scb_uart_config_t const *config);
__STATIC_INLINE void LidarUart_DeInit(void);
__STATIC_INLINE void LidarUart_Enable(void);
__STATIC_INLINE void LidarUart_Disable(void);

/* Register callback. */
__STATIC_INLINE void LidarUart_RegisterCallback(cy_cb_scb_uart_handle_events_t callback);

/* Configuration change. */
#if (LidarUart_ENABLE_CTS)
__STATIC_INLINE void LidarUart_EnableCts(void);
__STATIC_INLINE void LidarUart_DisableCts(void);
#endif /* (LidarUart_ENABLE_CTS) */

#if (LidarUart_ENABLE_RTS)
__STATIC_INLINE void     LidarUart_SetRtsFifoLevel(uint32_t level);
__STATIC_INLINE uint32_t LidarUart_GetRtsFifoLevel(void);
#endif /* (LidarUart_ENABLE_RTS) */

__STATIC_INLINE void LidarUart_EnableSkipStart(void);
__STATIC_INLINE void LidarUart_DisableSkipStart(void);

#if (LidarUart_ENABLE_RX)
/* Low level: Receive direction. */
__STATIC_INLINE uint32_t LidarUart_Get(void);
__STATIC_INLINE uint32_t LidarUart_GetArray(void *buffer, uint32_t size);
__STATIC_INLINE void     LidarUart_GetArrayBlocking(void *buffer, uint32_t size);
__STATIC_INLINE uint32_t LidarUart_GetRxFifoStatus(void);
__STATIC_INLINE void     LidarUart_ClearRxFifoStatus(uint32_t clearMask);
__STATIC_INLINE uint32_t LidarUart_GetNumInRxFifo(void);
__STATIC_INLINE void     LidarUart_ClearRxFifo(void);
#endif /* (LidarUart_ENABLE_RX) */

#if (LidarUart_ENABLE_TX)
/* Low level: Transmit direction. */
__STATIC_INLINE uint32_t LidarUart_Put(uint32_t data);
__STATIC_INLINE uint32_t LidarUart_PutArray(void *buffer, uint32_t size);
__STATIC_INLINE void     LidarUart_PutArrayBlocking(void *buffer, uint32_t size);
__STATIC_INLINE void     LidarUart_PutString(char_t const string[]);
__STATIC_INLINE void     LidarUart_SendBreakBlocking(uint32_t breakWidth);
__STATIC_INLINE uint32_t LidarUart_GetTxFifoStatus(void);
__STATIC_INLINE void     LidarUart_ClearTxFifoStatus(uint32_t clearMask);
__STATIC_INLINE uint32_t LidarUart_GetNumInTxFifo(void);
__STATIC_INLINE bool     LidarUart_IsTxComplete(void);
__STATIC_INLINE void     LidarUart_ClearTxFifo(void);
#endif /* (LidarUart_ENABLE_TX) */

#if (LidarUart_ENABLE_RX)
/* High level: Ring buffer functions. */
__STATIC_INLINE void     LidarUart_StartRingBuffer(void *buffer, uint32_t size);
__STATIC_INLINE void     LidarUart_StopRingBuffer(void);
__STATIC_INLINE void     LidarUart_ClearRingBuffer(void);
__STATIC_INLINE uint32_t LidarUart_GetNumInRingBuffer(void);

/* High level: Receive direction functions. */
__STATIC_INLINE cy_en_scb_uart_status_t LidarUart_Receive(void *buffer, uint32_t size);
__STATIC_INLINE void     LidarUart_AbortReceive(void);
__STATIC_INLINE uint32_t LidarUart_GetReceiveStatus(void);
__STATIC_INLINE uint32_t LidarUart_GetNumReceived(void);
#endif /* (LidarUart_ENABLE_RX) */

#if (LidarUart_ENABLE_TX)
/* High level: Transmit direction functions. */
__STATIC_INLINE cy_en_scb_uart_status_t LidarUart_Transmit(void *buffer, uint32_t size);
__STATIC_INLINE void     LidarUart_AbortTransmit(void);
__STATIC_INLINE uint32_t LidarUart_GetTransmitStatus(void);
__STATIC_INLINE uint32_t LidarUart_GetNumLeftToTransmit(void);
#endif /* (LidarUart_ENABLE_TX) */

/* Interrupt handler */
__STATIC_INLINE void LidarUart_Interrupt(void);
/** @} group_general */


/***************************************
*    Variables with External Linkage
***************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t LidarUart_initVar;
extern cy_stc_scb_uart_config_t const LidarUart_config;
extern cy_stc_scb_uart_context_t LidarUart_context;
/** @} group_globals */


/***************************************
*         Preprocessor Macros
***************************************/
/**
* \addtogroup group_macros
* @{
*/
/** The pointer to the base address of the hardware */
#define LidarUart_HW     ((CySCB_Type *) LidarUart_SCB__HW)
/** @} group_macros */


/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: LidarUart_Init
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t LidarUart_Init(cy_stc_scb_uart_config_t const *config)
{
   return Cy_SCB_UART_Init(LidarUart_HW, config, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_DeInit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_DeInit(void)
{
    Cy_SCB_UART_DeInit(LidarUart_HW);
}


/*******************************************************************************
* Function Name: LidarUart_Enable
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Enable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_Enable(void)
{
    Cy_SCB_UART_Enable(LidarUart_HW);
}


/*******************************************************************************
* Function Name: LidarUart_Disable
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Disable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_Disable(void)
{
    Cy_SCB_UART_Disable(LidarUart_HW, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_RegisterCallback
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_RegisterCallback() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_RegisterCallback(cy_cb_scb_uart_handle_events_t callback)
{
    Cy_SCB_UART_RegisterCallback(LidarUart_HW, callback, &LidarUart_context);
}


#if (LidarUart_ENABLE_CTS)
/*******************************************************************************
* Function Name: LidarUart_EnableCts
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_EnableCts() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_EnableCts(void)
{
    Cy_SCB_UART_EnableCts(LidarUart_HW);
}


/*******************************************************************************
* Function Name: Cy_SCB_UART_DisableCts
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DisableCts() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_DisableCts(void)
{
    Cy_SCB_UART_DisableCts(LidarUart_HW);
}
#endif /* (LidarUart_ENABLE_CTS) */


#if (LidarUart_ENABLE_RTS)
/*******************************************************************************
* Function Name: LidarUart_SetRtsFifoLevel
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_SetRtsFifoLevel() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_SetRtsFifoLevel(uint32_t level)
{
    Cy_SCB_UART_SetRtsFifoLevel(LidarUart_HW, level);
}


/*******************************************************************************
* Function Name: LidarUart_GetRtsFifoLevel
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetRtsFifoLevel() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetRtsFifoLevel(void)
{
    return Cy_SCB_UART_GetRtsFifoLevel(LidarUart_HW);
}
#endif /* (LidarUart_ENABLE_RTS) */


/*******************************************************************************
* Function Name: LidarUart_EnableSkipStart
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_EnableSkipStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_EnableSkipStart(void)
{
    Cy_SCB_UART_EnableSkipStart(LidarUart_HW);
}


/*******************************************************************************
* Function Name: LidarUart_DisableSkipStart
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DisableSkipStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_DisableSkipStart(void)
{
    Cy_SCB_UART_DisableSkipStart(LidarUart_HW);
}


#if (LidarUart_ENABLE_RX)
/*******************************************************************************
* Function Name: LidarUart_Get
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Get() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_Get(void)
{
    return Cy_SCB_UART_Get(LidarUart_HW);
}


/*******************************************************************************
* Function Name: LidarUart_GetArray
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetArray() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetArray(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_GetArray(LidarUart_HW, buffer, size);
}


/*******************************************************************************
* Function Name: LidarUart_GetArrayBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetArrayBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_GetArrayBlocking(void *buffer, uint32_t size)
{
    Cy_SCB_UART_GetArrayBlocking(LidarUart_HW, buffer, size);
}


/*******************************************************************************
* Function Name: LidarUart_GetRxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetRxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetRxFifoStatus(void)
{
    return Cy_SCB_UART_GetRxFifoStatus(LidarUart_HW);
}


/*******************************************************************************
* Function Name: LidarUart_ClearRxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_ClearRxFifoStatus(uint32_t clearMask)
{
    Cy_SCB_UART_ClearRxFifoStatus(LidarUart_HW, clearMask);
}


/*******************************************************************************
* Function Name: LidarUart_GetNumInRxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInRxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetNumInRxFifo(void)
{
    return Cy_SCB_UART_GetNumInRxFifo(LidarUart_HW);
}


/*******************************************************************************
* Function Name: LidarUart_ClearRxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_ClearRxFifo(void)
{
    Cy_SCB_UART_ClearRxFifo(LidarUart_HW);
}
#endif /* (LidarUart_ENABLE_RX) */


#if (LidarUart_ENABLE_TX)
/*******************************************************************************
* Function Name: LidarUart_Put
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Put() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_Put(uint32_t data)
{
    return Cy_SCB_UART_Put(LidarUart_HW,data);
}


/*******************************************************************************
* Function Name: LidarUart_PutArray
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutArray() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_PutArray(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_PutArray(LidarUart_HW, buffer, size);
}


/*******************************************************************************
* Function Name: LidarUart_PutArrayBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutArrayBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_PutArrayBlocking(void *buffer, uint32_t size)
{
    Cy_SCB_UART_PutArrayBlocking(LidarUart_HW, buffer, size);
}


/*******************************************************************************
* Function Name: LidarUart_PutString
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutString() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_PutString(char_t const string[])
{
    Cy_SCB_UART_PutString(LidarUart_HW, string);
}


/*******************************************************************************
* Function Name: LidarUart_SendBreakBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_SendBreakBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_SendBreakBlocking(uint32_t breakWidth)
{
    Cy_SCB_UART_SendBreakBlocking(LidarUart_HW, breakWidth);
}


/*******************************************************************************
* Function Name: LidarUart_GetTxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetTxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetTxFifoStatus(void)
{
    return Cy_SCB_UART_GetTxFifoStatus(LidarUart_HW);
}


/*******************************************************************************
* Function Name: LidarUart_ClearTxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearTxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_ClearTxFifoStatus(uint32_t clearMask)
{
    Cy_SCB_UART_ClearTxFifoStatus(LidarUart_HW, clearMask);
}


/*******************************************************************************
* Function Name: LidarUart_GetNumInTxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInTxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetNumInTxFifo(void)
{
    return Cy_SCB_UART_GetNumInTxFifo(LidarUart_HW);
}


/*******************************************************************************
* Function Name: LidarUart_IsTxComplete
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_IsTxComplete() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE bool LidarUart_IsTxComplete(void)
{
    return Cy_SCB_UART_IsTxComplete(LidarUart_HW);
}


/*******************************************************************************
* Function Name: LidarUart_ClearTxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearTxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_ClearTxFifo(void)
{
    Cy_SCB_UART_ClearTxFifo(LidarUart_HW);
}
#endif /* (LidarUart_ENABLE_TX) */


#if (LidarUart_ENABLE_RX)
/*******************************************************************************
* Function Name: LidarUart_StartRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_StartRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_StartRingBuffer(void *buffer, uint32_t size)
{
    Cy_SCB_UART_StartRingBuffer(LidarUart_HW, buffer, size, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_StopRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_StopRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_StopRingBuffer(void)
{
    Cy_SCB_UART_StopRingBuffer(LidarUart_HW, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_ClearRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_ClearRingBuffer(void)
{
    Cy_SCB_UART_ClearRingBuffer(LidarUart_HW, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_GetNumInRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetNumInRingBuffer(void)
{
    return Cy_SCB_UART_GetNumInRingBuffer(LidarUart_HW, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_Receive
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Receive() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t LidarUart_Receive(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_Receive(LidarUart_HW, buffer, size, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_GetReceiveStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetReceiveStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetReceiveStatus(void)
{
    return Cy_SCB_UART_GetReceiveStatus(LidarUart_HW, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_AbortReceive
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_AbortReceive() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_AbortReceive(void)
{
    Cy_SCB_UART_AbortReceive(LidarUart_HW, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_GetNumReceived
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumReceived() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetNumReceived(void)
{
    return Cy_SCB_UART_GetNumReceived(LidarUart_HW, &LidarUart_context);
}
#endif /* (LidarUart_ENABLE_RX) */


#if (LidarUart_ENABLE_TX)
/*******************************************************************************
* Function Name: LidarUart_Transmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Transmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t LidarUart_Transmit(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_Transmit(LidarUart_HW, buffer, size, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_GetTransmitStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetTransmitStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetTransmitStatus(void)
{
    return Cy_SCB_UART_GetTransmitStatus(LidarUart_HW, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_AbortTransmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_AbortTransmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_AbortTransmit(void)
{
    Cy_SCB_UART_AbortTransmit(LidarUart_HW, &LidarUart_context);
}


/*******************************************************************************
* Function Name: LidarUart_GetNumLeftToTransmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumLeftToTransmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LidarUart_GetNumLeftToTransmit(void)
{
    return Cy_SCB_UART_GetNumLeftToTransmit(LidarUart_HW, &LidarUart_context);
}
#endif /* (LidarUart_ENABLE_TX) */


/*******************************************************************************
* Function Name: LidarUart_Interrupt
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Interrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LidarUart_Interrupt(void)
{
    Cy_SCB_UART_Interrupt(LidarUart_HW, &LidarUart_context);
}

#if defined(__cplusplus)
}
#endif

#endif /* LidarUart_CY_SCB_UART_PDL_H */


/* [] END OF FILE */
