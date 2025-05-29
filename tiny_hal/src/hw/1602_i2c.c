
#include <tiny_hal/hw/1602_i2c.h>


uint8_t lcd16_flags;


#ifdef ENABLE_1602_CUSTOM_CHAR
	const uint8_t char_happy[8] 	= {0b00001, 0b00011, 0b00111, 0b01111, 0b11111, 0b11110, 0b11100, 0b11000};
	const uint8_t char_sad[8] 		= {0b00000, 0b00000, 0b00100, 0b11000, 0b00000, 0b00000, 0b00110, 0b00000};
	const uint8_t char_celsius[8] 	= {0b11011, 0b11100, 0b00100, 0b00011, 0b00000, 0b00000, 0b00000, 0b00000};
	const uint8_t char_hot1[8] 		= {0b01001, 0b10010, 0b01001, 0b10010, 0b00000, 0b00000, 0b11111, 0b00000};
	const uint8_t char_hot2[8] 		= {0b10010, 0b01001, 0b10010, 0b01001, 0b00000, 0b00000, 0b11111, 0b00000};
	const uint8_t char_arrow_l[8] 	= {0b00000, 0b00100, 0b01000, 0b11111, 0b01000, 0b00100, 0b00000, 0b00000};
	const uint8_t char_arrow_r[8] 	= {0b00000, 0b00100, 0b00010, 0b11111, 0b00010, 0b00100, 0b00000, 0b00000};
#endif
// const uint8_t PROGMEM char_empty[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000};

#ifdef ENABLE_1602_PROGRESS
	const uint8_t char_progress_1[8] = {0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000};
	const uint8_t char_progress_2[8] = {0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000};
	const uint8_t char_progress_3[8] = {0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100};
	const uint8_t char_progress_4[8] = {0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110};
#endif



void lcd16_send_data_i2c(uint8_t nibble){
    uint8_t byte = nibble << 4 | lcd16_flags;

	i2c_send_byte(I2C_ADDR_1602, 1, 0);
    
    i2c_send_byte(byte | (1 << LCD16_EN), 0, 0);
    delay_us(1);
    
    i2c_send_byte(byte & ~(1 << LCD16_EN), 0, 1);
    delay_us(50);
}


// TODO
void lcd16_send_data(uint8_t nibble){
    nop();
}


#ifdef ENABLE_1602_I2C
void lcd16_send_byte(uint8_t byte){
	lcd16_send_data_i2c(byte >> 4);
	lcd16_send_data_i2c(byte & 0x0F);
}
#else
void lcd16_send_byte(uint8_t byte){
	lcd16_send_data(byte >> 4);
	lcd16_send_data(byte & 0x0F);
}
#endif


void lcd16_print_char(uint8_t byte){
	lcd16_flags |= (1 << LCD16_RS);
	lcd16_send_byte(byte);
	lcd16_flags &= ~(1 << LCD16_RS);
}


void lcd16_print(char *str){
    uint8_t i = 0;
    while(str[i] != '\0'){
        lcd16_print_char(str[i++]);
    }
}


void lcd16_set_backlight(uint8_t turn_on){
    if(turn_on){
        lcd16_flags |= (1 << LCD16_BL);
    }
    else{
        lcd16_flags &= ~(1 << LCD16_BL);
    }
}


void lcd16_clear(){
	lcd16_send_byte(0b1);
	delay_ms(2);
}


void lcd16_home(){
	lcd16_send_byte(0b10);
	delay_ms(2);
}


void lcd16_set_entry(){
	lcd16_send_byte(0b110);
}


void lcd16_scroll_left(){
    lcd16_send_byte(0b11000);
}


void lcd16_scroll_right(){
    lcd16_send_byte(0b11100);
}


void lcd16_move_cursor(uint8_t x, uint8_t y){
    lcd16_send_byte(1 << 7 | (x + (0x40 * y)));
}


void lcd16_create_char(uint8_t id, const uint8_t *array){
    uint8_t i;
    lcd16_send_byte(1 << 6 | id << 3); // Write to custom char address in GCRAM | id between 0-7

    for(i = 0; i < 8; ++i){
        lcd16_print_char(array[i]);
    }
}


void lcd16_print_progress(uint16_t current, uint16_t start, uint16_t stop, uint8_t width){
	if(current < start || current > stop){
		return;
	}
	
	uint16_t total = diff(start, stop);
	uint16_t value = current;

	if(total < (LCD16_CHAR_WIDTH * width)){
		total *= 100;
		value *= 100;
	}

	uint16_t total_per_char = (total / width);

	uint8_t current_char = (uint8_t) ((width * value) / total);
	uint8_t current_column = (uint8_t) ((LCD16_CHAR_WIDTH * (value - (current_char * total_per_char))) / total_per_char);

	lcd16_move_cursor(0, 0);
	// log_l(5, "%d | %d | %d", current, current_char, current_column);
	lcd16_move_cursor(0, 1);

	if(current_column == 5){
		lcd16_print_char(0xff);
	}
}


// I don't really know the init sequence of the screen but it works
void lcd16_init(){
	delay_ms(50);

	lcd16_send_data(0);
	delay_ms(100);
    
	lcd16_send_data(0b0011);
	delay_ms(5);
    
	lcd16_send_data(0b0011);
	delay_ms(5);
    
	lcd16_send_data(0b0011);
	delay_ms(5);

	lcd16_send_data(0b0010); // Enable 4-bit mode
	lcd16_send_byte(0b00001100); // Display all ON without cursor
    lcd16_set_backlight(1);
	lcd16_clear();
}
