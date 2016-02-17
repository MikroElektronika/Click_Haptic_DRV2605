/*******************************************************************************
* Title                 :   System Initialization
* Filename              :   sys_init.c
* Author                :   JWB
* Origin Date           :   04/23/2012
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials   Description
*  XX/XX/XX    XXXXXXXXXXX         JWB      Module Created.
*
*******************************************************************************/
/** @file XXX.c
 *  @brief This module contains the
 */
/******************************************************************************
* Includes
*******************************************************************************/
//#include <ints.h>                                        // For portable types
#include "haptic_hal.h"
#include "haptic_hw.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
/**
 * Doxygen tag for documenting variables and constants
 */


/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

void haptic_set_mode ( haptic_mode_t mode )
{
    switch( mode )
    {
        case 0:
            haptic_hal_write8 ( HAPTIC_REG_MODE, 0x00 );
            break;
        case 1:
            haptic_hal_write8 ( HAPTIC_REG_MODE, 0x01 );
            break;
        case 2:
            haptic_hal_write8 ( HAPTIC_REG_MODE, 0x02 );
            break;
        case 3:
            haptic_hal_write8 ( HAPTIC_REG_MODE, 0x03 );
            break;
        case 4:
            haptic_hal_write8 ( HAPTIC_REG_MODE, 0x04 );
            break;
        case 5:
            haptic_hal_write8 ( HAPTIC_REG_MODE, 0x05 );
            break;
        case 6:
            haptic_hal_write8 ( HAPTIC_REG_MODE, 0x06 );
            break;
        case 7:
            haptic_hal_write8 ( HAPTIC_REG_MODE, 0x07 );
            break;
    }
}


void haptic_init ( haptic_mode_t mode )
{
    if( haptic_i2c_init( HAPTIC_I2C_ADDR ) )
        return;
    
    haptic_hal_enable();

    // Initialization for Internal trigger
    haptic_set_mode( mode );
}

void haptic_reset()
{
   haptic_hal_write8(HAPTIC_REG_MODE, 0x80 );
}


uint8_t haptic_get_status ( void )
{
    uint8_t temp;
    temp = haptic_hal_read8( HAPTIC_REG_STATUS );
    return temp;
}


void haptic_set_rtp_input ( uint8_t input )
{
    haptic_hal_write8 ( HAPTIC_REG_RTPIN, input );
}


void haptic_set_to_HI_state ( void )
{
    uint8_t temp_read;
    temp_read =  haptic_hal_read8( HAPTIC_REG_LIBRARY );
    temp_read |= ( 1 << 7 );
    haptic_hal_write8 ( HAPTIC_REG_LIBRARY, temp_read );
}

uint8_t haptic_set_library ( haptic_library_t library )
{
    uint8_t temp_read;
    temp_read =  haptic_hal_read8( HAPTIC_REG_LIBRARY );
    temp_read &= ~( 0b00000111 );


    switch ( library )
    {
        case 0:
            temp_read &= ~( 0b00000111 );
            break;
        case 1:
            temp_read |= ( 0b00000001 );
            break;
        case 2:
            temp_read |= ( 0b00000010 );
            break;
        case 3:
            temp_read |= ( 0b00000011 );
            break;
        case 4:
            temp_read |= ( 0b00000100 );
            break;
        case 5:
            temp_read |= ( 0b00000101 );
            break;
        case 6:
            temp_read |= ( 0b00000110 );
            break;
        default:
            break;
    }

    haptic_hal_write8( HAPTIC_REG_LIBRARY, temp_read );
    return 1;
}

void haptic_start_motor ( void )
{
    haptic_hal_write8 ( HAPTIC_REG_GO, 0x01 );
}

void set_overdrive_offset ( uint8_t temp_data )
{
    haptic_hal_write8 ( HAPTIC_REG_OVERDRIVE, temp_data );
}

void set_sustain_offset_positive ( uint8_t temp_data )
{
    haptic_hal_write8 ( HAPTIC_REG_SUSTAINPOS, temp_data );
}

void set_sustain_offset_negative ( uint8_t temp_data )
{
    haptic_hal_write8 ( HAPTIC_REG_SUSTAINNEG, temp_data );
}

void set_brake_time_offset ( uint8_t temp_data )
{
    haptic_hal_write8 ( HAPTIC_REG_BREAK, temp_data );
}

void set_audio_minimum_input ( uint8_t temp_data )
{
    haptic_hal_write8 ( HAPTIC_REG_AUDIOMININ, temp_data );
}

void set_audio_maximum_input ( uint8_t temp_data )
{
    haptic_hal_write8 ( HAPTIC_REG_AUDIOMAXIN, temp_data );
}

void set_audio_minimum_output ( uint8_t temp_data )
{
    haptic_hal_write8 ( HAPTIC_REG_AUDIOMINOUT, temp_data );
}

void set_audio_maximum_output ( uint8_t temp_data )
{
    haptic_hal_write8 ( HAPTIC_REG_AUDIOMAXOUT, temp_data );
}


void set_rated_voltage ( uint8_t temp_data )
{
    haptic_hal_write8 ( HAPTIC_REG_RATEDV, temp_data );
}


void set_overdrive_clamp_voltage ( uint8_t temp_data )
{
    haptic_hal_write8 ( HAPTIC_REG_CLAMPV, temp_data );
}


