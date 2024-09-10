#include "system_driver.h"



#define USART_BUFF_FULL DISABLE
#define USART_BUFF_EMPTY ENABLE

#define BAURD_9600_RATE 9600


#define RX_ONLY 0
#define TX_ONLY 1
#define RXandTX 2

#define Async 0
#define sync 1

#define TXSTATUS_BASE_ADDR 0x98
#define RCSTATUS_BASE_ADDR 0x18
#define SPBRG_BASE_ADDR 0x99
#define TXBUFFF_BASE_ADDR 0x19
#define RXBUFF_BASE_ADDR 0x1A

typedef struct {
    v uint8_t TX9D_BIT :1;
    v uint8_t TRMT_BIT :1;
    v uint8_t BRGH_BIT :1;
    uint8_t RESERVED_BIT :1;
    v uint8_t SYNC_BIT :1;
    v uint8_t TXEN_BIT :1;
    v uint8_t TX9_BIT :1;
    v uint8_t CSRC_BIT :1;
    }TXSTA_reg;

typedef struct {
    v uint8_t RX9D_BIT :1;
    v uint8_t OERR_BIT :1;
    v uint8_t FERR_BIT :1;
    v uint8_t ADDEN_BIT :1;
    v uint8_t CREN_BIT :1;
    v uint8_t SREN_BIT :1;
    v uint8_t RX9_BIT :1;
    v uint8_t SPEN_BIT : 1;
     
}RCSTA_reg;


#define TXSTATUS_REGISTER  ( (TXSTA_reg *)TXSTATUS_BASE_ADDR )
#define RXSTATUS_REGISTER  ( (RCSTA_reg *)RCSTATUS_BASE_ADDR )
#define USART_BAURD_RATE   ( (uint8_t *) SPBRG_BASE_ADDR  )
#define USART_TX_DATA_BUFF ( (uint8_t *) TXBUFFF_BASE_ADDR)
#define USART_RX_DATA_BUFF   ( (uint8_t *) RXBUFF_BASE_ADDR)

void USART_INIT(unsigned int,uint8_t,uint8_t,uint8_t); 
uint8_t baud_rate_cal (unsigned int );
void USART_DATA_TX(char *,size_t );
void USART_DATA_RX(char *,size_t );