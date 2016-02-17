/****************************************************************************
* Title                 :   ADC Application
* Filename              :   adc_app.h
* Author                :   JWB
* Origin Date           :   06/07/2012
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  08/17/13    XXXXXXXXXXX         JWB      Interface Created.
*
*****************************************************************************/
/** @file haptic_hw.h
 *  @brief Contains the hardware layer drivers for HAPTIC click
 *
 *  @date 24 Nov 2015
 *  @author Viktor Milovanovic
 *  @copyright GNU Public License
 *
 *  @version 1.0.0 - Initial testing and verification
 *
 *  @note Test configuration:
 *   MCU:             STM32F107VC
 *   Dev.Board:       EasyMx Pro v7
 *   Oscillator:      72 Mhz internal
 *   Ext. Modules:    GPS Click
 *   SW:              ARM 4.5.2
 *
 */

/**
 * @mainpage
 *  <h1>HAPTIC Click</h1>
 * @par Introduction
 * The DRV2605 device is designed to provide
 * extremely-flexible haptic control of ERM and LRA
 * actuators over a shared I 2 C-compatible bus. This
 * control relieves the host processor from ever
 * generating pulse-width modulated (PWM) drive
 * signals, saving both costly timer interrupts and
 * hardware pins.
 * The DRV2605 device provides an extensive
 * integrated library over 100 licensed effects from
 * Immersion for ERM and LRA which eliminates the
 * need to design haptics waveforms.
 *
 *
 *
 * @par Example on STM :
 * @ref example_arm
 *
 * @par Example on PIC :
 * @ref example_pic
 *
 * @par Example on AVR :
 * @ref example_avr
 *
 * @par Example on FT90x :
 * @ref example_ft90
 *
 *
 * @note You will need to install this library via the <a href="http://www.mikroe.com/package-manager/">Package Manager</a> to use it.
 */
#ifndef HAPTIC_HW_H_
#define HAPTIC_HW_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include "haptic_hal.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/


/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/



/******************************************************************************
* Typedefs
*******************************************************************************/

typedef enum
{
    HAPMODE_INTERNAL = 0,
    HAPMODE_EXTERNAL_EDGE,
    HAPMODE_EXTERNAL_LEVEL,
    HAPMODE_PWM_IN,
    HAPMODE_AUDIO_IN,
    HAPMODE_REAL_TIME,
    HAPMODE_DIAG,
    HAPMODE_CAL,
} haptic_mode_t;


typedef enum
{
    EMPTY = 0,
    LIBRARY_A,
    LIBRARY_B,
    LIBRARY_C,
    LIBRARY_D,
    LIBRARY_E,
    LIBRARY_LRA,
} haptic_library_t;


typedef enum
{
    LOW = 0,
    MEDIUM,
    HIGH,
    VERY_HIGH,
} loop_gain_t;


/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief haptic_init
 * Initializes Haptic click with the desired mode.
 * @param mode
 *  - Desired working mode of the Haptic click
 */
void haptic_init( haptic_mode_t mode );
/**
 * @brief
 * Returns the status of click, contained in the status register.
 * @return
 * Returns status register value.
 */

/**
 * @brief
 * Resets all the registers
 */
void haptic_reset();


/**
 * @brief
 * Reads the value held in status register.
 * @return
 * Returns the value held in the status register
 */
uint8_t haptic_get_status ();
/**
 * @brief
 * Sets the input of the Haptic click to analog.
 */
void set_input_to_analog ();
/**
 * @brief
 * Sets desired minimum analog input for reading.
 * @param temp_data
 *  - Desired minimum input
 */
void set_audio_minimum_input ( uint8_t temp_data );
/**
 * @brief
 * Sets the Haptic click to desired mode.
 * @param mode
 *  - Desired mode
 */
void haptic_set_mode ( haptic_mode_t mode );
/**
 * @brief
 * Sets the desired input for RTP mode
 * @param input
 *  - Desired input for RTP mode
 */
