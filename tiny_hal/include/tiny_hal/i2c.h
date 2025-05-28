
#ifndef 	__I2C__
#define 	__I2C__

#include <tiny_hal/debug.h>
#include <tiny_hal/registers.h>
#include <tiny_hal/io.h>
#include <tiny_hal/delay.h>


// I2C pins should be defined as multiplexed open drain output
#ifndef PIN_I2C_SDA
    #define PIN_I2C_SDA     (PC1)
#endif
#ifndef PIN_I2C_SCL
    #define PIN_I2C_SCL     (PC2)
#endif


#define I2C_TIMEOUT         (1000000)
#define I2C_STATUS_GETCTRL  ((((1 << I2C1_BUSY) | (1 << I2C1_MSL)) << 16) | (1 << I2C1_SB)) // BUSY - MSL - SB
#define I2C_STATUS_SENDADDR ((((1 << I2C1_TRA) | (1 << I2C1_BUSY) | (1 << I2C1_MSL)) << 16) | (1 << I2C1_TXE) | (1 << I2C1_ADDR)) // TRA - BUSY - MSL - TXE - ADDR
#define I2C_STATUS_SENDBYTE ((((1 << I2C1_TRA) | (1 << I2C1_BUSY) | (1 << I2C1_MSL)) << 16) | (1 << I2C1_TXE) | (1 << I2C1_BTF)) // TRA - BUSY - MSL - TXE - BTF


typedef enum: uint8_t{
    I2C_EOK,
    I2C_EBUSY,
    I2C_ESTART,
    I2C_ESTOP,
    I2C_EARLO,
    I2C_EBERR,
    I2C_EADDR,
    I2C_EACK,
    I2C_ETX,
    I2C_EUNKN,
} i2c_t;


void i2c_reset(uint8_t hard_reset);
void i2c_enable();
i2c_t i2c_send_byte(uint8_t data, uint8_t start, uint8_t stop);
i2c_t i2c_send_nbytes(uint8_t addr, uint8_t *data, uint8_t nbytes);
uint8_t i2c_recv_byte(uint8_t ack);


#endif // __I2C__
