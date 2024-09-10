#include "system_driver.h"

#define INPUT ENABLE 
#define OUTPUT DISABLE
#define HIGH ENABLE
#define LOW DISABLE 

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3
#define GPIOE 4


/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
typedef struct {
    v uint8_t GPIO_0 : 1;
    v uint8_t GPIO_1 : 1;
    v uint8_t GPIO_2 : 1;
    v uint8_t GPIO_3 : 1;
    v uint8_t GPIO_4 : 1;
    v uint8_t GPIO_5 : 1;
    v uint8_t GPIO_6 : 1;
    v uint8_t GPIO_7 : 1;  
}GPIO_REGISTER;


#define GPIO_TRIS_BASE_ADDR  0x00U
#define GPIO_PORT_BASE_ADDR  0x00U

#define TRISA_GPIO (GPIO_REGISTER *)(GPIO_TRIS_BASE_ADDR + 0x85)
#define TRISB_GPIO (GPIO_REGISTER *)(GPIO_TRIS_BASE_ADDR + 0x86)
#define TRISC_GPIO (GPIO_REGISTER *)(GPIO_TRIS_BASE_ADDR + 0x87)
#define TRISD_GPIO (GPIO_REGISTER *)(GPIO_TRIS_BASE_ADDR + 0x88)
#define TRISE_GPIO (GPIO_REGISTER *)(GPIO_TRIS_BASE_ADDR + 0x89)

#define PORTA_GPIO (GPIO_REGISTER *)(GPIO_PORT_BASE_ADDR + 0x05)
#define PORTB_GPIO (GPIO_REGISTER *)(GPIO_PORT_BASE_ADDR + 0x06)
#define PORTC_GPIO (GPIO_REGISTER *)(GPIO_PORT_BASE_ADDR + 0x07)
#define PORTD_GPIO (GPIO_REGISTER *)(GPIO_PORT_BASE_ADDR + 0x08)
#define PORTE_GPIO (GPIO_REGISTER *)(GPIO_PORT_BASE_ADDR + 0x09)





void GPIO_MODE (uint8_t,uint8_t ,uint8_t );
void GPIO_WRITE (uint8_t,uint8_t,uint8_t );
uint8_t GPIO_READ (uint8_t,uint8_t );

void pinconfig (GPIO_REGISTER *,uint8_t,uint8_t);
uint8_t pinread(GPIO_REGISTER *,uint8_t );
void pinwrite(GPIO_REGISTER *,uint8_t ,uint8_t );