void haptic_set_rtp_input ( uint8_t input );
/**
 * @brief
 * Sets the device in HI state.
 */
void haptic_set_to_HI_state ( void );
/**
 * @brief
 * Sets the desired library of vibrating patterns to read.
 * @param library
 *  - Desired pattern library for reading.
 * @return
 * Returns 0 if succesful.
 */
uint8_t haptic_set_library ( haptic_library_t library );
/**
 * @brief
 * Starts reading the desired pattern nad moving the motor depending on it.
 */
void haptic_start_motor ( void );
/**
 * @brief
 * Sets overdrive offset.
 * @param temp_data
 *  - Desired overdrive offset.
 */
void set_overdrive_offset ( uint8_t temp_data );
/**
 * @brief
 * Sets desired sustain offset - positive
 * @param temp_data
 *  - Desired positive sustain offset
 */
void set_sustain_offset_positive ( uint8_t temp_data );
/**
 * @brief
 * Sets desired sustain offset - positive
 * @param temp_data
 *  - Desired negative sustain offset
 */
void set_sustain_offset_negative ( uint8_t temp_data );
/**
 * @brief
 * Sets desired brake time offset.
 * @param temp_data
 *  - Desired brake time offset.
 */
void set_brake_time_offset ( uint8_t temp_data );
/**
 * @brief
 * Sets minimum input for audio to vibe mode
 * @param temp_data
 *  - Desired minimum input
 */
void set_audio_minimum_input ( uint8_t temp_data );
/**
 * @brief
 * Sets maximum input for audio to vibe mode
 * @param temp_data
 *  - Desired maximum input
 */
void set_audio_maximum_input ( uint8_t temp_data );
/**
 * @brief
 * Sets minimum output for audio to vibe mode
 * @param temp_data
 *  - Desired minimum output
 */
void set_audio_minimum_output ( uint8_t temp_data );
/**
 * @brief
 * Sets maximum output for audio to vibe mode
 * @param temp_data
 *  - Desired maximum output
 */
void set_audio_maximum_output ( uint8_t temp_data );
/**
 * @brief
 * Sets the reference voltage for full-scale output during closed-loop
 * operation.
 * @param temp_data
 *  - Desired value.
 */
void set_rated_voltage ( uint8_t temp_data );
/**
 * @brief
 * Sets a clamp so that the automatic overdrive is
 * bounded. This bit also serves as the full-scale reference voltage for open-loop
 * operation.
 * @param temp_data
 *  - Desired value
 */
void set_overdrive_clamp_voltage ( uint8_t temp_data );
/**
 * @brief
 * Sets the peak detection time for the audio-to-vibe signal path
 * @param temp_data
 *  - Desired value
 * @return
 * returns 0 if successful
 */
uint8_t set_audio_peak_time ( uint8_t temp_data );
/**
 * @brief
 * Sets the low-pass filter frequency for the audio-to-vibe signal path
 * @param temp_data
 *  - Desired value
 * @return
 */
int set_audio_low_pass_filter ( uint8_t temp_data );
/**
 * @brief
 * Reads the voltage-compensation result after execution of auto calibration.
 *
 * @return
 * Returns the value contained in the register
 *
 */
uint8_t get_calibration_result_comp ();
/**
 * @brief Reads the rated back-EMF result after execution of auto calibration.
 *
 * @return
 * Returns the value contained in  the register.
 */
uint8_t get_calibration_result_emf ();
/**
 * @brief
 * Does a real-time reading of the supply voltage at the VDD pin
 * @return
 * Returns voltage on VDD pin
 */
uint8_t get_supply_voltage_value ();
/**
 * @brief
 * Reads the measurement of the LRA resonance period.
 * The device must be actively sending a waveform to take a reading.
 * @return
 * Returns the measurement of the LRA resonance period.
 */
uint8_t get_lra_resonance_period ();
/**
 * @brief
 * Sets the Haptic click in ERM mode
 */
