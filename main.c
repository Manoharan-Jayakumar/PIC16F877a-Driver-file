#include "system_driver.h"
#include "USART_DRIVER_HEADER.h"
#include "GPIO_DRIVER_HEADER.h"


void main(void) {

    GPIO_MODE(GPIOC,INPUT,8); //(port , mode ,pinnumber)
    GPIO_MODE(GPIOC,OUTPUT,7);  
    GPIO_MODE(GPIOC,OUTPUT,1);
    GPIO_MODE(GPIOC,INPUT,2);
    
    
    GPIO_WRITE(GPIOC,1,1); 
    __delay_ms(1000);
    GPIO_WRITE(GPIOC,1,0);  //uint8_t port,uint8_t pinnumber,uint8_t data
    
  
    

    USART_INIT(BAURD_9600_RATE,8,TX_ONLY,Async); 
    // baud_rate,bits,rxortx,clk_mode
    
    
    while (1) {
        
        if(  (  GPIO_READ(GPIOC,2) ) == 0 ) { //uint8_t port,uint8_t pin
         
          // Return for the pull_down 
    
        char *data = "MANOHRAN DONE THE DRIVER DEVELOPMENT \n";
    
        USART_DATA_TX (data,strlen(data));
        
        }
    
    
    }
}