uint8_t set_audio_peak_time ( uint8_t temp_data )
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8( HAPTIC_REG_AUDIOCTRL );
    switch( temp_data )
    {
        case 0:
            temp_read &= ~1;
            haptic_hal_write8 ( HAPTIC_REG_AUDIOCTRL, temp_read );
            break;
        case 1:
            temp_read |= ( 1 << 2 );
            haptic_hal_write8 ( HAPTIC_REG_AUDIOCTRL, temp_read );
            break;
        case 2:
            temp_read |= ( 1 << 3 );
            haptic_hal_write8 ( HAPTIC_REG_AUDIOCTRL, temp_read );
            break;
        case 3:
            temp_read |= ( 1 << 3 );
            temp_read |= ( 1 << 2 );
            haptic_hal_write8 ( HAPTIC_REG_AUDIOCTRL, temp_read );
            break;
        default:
            return -1;
    }
    return 0;
}

int set_audio_low_pass_filter ( uint8_t temp_data )
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8( HAPTIC_REG_AUDIOCTRL );

    switch( temp_data )
    {
        case 0:
            temp_read &= ~1;
            haptic_hal_write8 ( HAPTIC_REG_AUDIOCTRL, temp_read );
            break;
        case 1:
            temp_read |= 1;
            haptic_hal_write8 ( HAPTIC_REG_AUDIOCTRL, temp_read );
            break;
        case 2:
            temp_read |= ( 1 << 1 );
            haptic_hal_write8 ( HAPTIC_REG_AUDIOCTRL, temp_read );
            break;
        case 3:
            temp_read |= ( 1 << 1 );
            temp_read |= ( 1 << 2 );
            haptic_hal_write8 ( HAPTIC_REG_AUDIOCTRL, temp_read );
            break;
        default:
            return -1;

    }
    return 0;
}

uint8_t get_calibration_result_comp ()
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8( HAPTIC_REG_AUTOCALCOMP );
    return temp_read;

}

uint8_t get_calibration_result_emf ()
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8 ( HAPTIC_REG_AUTOCALEMF );
    return temp_read;
}

uint8_t get_supply_voltage_value ()
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8( HAPTIC_REG_VBAT );
    return temp_read;
}

uint8_t get_lra_resonance_period ()
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8( HAPTIC_REG_LRARESON );
    return temp_read;
}

void set_to_erm_mode ()
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8( HAPTIC_REG_FEEDBACK );
    temp_read &= ~( 1 << 7 );
    haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
}

void set_to_lra_mode ()
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8( HAPTIC_REG_FEEDBACK );
    temp_read |= ( 1 << 7 );
    haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
}


int set_brake_factor ( uint8_t brake_factor )
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8( HAPTIC_REG_FEEDBACK );

    switch ( brake_factor )
    {
        case 1:
            temp_read &= ~( 1 << 4 );
            temp_read &= ~( 1 << 5 );
            temp_read &= ~( 1 << 6 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;
        case 2:
            temp_read |= ( 1 << 4 );
            temp_read &= ~( 1 << 5 );
            temp_read &= ~( 1 << 6 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;
        case 3:
            temp_read &= ~( 1 << 4 );
            temp_read |=  ( 1 << 5 );
            temp_read &= ~( 1 << 6 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;
        case 4:
            temp_read |= ( 1 << 4 );
            temp_read |= ( 1 << 5 );
            temp_read &= ~( 1 << 6 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;
        case 6:
            temp_read &= ~( 1 << 4 );
            temp_read &= ~( 1 << 5 );
            temp_read |= ( 1 << 6 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;
        case 8:
            temp_read |= ( 1 << 4 );
            temp_read &= ~( 1 << 5 );
            temp_read |= ( 1 << 6 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;
        case 16:
            temp_read &= ~( 1 << 4 );
            temp_read |= ( 1 << 5 );
            temp_read |= ( 1 << 6 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;
        default :
            return -1;

    }

    return 0;

}




int set_loop_gain ( loop_gain_t gain )
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8( HAPTIC_REG_FEEDBACK );

    switch ( gain )
    {
        case LOW:
            temp_read &= ~( 1 << 2 );
            temp_read &= ~( 1 << 2 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;

        case MEDIUM:
            temp_read |= ( 1 << 2 );
            temp_read &= ~( 1 << 2 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;
        case HIGH:
            temp_read &= ~( 1 << 2 );
            temp_read |=  ( 1 << 2 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;
        case VERY_HIGH:
            temp_read |= ( 1 << 2 );
            temp_read |= ( 1 << 2 );
            haptic_hal_write8( HAPTIC_REG_FEEDBACK, temp_read );
            break;
        default:
            return -1;
    }
    return 0;
}

void set_input_to_analog ()
{

    haptic_hal_write8( HAPTIC_REG_CONTROL3, 0x02 );

}

void set_input_to_pwm ()
{
    uint8_t temp_read;
    temp_read = haptic_hal_read8( HAPTIC_REG_CONTROL3 );
    temp_read &= ~ ( 1 << 1 );
    haptic_hal_write8( HAPTIC_REG_CONTROL3, temp_read );

}


void set_sequence (uint8_t temp_data)
{
    haptic_hal_write8(HAPTIC_REG_WAVESEQ1, temp_data );

}

void enable_ac_coulping ()
{
    haptic_hal_write8 ( HAPTIC_REG_CONTROL1, 0xB3 );
}





/*************** END OF FUNCTIONS ***************************************************************************/
