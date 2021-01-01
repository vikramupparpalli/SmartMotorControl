/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

void TimerInterruptHandler(void)
{
    /* Clear the terminal count interrupt */
    Cy_TCPWM_ClearInterrupt(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, CY_TCPWM_INT_ON_TC);
    
    Cy_GPIO_Inv(DirectionInput1_PORT, DirectionInput1_NUM);
}

int main(void)
{
    Cy_SysInt_Init(&OneMsInterrupt_cfg, TimerInterruptHandler);
    NVIC_ClearPendingIRQ(OneMsInterrupt_cfg.intrSrc);/* Clears the interrupt */
    NVIC_EnableIRQ(OneMsInterrupt_cfg.intrSrc); /* Enable the core interrupt */
    __enable_irq(); /* Enable global interrupts. */
    
    Cy_TCPWM_Counter_Init(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, &PeriodicTimer_config);
    Cy_TCPWM_Enable_Multiple(PeriodicTimer_HW, PeriodicTimer_CNT_MASK);
    Cy_TCPWM_Counter_SetPeriod(PeriodicTimer_HW, PeriodicTimer_CNT_NUM, 0);
    Cy_TCPWM_TriggerReloadOrIndex(PeriodicTimer_HW, PeriodicTimer_CNT_MASK); 
    
    for(;;)
    {

    }
}

/* [] END OF FILE */
