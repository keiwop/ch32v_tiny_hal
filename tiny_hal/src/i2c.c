
#include <tiny_hal/i2c.h>


static inline uint8_t i2c_check_status(uint32_t status_mask){
    uint32_t status = reg_ptr(I2C1_STAR1) | reg_ptr(I2C1_STAR2) << 16; // Read STAR2 after STAR1, it's a condition to reset the ADDR bit
    return (status & status_mask) == status_mask;
}


static inline uint8_t wait_for_status(uint32_t status_mask){
    uint32_t counter = I2C_TIMEOUT;
    while(counter-- > 0){
        if(i2c_check_status(status_mask)){
            return 0;
        }
    }
    return 1;
}


static inline uint8_t wait_for_bit(uint32_t reg, uint8_t bit, uint8_t value){
    uint32_t counter = I2C_TIMEOUT;
    while(counter-- > 0){
        if(check_bit(reg, bit) >> bit == value){
            return 0;
        }
    }
    return 1;
}


void i2c_reset(uint8_t hard_reset){
    if(hard_reset){
        sbi(RCC_APB1PRSTR, RCC_I2C1RST);
        cbi(RCC_APB1PRSTR, RCC_I2C1RST);
    }
    else{
        sbi(I2C1_CTRLR1, I2C1_SWRST);
        cbi(I2C1_CTRLR1, I2C1_SWRST);
    }
}


void i2c_enable(){
    sbi(RCC_APB1PCENR, RCC_I2C1EN);         // Enable i2c clock
    pin_output_mod(PIN_I2C_SDA);            // Set pin to output multiplexed open drain
    pin_output_mod(PIN_I2C_SCL);
    sreg(I2C1_CTRLR2, 24, I2C1_FREQ);       // PCLK is running at 24MHz (Prescaler disabled)
    sreg(I2C1_CKCFGR, 120, I2C1_CCR);       // PCLK / (2 * i2c_speed) = 120
    sbi(I2C1_CTRLR1, I2C1_PE);              // Enable the i2c
}


i2c_t i2c_send_byte(uint8_t data, uint8_t start, uint8_t stop){
    if(start){
        if(wait_for_bit(I2C1_STAR2, I2C1_BUSY, 0)){
            return I2C_EBUSY;
        }
        sbi(I2C1_CTRLR1, I2C1_START);

        if(wait_for_status(I2C_STATUS_GETCTRL)){
            return I2C_ESTART;
        }

        reg_ptr(I2C1_DATAR) = (data << 1);
        if(wait_for_status(I2C_STATUS_SENDADDR)){
            return I2C_EADDR;
        }
    }
    else{
        reg_ptr(I2C1_DATAR) = data;
        if(wait_for_bit(I2C1_STAR1, I2C1_TXE, 1)){
            return I2C_ETX;
        }
    }

    if(stop){
        sbi(I2C1_CTRLR1, I2C1_STOP);
    }
    return I2C_EOK;
}


i2c_t i2c_send_nbytes(uint8_t addr, uint8_t *data, uint8_t nbytes){
    i2c_send_byte(addr << 1, 1, 0);
    uint8_t i, stop, ret;
    for(i = 0; i < nbytes; ++i){
        if(i == nbytes - 1){
            stop = 1;
        }
        if((ret = i2c_send_byte(data[i], 0, stop))){
            return ret;
        }
    }
    return ret;
}

// TODO
uint8_t i2c_recv_byte(uint8_t ack){
    wait_for_bit(I2C1_STAR1, I2C1_RXNE, 1);
    if(ack){
        sbi(I2C1_CTRLR1, I2C1_ACK);
    }
    else{
        cbi(I2C1_CTRLR1, I2C1_ACK);
    }
    return (uint8_t)(reg_ptr(I2C1_DATAR) & 0xff);
}
