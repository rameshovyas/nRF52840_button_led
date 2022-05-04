#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"
#include "nrf_gpio.h" // Required for configuring GPIO PINS

/*  
 Program to control LED on a Button press
 Board used : nRF52840 DK
 Author : Ramesh Vyas
*/

#define LED1 13
#define BUTTON1 11

int main(void)
{
    
    nrf_gpio_cfg_output(LED1); // Set pin 13 (LED1) as output pin 
    
    nrf_gpio_cfg_input(BUTTON1,NRF_GPIO_PIN_PULLUP); // SEt pin 11 (BUTTON1) as input pin
   
    nrf_gpio_pin_set(LED1) ; // Turns off the LED1 at pin 13 as it works on reverse logic

    while (true)
    {
        if(nrf_gpio_pin_read(BUTTON1) == 0 )
        {
          nrf_gpio_pin_clear(LED1); // Turns on the LED1 at pin 13

          while(nrf_gpio_pin_read(BUTTON1) == 0); // Stays in the loop until the button is released

          nrf_gpio_pin_set(LED1); // Turns the LED1 off at pin 13
        }
    }
}


