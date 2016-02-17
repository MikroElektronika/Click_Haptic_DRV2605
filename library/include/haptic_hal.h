/****************************************************************************
* Title                 :   Color2 HAL
* Filename              :   color2_hal.h
* Author                :   VM
* Origin Date           :   16/11/2015
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials     Description
*  16/11/15        1.0.0           VM      Interface Created.
*
*****************************************************************************/
/** @file haptic_hal.h
 *  @brief Contains the HAL drivers for HAPTIC click
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
 *   Ext. Modules:    Color2 Click
 *   SW:              ARM 4.5.2
 *
 *
 */
#ifndef HAPTIC_HAL_H_
#define HAPTIC_HAL_H_
#include <stdint.h>
/******************************************************************************
* Includes
*******************************************************************************/


/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define HAPTIC_I2C_ADDR   0x5A                                                 // HAPTIC I2C address

#define HAPTIC_MODE_INTTRIG  0x00
#define HAPTIC_MODE_EXTTRIGEDGE  0x01
#define HAPTIC_MODE_EXTTRIGLVL  0x02
#define HAPTIC_MODE_PWMANALOG  0x03
#define HAPTIC_MODE_AUDIOVIBE  0x04
#define HAPTIC_MODE_REALTIME  0x05
#define HAPTIC_MODE_DIAGNOS  0x06
#define HAPTIC_MODE_AUTOCAL  0x07


#define HAPTIC_REG_STATUS 0x00          // should return    11100000
#define HAPTIC_REG_MODE 0x01
#define HAPTIC_REG_RTPIN 0x02
#define HAPTIC_REG_LIBRARY 0x03
#define HAPTIC_REG_WAVESEQ1 0x04
#define HAPTIC_REG_WAVESEQ2 0x05
#define HAPTIC_REG_WAVESEQ3 0x06
#define HAPTIC_REG_WAVESEQ4 0x07
#define HAPTIC_REG_WAVESEQ5 0x08
#define HAPTIC_REG_WAVESEQ6 0x09
#define HAPTIC_REG_WAVESEQ7 0x0A
#define HAPTIC_REG_WAVESEQ8 0x0B

#define HAPTIC_REG_GO 0x0C
#define HAPTIC_REG_OVERDRIVE 0x0D
#define HAPTIC_REG_SUSTAINPOS 0x0E
#define HAPTIC_REG_SUSTAINNEG 0x0F
#define HAPTIC_REG_BREAK 0x10
#define HAPTIC_REG_AUDIOCTRL 0x11
#define HAPTIC_REG_AUDIOMININ 0x12
#define HAPTIC_REG_AUDIOMAXIN 0x13
#define HAPTIC_REG_AUDIOMINOUT 0x14
#define HAPTIC_REG_AUDIOMAXOUT 0x15
#define HAPTIC_REG_RATEDV 0x16
#define HAPTIC_REG_CLAMPV 0x17
#define HAPTIC_REG_AUTOCALCOMP 0x18
#define HAPTIC_REG_AUTOCALEMF 0x19
#define HAPTIC_REG_FEEDBACK 0x1A
#define HAPTIC_REG_CONTROL1 0x1B
#define HAPTIC_REG_CONTROL2 0x1C
#define HAPTIC_REG_CONTROL3 0x1D
#define HAPTIC_REG_CONTROL4 0x1E
#define HAPTIC_REG_VBAT 0x21
#define HAPTIC_REG_LRARESON 0x22

/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/



/******************************************************************************
* Typedefs
*******************************************************************************/


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
 * @brief
 * Initializes I2C bus for Haptic click
 * @param address_id
 *  - Haptic click I2C slave address.
 * @return
 * Returns 0 if succesful
 */
int haptic_i2c_init ( uint8_t address_id );
/**
 * @brief
 * Sets the Haptic enable pin so that the module runs the motor.
 */
void haptic_hal_enable( void );
/**
 * @brief
 * Disables the Haptic click module by pulling the enable pin low.
 * The module can still communicate with the MCU, but does not run the motor.
 */
void haptic_hal_disable( void );
/**
 * @brief
 * Writes a byte to Haptic click through  I2C
 * @param reg_address
 *  - Register adress to which the data is sent.
 * @param reg_data
 *  - Desired data for sending.
 */
void haptic_hal_write8 ( uint8_t reg_address, uint8_t reg_data );
/**
 * @brief
 * Reads a byte from Haptic click through  I2C
 * @param reg_address
 *  - Register adress from which the data is read.
 * @return
 * Returns the read byte.
 */
uint8_t haptic_hal_read8 ( uint8_t reg_address );



#ifdef __cplusplus
} // extern "C"
#endif

#endif /*File_H_*/

/*** End of File **************************************************************/
