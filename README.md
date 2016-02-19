![mikroe_logo] 
# by [MikroElektronika]
![haptic_image] 
# More information about [Haptic click] is found here.
---
## Installation
>If installing from package, [Package manager] required to install to your IDE.  

## Looking for a [tutorial?][Haptic Tutorial]

### Example
```
#include "haptic_hw.h"

sbit HAPTIC_EN  at GPIOD_ODR.B13;

void hw_init( void );

void hw_init()
{
    // Initialization for Audio input
    haptic_i2c_init(HAPTIC_I2C_ADDR);
    haptic_hal_enable();                   // set enable pin to 1
    haptic_set_mode(HAPTIC_MODE_AUTOCAL);  // set working mode to auto calibration
    haptic_start_motor();                  // start calibrating
    Delay_ms(100);

    haptic_set_mode(HAPTIC_MODE_AUDIOVIBE);  // Set Audio-to-Vibe mode
    set_audio_minimum_input(0x0C);           // Minimum Input level (About 1.35V)
    enable_ac_coulping();                    // enable AC coupling
    set_input_to_analog ();                  // Select Input mode for Analog input
}


void main() 
{
    GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_13);         // Set EN pin as output
    I2C1_Init_Advanced(400000, &_GPIO_MODULE_I2C1_PB67);       // I2C1 initialization
    Delay_ms(200);                                             // Delay (200 ms)

    hw_init();                                                 // DRV2605 Intialization

    while(1);
}
```

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [MikroElektronika]: <http://www.mikroe.com/>
   [mikroe_logo]: <http://www.mikroe.com/img/designs/beta/logo_small.png>
   [Haptic click]: <http://www.mikroe.com/click/haptic/>
   [haptic_image]: <http://cdn.mikroe.com/img/click/haptic/haptic_click.png>
   [Haptic Tutorial]: <http://learn.mikroe.com/haptic-click-feel-the-code-on-your-skin/>
   [Package Manager]: <http://www.mikroe.com/package-manager/>