void set_to_erm_mode ();
/**
 * @brief
 * Sets the Haptic click in LRA mode
 */
void set_to_lra_mode ();
/**
 * @brief
 * Sets the feedback gain ratio between braking gain and driving gain.
 * In general, adding additional feedback gain while braking is desirable
 * so that the actuator brakes as quickly as possible.
 * Large ratios provide less-stable operation than lower ones.
 * @param brake_factor
 *  - Desired brake factor
 * @return
 * Returns -1 if failed, 0 if successful.
 */
int set_brake_factor ( uint8_t brake_factor );
/**
 * @brief
 * Selects a loop gain for the feedback control.
 * @param gain
 *  - Desired gain
 * @return
 * Returns -1 if failed, 0 if successful.
 *
 */
int set_loop_gain ( loop_gain_t gain );
/**
 * @brief
 * Sets the input for PWM control of the motor.
 */
void set_input_to_pwm ();

/**
 * @brief
 * Sets the waveform identifier of the waveform to be played. A waveform identifier is an integer value referring
 * to the index position of a waveform in a ROM library. Playback begins at
 * register address 0x04 when the user asserts the GO bit (register 0x0C).
 * When playback of that waveform ends, the waveform sequencer plays the
 * next waveform identifier held in register 0x05
 * @param temp_data
 * - Desired waveform
 */

void set_sequence (uint8_t temp_data);

/**
 * @brief
 * Applies a 0.9-V common mode voltage to the IN/TRIG pin when an AC-
 * coupling capacitor is used. Used for analog input mode.
 */
void enable_ac_coulping ();

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*File_H_*/

/*** End of File **************************************************************/

/**
 * @page example_arm Example on ARM
 * @par Example created using the EasyMX Pro for STM32
 * @par STM32F107
 * @code
 *
 * #include "haptic_hw.h"
 *
 * sbit HAPTIC_EN  at GPIOD_ODR.B13;
 *
 * void HW_Init()
 * {
 *  // haptic_reset();                                         // Reset all registers
 *
 *  // Initialization for Audio input
 *  haptic_i2c_init(HAPTIC_I2C_ADDR);
 *  haptic_hal_enable();                                       // set enable pin to 1
 *  haptic_set_mode(HAPTIC_MODE_AUTOCAL);                      // set working mode to auto calibration
 *  haptic_start_motor();                                      // start calibrating
 *  delay_ms(100);

 *  haptic_set_mode(HAPTIC_MODE_AUDIOVIBE);                    // Set Audio-to-Vibe mode
 *  set_audio_minimum_input(0x0C);                             // Minimum Input level (About 1.35V)
 *  enable_ac_coulping();                                      // enable AC coupling
 *  set_input_to_analog ();                                    // Select Input mode for Analog input
 * }
 *
 *
 * // Main function
 *
 * void main()
 * {
 *  GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_13);         // Set EN pin as output
 *  I2C1_Init_Advanced(400000, &_GPIO_MODULE_I2C1_PB67);       // I2C1 initialization
 *  delay_ms(200);                                             // Delay (200 ms)
 *
 *  HW_Init();                                                 // DRV2605 Intialization
 *
 *  while(1)
 *  {}
 * }
 *
 * @endcode
 */

