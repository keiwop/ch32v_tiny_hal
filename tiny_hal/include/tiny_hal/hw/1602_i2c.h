
#ifndef     __1602_I2C__
#define     __1602_I2C__


#include <tiny_hal/io.h>
#include <tiny_hal/delay.h>
#include <tiny_hal/i2c.h>


#ifndef I2C_ADDR_1602
    #define I2C_ADDR_1602   (0b0100111)
#endif

#define LCD16_RS    (0) // Register Select (0 for sending cmd, 1 for writing char to screen)
#define LCD16_RW    (1) // Read / Write (never reading from target so set as 0)
#define LCD16_EN    (2) // Enable (set high after sending address to target, then low when sending i2c stop condition)
#define LCD16_BL    (3) // Backlight On / Off

#define LCD16_CHAR_WIDTH (5)



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
    #define lcd16_printf(...)     sprintf(printf_buf, __VA_ARGS__); lcd16_print(printf_buf)
#endif


extern uint8_t lcd16_flags;


void lcd16_send_data_i2c(uint8_t nibble);
void lcd16_send_data(uint8_t nibble);
void lcd16_send_byte(uint8_t byte);
void lcd16_print_char(uint8_t byte);
void lcd16_print(char *str);
void lcd16_set_backlight(uint8_t turn_on);
void lcd16_clear();
void lcd16_home();
void lcd16_set_entry();
void lcd16_scroll_left();
void lcd16_scroll_right();
void lcd16_move_cursor(uint8_t x, uint8_t y);
void lcd16_create_char(uint8_t id, const uint8_t *array);
void lcd16_print_progress(uint16_t current, uint16_t start, uint16_t stop, uint8_t width);
void lcd16_init();


#endif // __1602_I2C__
