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


/******************************************************************************
* Includes
*******************************************************************************/

#include "haptic_hal.h"
#if defined( __GNUC__ )
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#endif

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
/**
 * Doxygen tag for documenting variables and constants
 */

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/
#define WRITE 0
#define READ  1

/******************************************************************************
* Module Typedefs
*******************************************************************************/
#if defined(__MIKROC_PRO_FOR_ARM__)
static unsigned int ( *i2c_start_p )( void );
static void ( *i2c_read_p )( char slave_address, char *ptrdata,
                             unsigned long count, unsigned long END_mode );
static unsigned int ( *i2c_write_p )( unsigned char slave_address,
                                      unsigned char *buf,
                                      unsigned long count,
                                      unsigned long END_mode );

#elif defined(__MIKROC_PRO_FOR_AVR__)
static unsigned char ( *i2c_start_p )( void );
static unsigned char ( *i2c_read_p )( unsigned char ack );
static void ( *i2c_write_p )( unsigned char data_ );
static void ( *i2c_stop_p )( void );

#elif defined(__MIKROC_PRO_FOR_8051__)

#elif defined(__MIKROC_PRO_FOR_FT90x__)
static char ( *i2c_read_p )( char *bufferIn, unsigned int numBytesToReceive );
static char ( *i2c_write_p )( char *bufferOut, unsigned int numBytesToWrite );

#elif defined(__MIKROC_PRO_FOR_PIC__)
static unsigned char ( *i2c_start_p )( void );
static unsigned char ( *i2c_read_p )( unsigned char ack );
static unsigned char ( *i2c_write_p )( unsigned char data_ );
static void ( *i2c_stop_p )( void );
static void ( *i2c_repeat_p )( void );

#elif defined(__MIKROC_PRO_FOR_DSPIC__)
static unsigned int ( *i2c_start_p )( void );
static unsigned char ( *i2c_read_p )( unsigned int ack );
static unsigned int ( *i2c_write_p )( unsigned char data_ );
static void ( *i2c_stop_p )( void );
static void ( *i2c_repeat_p )( void );

#elif defined(__MIKROC_PRO_FOR_PIC32__)
static unsigned int ( *i2c_start_p )( void );
static unsigned char ( *i2c_read_p )( unsigned int ack );
static unsigned int ( *i2c_write_p )( unsigned char data_ );
static void ( *i2c_stop_p )( void );

#endif

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
static uint8_t i2c_address;

#if defined(__MIKROC_PRO_FOR_AVR__)   || \
    defined(__MIKROC_PRO_FOR_8051__)  || \
    defined(__MIKROC_PRO_FOR_DSPIC__) || \
    defined(__MIKROC_PRO_FOR_PIC32__) || \
    defined(__MIKROC_PRO_FOR_FT90x__) || \
    defined(__MIKROC_PRO_FOR_ARM__ )  || \
    defined(__MIKROC_PRO_FOR_PIC__)

extern sfr sbit HAPTIC_EN;

#elif defined(__GNUC__)

extern uint8_t bits;
extern uint32_t speed;
extern uint16_t delay;
#define _hal_i2c_start
#define _hal_i2c_read
#define _hal_i2c_write
#define _hal_i2c_stop
#endif

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#if defined( __GNUC__ )
static void transfer( int fd, uint8_t const *tx,
                      uint8_t const *rx, size_t len );
#endif
/******************************************************************************
* Function Definitions
*******************************************************************************/

int haptic_i2c_init( uint8_t address_id )
{
#if defined( __MIKROC_PRO_FOR_ARM__ ) || \
    defined(__MIKROC_PRO_FOR_FT90x__)
    i2c_address = address_id;
#else
    i2c_address = ( address_id << 1 );
#endif

#if defined(__MIKROC_PRO_FOR_AVR__)
    i2c_start_p = TWI_Start;
    i2c_read_p  = TWI_Read;
    i2c_write_p = TWI_Write;
    i2c_stop_p  = TWI_Stop;

#elif defined(__MIKROC_PRO_FOR_ARM__ )
    i2c_start_p = I2C_Start_Ptr;
    i2c_read_p  = I2C_Read_Ptr;
    i2c_write_p = I2C_Write_Ptr;

#elif defined(__MIKROC_PRO_FOR_8051__)

#elif defined(__MIKROC_PRO_FOR_FT90x__)
    i2c_read_p = I2CM_Read_Bytes_Ptr;
    i2c_write_p = I2CM_Write_Bytes_Ptr;
#define i2c_start_p 1

#elif defined(__MIKROC_PRO_FOR_DSPIC__)
    i2c_start_p = I2C1_Start;
    i2c_read_p  = I2C1_Read;
    i2c_write_p = I2C1_Write;
    i2c_stop_p  = I2C1_Stop;
    i2c_repeat_p= I2C1_Restart;

#elif defined(__MIKROC_PRO_FOR_PIC__)
    i2c_start_p = I2C1_Start;
    i2c_read_p  = I2C1_Rd;
    i2c_write_p = I2C1_Wr;
    i2c_stop_p  = I2C1_Stop;
    i2c_repeat_p= I2C1_Repeated_Start;

#elif defined(__MIKROC_PRO_FOR_PIC32__)
    i2c_start_p = I2C_Start_Ptr;
    i2c_read_p  = I2C_Read_Ptr;
    i2c_write_p = I2C_Write_Ptr;
    i2c_stop_p  = I2C_Stop_Ptr;

#endif

    if( i2c_start_p == 0 || i2c_read_p == 0 || i2c_write_p == 0 )
        return -1;

    return 0;
}


