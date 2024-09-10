/*
 * File:   USART_DRIVER.c
 * Author: jayka
 *
 * Created on 7 September, 2024, 10:40 PM
 */


#include "USART_DRIVER_HEADER.h"

void USART_INIT(unsigned int baud_rate , uint8_t bits ,uint8_t rxortx, uint8_t clk_mode){
    RXSTATUS_REGISTER->SPEN_BIT  = ENABLE ;
     
    switch (rxortx){
        
        case RX_ONLY:
            RXSTATUS_REGISTER->RX9_BIT      = DISABLE;
            RXSTATUS_REGISTER->CREN_BIT     = ENABLE; 
            TXSTATUS_REGISTER->SYNC_BIT     = DISABLE;
            TXSTATUS_REGISTER->BRGH_BIT     = DISABLE;
            RXSTATUS_REGISTER->ADDEN_BIT    = DISABLE;
            *USART_BAURD_RATE = baud_rate_cal(baud_rate); 
        break;
        
        case TX_ONLY:
            if (bits == 8) {
                if (clk_mode == Async) {
                    
            TXSTATUS_REGISTER->TXEN_BIT     = ENABLE;
            TXSTATUS_REGISTER->TX9_BIT      = DISABLE; 
            TXSTATUS_REGISTER->SYNC_BIT     = DISABLE;
            TXSTATUS_REGISTER->BRGH_BIT     = DISABLE;
            *USART_BAURD_RATE = baud_rate_cal(baud_rate);;

                }
            }
        break;
        
        case RXandTX:
            RXSTATUS_REGISTER->RX9_BIT      = DISABLE;
            TXSTATUS_REGISTER->TX9_BIT      = DISABLE;
            RXSTATUS_REGISTER->CREN_BIT     = ENABLE; 
            TXSTATUS_REGISTER->SYNC_BIT     = DISABLE;
            TXSTATUS_REGISTER->BRGH_BIT     = DISABLE;
            RXSTATUS_REGISTER->ADDEN_BIT    = DISABLE;
            TXSTATUS_REGISTER->TXEN_BIT     = ENABLE; 
           *USART_BAURD_RATE = baud_rate_cal(baud_rate);
            break;
    }
}


void USART_DATA_TX(char *data,size_t len ) {
    
    uint16_t i = 0;
    while ( i < len ) {
        
//        while ( TXSTATUS_REGISTER->TRMT_BIT == 0){
//        }
            *USART_TX_DATA_BUFF  =  data[i];
            __delay_ms(5);
            i++;
    }
    
}
void USART_DATA_RX(char *data,size_t len) {
    
}
         
uint8_t baud_rate_cal (unsigned int baud_rate ) {
   unsigned int spbrg_val = (_XTAL_FREQ / (16 * baud_rate)) - 1; // For high-speed mode
   return (uint8_t)spbrg_val;
}
