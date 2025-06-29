// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#include <tiny_hal/uart.h>


void uart_reset(){
    sbi(RCC_APB2PRSTR, RCC_USART1RST);
    cbi(RCC_APB2PRSTR, RCC_USART1RST);
}


void uart_enable(){
    sbi(RCC_APB2PCENR, USART1EN);   // Enable UART clock
    pin_output_mpp(PIN_UART_TX);    // Set pin to output multiplexed push-pull
    pin_pullup(PIN_UART_RX);        // Set pin to input pull-up
    // Set baudrate
    reg_ptr(USART1_BRR) = (UART_MANTISSA << USART1_DIV_M) | (UART_FRACTION << USART1_DIV_F);
    sbi(USART1_CTRLR1, USART1_UE);  // Enable USART
    sbi(USART1_CTRLR1, USART1_TE);  // Enable transmitter
    sbi(USART1_CTRLR1, USART1_RE);  // Enable receiver
}


uart_t uart_send_byte(uint8_t data){
    if(wait_for_bit(USART1_STATR, USART1_TXE, 1)){
        return UART_ETXE;
    }

    reg_ptr(USART1_DATAR) = data;

    if(wait_for_bit(USART1_STATR, USART1_TC, 1)){
        return UART_ECOMPLETE;
    }

    return UART_EOK;
}


uart_t uart_send_nbytes(uint8_t *data, uint8_t nbytes){
    uint8_t i;
    uart_t ret;
    for(i = 0; i < nbytes; ++i){
        if((ret = uart_send_byte(data[i]))){
            return ret;
        }
    }
    return UART_EOK;
}


uart_t uart_print(char *str){
    uart_t ret;
    uint8_t i = 0;
    while(str[i] != '\0'){
        if((ret = uart_send_byte(str[i++]))){
            return ret;
        }
    }
    return UART_EOK;
}


// Receive function returns uart_t as high byte and data as low byte
uint16_t uart_recv_byte(){
    uint16_t data;
    uint32_t status;

    if(wait_for_bit(USART1_STATR, USART1_RXNE, 1)){
        return (UART_ERXNE << 8);
    }

    status = reg_ptr(USART1_STATR);
    data = reg_ptr(USART1_DATAR);   // Reading DATAR after STATR resets error flags

    if(status & (1 << USART1_ORE)){
        return (UART_EOVERLOAD << 8);
    }
    if(status & (1 << USART1_FE)){
        return (UART_EFRAME << 8);
    }
    if(status & (1 << USART1_PE)){
        return (UART_EPARITY << 8);
    }

    return data;
}


// Read function returns uart_t as high byte and number of bytes read as low byte
uint16_t uart_read(char *buf, uint8_t max_len){
    char data;
    uint8_t i = 0;
    uint16_t ret;

    while(i < max_len){
        ret = uart_recv_byte();
        while(ret >> 8){
            ret = uart_recv_byte();
        }

        // if(ret >> 8){
        //     return (ret | i);
        // }

        data = (char) (ret & 0xFF);
        buf[i] = data;
        i++;

        if(data == '\n' || data == '\r' || data == '\0'){
            break;
        }
    }

    return i;
}


void uart_flush(void){
    while(check_bit(USART1_STATR, USART1_RXNE)){
        reg_ptr(USART1_DATAR);
    }
}