/**
 * @page example_pic Example on PIC
 * @par Example created using the EasyPIC v7 Connectivity
 * @par PIC18F45K22
 * @code
 *
 * #include "haptic_hw.h"
 * #include <stdint.h>
 *
 * sbit HAPTIC_EN at LATE0_bit;    // HAPTIC enable pin
 *
 *
 * void HW_Init()
 * {
 *  // haptic_reset();                                          // Reset all registers
 *
 *  // Initialization for Audio input
 *  haptic_i2c_init(HAPTIC_I2C_ADDR);
 *  haptic_hal_enable();                                        // set enable pin to 1
 *  haptic_set_mode(HAPTIC_MODE_AUTOCAL);                       // set working mode to auto calibration
 *  haptic_hal_write8(HAPTIC_REG_GO, 0x01);                     // start calibrating
 *  delay_ms(100);
 *
 *  haptic_set_mode(HAPTIC_MODE_AUDIOVIBE);                     // Set Audio-to-Vibe mode
 *  set_audio_minimum_input(0x0C);                              // Minimum Input level (About 1.35V)
 *  enable_ac_coulping();
 *  set_input_to_analog ();                                     // Select Input mode for Analog input
 *
 * }
 *
 * void main()
 * {
 *  i2c1_init(100000);
 *  ANSELE = 0;
 *  TRISE = 0;                                                  // Set EN pin as output
 *  ANSELC = 0;
 *  HW_Init();
 *  while (1)
 *  {}
 *
 * }
 *
 * @endcode
 */


/**
 * @page example_avr Example on AVR
 * @par Example created using the EasyAVR v7 Connectivity
 * @par ATMEGA32
 * @code
 *
 * #include "haptic_hw.h"
 * sbit HAPTIC_EN at PORTA5_bit;
 * sbit HAPTIC_EN_DIR at DDA5_bit;
 *
 * void HW_Init()
 * {
 *  // haptic_reset();                                          // Reset all registers
 *
 *  // Initialization for Audio input
 *  haptic_i2c_init(HAPTIC_I2C_ADDR);
 *  haptic_hal_enable();                                        // set enable pin to 1
 *  haptic_set_mode(HAPTIC_MODE_AUTOCAL);                       // set working mode to auto calibration
 *  haptic_hal_write8(HAPTIC_REG_GO, 0x01);                     // start calibrating
 *  delay_ms(100);
 *
 *  haptic_set_mode(HAPTIC_MODE_AUDIOVIBE);                     // Set Audio-to-Vibe mode
 *  set_audio_minimum_input(0x0C);                              // Minimum Input level (About 1.35V)
 *  enable_ac_coulping();
 *  set_input_to_analog ();                                     // Select Input mode for Analog input
 *
 * }
 *
 *
 *
 * void main()
 * {
 *  HAPTIC_EN_DIR = 0;                                          // set EN pin to output
 *  TWI_Init( 100000 );
 *  delay_ms(200);
 *  HW_Init();
 *
 *  while (1)
 *  {}
 *
 * }
 *
 * @endcode
 */



/**
 * @page example_ft90 Example on FT90x
 * @par Example created using the EasyFT90x v7
 * @par FT900
 * @code
 *
 * #include "haptic_hw.h"
 *
 * sbit HAPTIC_EN  at GPIO_PIN28_bit;
 *
 * void HW_Init()
 * {
 *  // haptic_reset();                                          // Reset all registers
 *
 *  // Initialization for Audio input
 *  haptic_i2c_init(HAPTIC_I2C_ADDR);
 *  haptic_hal_enable();                                        // set enable pin to 1
 *  haptic_set_mode(HAPTIC_MODE_AUTOCAL);                       // set working mode to auto calibration
 *  haptic_hal_write8(HAPTIC_REG_GO, 0x01);                     // start calibrating
 *  delay_ms(100);
 *
 *  haptic_set_mode(HAPTIC_MODE_AUDIOVIBE);                      // Set Audio-to-Vibe mode
 *  set_audio_minimum_input(0x0C);                              // Minimum Input level (About 1.35V)
 *  enable_ac_coulping();
 *  set_input_to_analog ();                                     // Select Input mode for Analog input
 *
 * }
 *
 *
 *
 * void main()
 * {
 *
 *   GPIO_Pin_Digital_Output(28);                                // Set EN pin as output
 *   I2CM1_Init(_I2CM_SPEED_MODE_STANDARD, _I2CM_SWAP_DISABLE);  // I2C1 initialization
 *   delay_ms(200);                                              // Delay (200 ms)
 *
 *   HW_Init();
 *
 *   while(1)
 *   {}
 * }
 * @endcode
 */
