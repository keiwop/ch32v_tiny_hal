
#ifndef     __1602_I2C__
#define     __1602_I2C__


#include <tiny_hal/io.h>
#include <tiny_hal/delay.h>
#include <tiny_hal/i2c.h>


#ifndef I2C_ADDR_1602
    #define I2C_ADDR_1602   (0b0100111)
#endif

#define BIT_RS 	    (0b0001)
#define BIT_RW 	    (0b0010)
#define BIT_EN      (0b0100)
#define BIT_BL      (0b1000)

#define CHAR_HEIGHT (8)
#define CHAR_WIDTH  (5)


#ifdef ENABLE_1602_I2C

#ifdef ENABLE_1602_CUSTOM_CHAR
    extern const uint8_t char_happy[8];
    extern const uint8_t char_sad[8];
    extern const uint8_t char_celsius[8];
    extern const uint8_t char_hot1[8];
    extern const uint8_t char_hot2[8];
    extern const uint8_t char_arrow_l[8];
    extern const uint8_t char_arrow_r[8];
#endif


#ifdef ENABLE_1602_PROGRESS
    extern const uint8_t char_progress_1[8];
    extern const uint8_t char_progress_2[8];
    extern const uint8_t char_progress_3[8];
    extern const uint8_t char_progress_4[8];
#endif


#ifdef ENABLE_PRINTF
	#define lcd_printf(...) 	sprintf(printf_buf, __VA_ARGS__); lcd_print(printf_buf)
#endif

#endif // ENABLE_1602_I2C

extern uint8_t lcd_rs;
extern uint8_t lcd_rw;
extern uint8_t lcd_bl;

void lcd_send_data(uint8_t nibble);
void lcd_send_byte(uint8_t byte);
void lcd_print_char(uint8_t byte);
void lcd_print(char *str);
void lcd_clear();
void lcd_home();
void lcd_set_entry();
void lcd_scroll_left();
void lcd_scroll_right();
void lcd_move_cursor(uint8_t x, uint8_t y);
void lcd_create_char(uint8_t id, const uint8_t *array);
void lcd_print_progress(uint16_t current, uint16_t start, uint16_t stop, uint8_t width);
void lcd_init();



#endif // __1602_I2C__
