#include "GPIO_DRIVER_HEADER.h"


void GPIO_MODE(uint8_t port ,uint8_t mode ,uint8_t pinnumber) {
    
    switch( port ) {
        
        case GPIOA:
                pinconfig(TRISA_GPIO,mode,pinnumber);
            break;
            
        case GPIOB:
                pinconfig(TRISB_GPIO,mode,pinnumber);
            break;
            
        case GPIOC:
                pinconfig(TRISC_GPIO,mode,pinnumber);
            break;

        case GPIOD:
                pinconfig(TRISD_GPIO,mode,pinnumber);
            break;

        case GPIOE:
                pinconfig(TRISE_GPIO,mode,pinnumber);
            break;
    }
    
}

void GPIO_WRITE (uint8_t port,uint8_t pinnumber,uint8_t data){
    
    switch(port) {
        
        case GPIOA:
            pinwrite(PORTA_GPIO,pinnumber,data);
            break;
            
        case GPIOB:
            pinwrite(PORTB_GPIO,pinnumber,data);
            break;
            
        case GPIOC:
            pinwrite(PORTC_GPIO,pinnumber,data);
            break;
            
        case GPIOD:
            pinwrite(PORTD_GPIO,pinnumber,data);
            break;
            
        case GPIOE:
            pinwrite(PORTE_GPIO,pinnumber,data);
            break;
    }
}


void pinconfig (GPIO_REGISTER *port,uint8_t mode,uint8_t pin) {
    

    if ( mode == INPUT ) {
        
        switch (pin) {
            
            case 1:
                 port->GPIO_0 = 1;
                break;
            case 2:
                port->GPIO_1 = 1;
                break;
            case 3:
                port->GPIO_2 = 1;
                break;
            case 4:
                port->GPIO_3 = 1;
                break;
            case 5:
                port->GPIO_4 = 1;
                break;
            case 6:
                port->GPIO_5 = 1;
                break;
            case 7:
                port->GPIO_6 = 1;
                break;
            case 8:
                port->GPIO_7 = 1;
                break;
        }
        
    }  else if(mode == OUTPUT) {
       
        switch (pin) {
            
            case 1:
                 port->GPIO_0 = 0;
                break;
            case 2:
                port->GPIO_1 = 0;
                break;
            case 3:
                port->GPIO_2 = 0;
                break;
            case 4:
                port->GPIO_3 = 0;
                break;
            case 5:
                port->GPIO_4 = 0;
                break;
            case 6:
                port->GPIO_5 = 0;
                break;
            case 7:
                port->GPIO_6 = 0;
                break;
            case 8:
                port->GPIO_7 = 0;
                break;
        }        
        
        
    }
}


/*********************************************************************
 * @fn      		  - pinwrite
 *
 * @brief             - This function Write the Data to the respective pin
 *
 * @param[in]         - GPIO Register address
 * @param[in]         - GPIO Pin Number 
 * @param[in]         - 8 bit data which want to write on the pin
 *
 * @return            -  none
 *
 * @Note              -  none

 */

void pinwrite(GPIO_REGISTER *port,uint8_t pin,uint8_t data) {
    
     switch (pin) {
            
            case 1:
                 port->GPIO_0 = data;
                break;
            case 2:
                port->GPIO_1 = data;
                break;
            case 3:
                port->GPIO_2 = data;
                break;
            case 4:
                port->GPIO_3 = data;
                break;
            case 5:
                port->GPIO_4 = data;
                break;
            case 6:
                port->GPIO_5 = data;
                break;
            case 7:
                port->GPIO_6 = data;
                break;
            case 8:
                port->GPIO_7 = data;
                break;
        }
}

uint8_t GPIO_READ (uint8_t port,uint8_t pin ){
   
    uint8_t data;
    switch(port) {
        
        case GPIOA:
            
            data = pinread(PORTA_GPIO,pin);
            return(data);
            break;
            
        case GPIOB:
            data = pinread(PORTB_GPIO,pin);
            return(data);
            
        case GPIOC:
            data = pinread(PORTC_GPIO,pin);
            return(data);
            
        case GPIOD:
            data = pinread(PORTD_GPIO,pin);
            return(data);
            
        case GPIOE:
            data = pinread(PORTE_GPIO,pin);
            return(data);
         
    }
    return 0;
}

uint8_t pinread(GPIO_REGISTER *port,uint8_t pin) {

         switch (pin) {
            
            case 1:
                 return ( port->GPIO_0 );
                break;
            case 2:
                return ( port->GPIO_1 );
                break;
            case 3:
                return ( port->GPIO_2 );
                break;
            case 4:
                return ( port->GPIO_3 );
                break;
            case 5:
                return ( port->GPIO_4 );
                break;
            case 6:
                return ( port->GPIO_5 );
                break;
            case 7:
                return ( port->GPIO_6 );
                break;
            case 8:
                return ( port->GPIO_7 );
                break;
        }
         return 0;
}