#include "haptic_hw.h"

sbit HAPTIC_EN  at GPIOD_ODR.B13;

void HW_Init(){
  //Write_DRV2605(DRV2605_REG_MODE, 0x80);                   // Reset all registers

  // Initialization for Audio input
  haptic_i2c_init(HAPTIC_I2C_ADDR);
  haptic_hal_enable();                                       // set enable pin to 1
  haptic_set_mode(HAPTIC_MODE_AUTOCAL);                      // set working mode to auto calibration
  haptic_start_motor();                                      // start calibrating
  delay_ms(100);

  haptic_set_mode(HAPTIC_MODE_AUDIOVIBE);                    // Set Audio-to-Vibe mode
  set_audio_minimum_input(0x0C);                             // Minimum Input level (About 1.35V)
  enable_ac_coulping();                                      // enable AC coupling
  set_input_to_analog ();                                    // Select Input mode for Analog input
}

// Main function

void main() {
  GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_13);         // Set EN pin as output
  I2C1_Init_Advanced(400000, &_GPIO_MODULE_I2C1_PB67);       // I2C1 initialization
  delay_ms(200);                                             // Delay (200 ms)

  HW_Init();                                                 // DRV2605 Intialization

  while(1)
  {}
}
