/*******************************************************************************
* File Name: app_LED.c
*
* Description:
*  Common BLE application code for client devices.
*
*******************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "app_LED.h"


/*******************************************************************************
* Function Name: HandleLeds
********************************************************************************
*
* Summary:
*  This function handles the toggling of Scan and Connection LED. 
*
* Parameters:
*  None.
*
* Return:
*   None.
*
*******************************************************************************/
void HandleLeds(void)
{
    static uint8        ledState        = LED_OFF;  
    static uint32       connLedTimer    = CONN_LED_TIMEOUT;   
    
    switch (cyBle_state)
    {
        case CYBLE_STATE_ADVERTISING:
            
            
            break;
            
        case CYBLE_STATE_CONNECTED: 
            
            #if DONGLE
            Adv_LED_Write(LED_OFF);
            #endif 
            
            if(--connLedTimer == 0u) 
            {
                connLedTimer = CONN_LED_TIMEOUT;
                ledState    ^= LED_OFF;
                
            }
            
        default:
            break;
    }
}








/* [] END OF FILE */