void haptic_hal_enable()
{
#if defined(__MIKROC_PRO_FOR_AVR__)   || \
    defined(__MIKROC_PRO_FOR_8051__)  || \
    defined(__MIKROC_PRO_FOR_DSPIC__) || \
    defined(__MIKROC_PRO_FOR_PIC32__) || \
    defined(__MIKROC_PRO_FOR_PIC__)   || \
    defined(__MIKROC_PRO_FOR_ARM__ )  || \
    defined(__MIKROC_PRO_FOR_FT90x__)
    HAPTIC_EN = 1;

#elif defined( __GNUC__ )

#endif
}

void haptic_hal_disable()
{
#if defined(__MIKROC_PRO_FOR_AVR__)   || \
    defined(__MIKROC_PRO_FOR_8051__)  || \
    defined(__MIKROC_PRO_FOR_DSPIC__) || \
    defined(__MIKROC_PRO_FOR_PIC32__) || \
    defined(__MIKROC_PRO_FOR_PIC__)   || \
    defined(__MIKROC_PRO_FOR_ARM__ )  || \
    defined(__MIKROC_PRO_FOR_FT90x__)
    HAPTIC_EN = 0;

#elif defined( __GNUC__ )

#endif
}

uint8_t haptic_hal_read8 ( uint8_t reg_address )
{

#if defined( __MIKROC_PRO_FOR_ARM__ )
    uint8_t buffer[1];
    buffer[0] = reg_address;
    i2c_start_p();
    i2c_write_p( i2c_address, buffer, 1, END_MODE_RESTART );
    i2c_read_p( i2c_address, buffer, 1, END_MODE_STOP );
    return buffer[0];
#elif defined (__MIKROC_PRO_FOR_FT90x__)
    uint8_t buffer;
    i2c_write_p ( reg_address, 1 );
    i2c_read_p ( &buffer, 1 );
    return buffer;

#elif       defined(__MIKROC_PRO_FOR_8051__)  || \
            defined(__MIKROC_PRO_FOR_DSPIC__) || \
            defined(__MIKROC_PRO_FOR_PIC32__)


#elif defined(__MIKROC_PRO_FOR_AVR__)
    uint8_t buffer[1];
    buffer[0] = reg_address;
    i2c_start_p();
    i2c_write_p( i2c_address + WRITE );
    i2c_write_p( buffer[0] );
    i2c_start_p();
    i2c_write_p( i2c_address + READ );
    buffer[0] = i2c_read_p( 0u );
    i2c_stop_p();
    return buffer[0];

#elif  defined(__MIKROC_PRO_FOR_PIC__)
    uint8_t buffer;
    i2c_start_p();
    i2c_write_p( i2c_address + WRITE );
    i2c_write_p( reg_address );
    i2c_start_p();
    i2c_write_p( i2c_address + READ );
    buffer = i2c_read_p( 0u );
    i2c_stop_p();
    return buffer;

#endif

}

// Generic I2C write data to register (single byte)
void haptic_hal_write8( uint8_t reg_address, uint8_t reg_data )
{
    static uint8_t buffer[2];
    buffer[0] = reg_address;
    buffer[1] = reg_data;
#if defined( __MIKROC_PRO_FOR_ARM__ )
    i2c_start_p();
    i2c_write_p( i2c_address, buffer, 2, END_MODE_STOP );

#elif defined (__MIKROC_PRO_FOR_FT90x__)
    i2cm1_set_slave_address ( HAPTIC_I2C_ADDR );
    i2c_write_p( buffer, 2 );

#elif defined(__MIKROC_PRO_FOR_AVR__) || \
            defined(__MIKROC_PRO_FOR_8051__)  || \
            defined(__MIKROC_PRO_FOR_DSPIC__) || \
            defined(__MIKROC_PRO_FOR_PIC32__)
    i2c_start_p();
    i2c_write_p( i2c_address | WRITE );
    i2c_write_p( buffer[0] );
    i2c_write_p( buffer[1] );
    i2c_stop_p();

#elif  defined(__MIKROC_PRO_FOR_PIC__)
    i2c_start_p();
    i2c_write_p( i2c_address + WRITE );
    i2c_write_p( buffer[0] );
    i2c_write_p( buffer[1] );
    i2c_stop_p();
#endif
}




/*************** END OF FUNCTIONS ***************************************************************************/