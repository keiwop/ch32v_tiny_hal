
#ifndef 	__IO__
#define 	__IO__

#include <stdint.h>
#include <tiny_hal/registers.h>


#define reg_ptr(reg)            (*(volatile uint32_t *) (reg))

#define sbi(reg, bit)           (reg_ptr(reg) |= (1 << bit))
#define cbi(reg, bit)           (reg_ptr(reg) &= ~(1 << bit))
#define xbi(reg, bit)           (reg_ptr(reg) ^= (1 << bit))

#define gpio_ptr(base, pin)     (reg_ptr(base + (GPIO_BANK_OFFSET * (pin / 8))))
#define gpio_clear_cfg(pin)     (gpio_ptr(GPIO_CFGLR, pin) &= ~(0b1111 << ((pin % 8) * 4)))
#define gpio_set_cfg(pin, cfg)  (gpio_ptr(GPIO_CFGLR, pin) |= (cfg << ((pin % 8) * 4)))
#define gpio_out_pp_10MHz(pin)  gpio_set_cfg(pin, 0b0001)
#define gpio_out_pp_2MHz(pin)   gpio_set_cfg(pin, 0b0010)
#define gpio_out_pp_50MHz(pin)  gpio_set_cfg(pin, 0b0011)
#define gpio_out_mpp_10MHz(pin) gpio_set_cfg(pin, 0b1001)
#define gpio_out_mpp_2MHz(pin)  gpio_set_cfg(pin, 0b1010)
#define gpio_out_mpp_50MHz(pin) gpio_set_cfg(pin, 0b1011)
#define gpio_in_adc(pin)        gpio_set_cfg(pin, 0b0000)
#define gpio_in_float(pin)      gpio_set_cfg(pin, 0b0100)
#define gpio_in_pp(pin)         gpio_set_cfg(pin, 0b1000)

#define pin_set(pin)            (gpio_ptr(GPIO_BSHR, pin) = 1 << (pin % 8))
#define pin_clear(pin)          (gpio_ptr(GPIO_BCR, pin) = 1 << (pin % 8))
#define pin_toggle(pin)         (gpio_ptr(GPIO_OUTDR, pin) ^= 1 << (pin % 8))

#define pin_output(pin)         gpio_clear_cfg(pin); gpio_out_pp_10MHz(pin)
#define pin_input(pin)          gpio_clear_cfg(pin); gpio_in_pp(pin)
#define pin_input_adc(pin)      gpio_clear_cfg(pin); gpio_in_adc(pin)
#define pin_input_float(pin)    gpio_clear_cfg(pin); gpio_in_float(pin)
#define pin_pullup(pin)         pin_input(pin); pin_set(pin)
#define pin_pulldown(pin)       pin_input(pin); pin_clear(pin)

#define read_state(pin)         (gpio_ptr(GPIO_INDR, pin) & (1 << (pin % 8)))

#define pin_write(p, v)         if(v){ pin_set(p); } else{ pin_clear(p); }
#define pin_read(pin)           (read_state(pin) >> (pin % 8))

// #define pin_read_adc(pin)   (adc_read_pin(pin))


#endif // __IO__
