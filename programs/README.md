# tiny_hal  

You can use definition flags to enable or customize features of this HAL.  
Examples are provided in the programs makefiles.  
A list of all available configuration flags and their default values is shown below.  

Here's how to use them:  
```
DEFINES := -DF_CPU=24000000UL -DENABLE_UART -DUART_BAUDRATE=115200 -DENABLE_PRINTF -DPRINTF_BUF_SIZE=80
```

The various **ENABLE_X** are used to set up the hardware in ``tiny_hal/init.c``.  
They are also used in the corresponding sources to set up global variables or hardware specific configuration.  

The logging works in a way that it will display all logs with a priority below or equal to its value.  
For example, if **LOG_LEVEL** is defined to 0, all log messages will be replaced by a nop(). If set to 2, it will display all logs with priority 1 or 2.
You can get more information about it in ``tiny_hal/debug.h``

**PROTO_TIMEOUT** is used to detect communications timeouts in protocols such as I2C, UART or SPI. It is defined as a number of CPU cycles and not a unit of time.


## Available configuration flags:  

Board:  
- **F_CPU**=24000000UL
- **PIN_LED_BOARD**=PC3
- **PROTO_TIMEOUT**=1000000UL

Newlib-nano printf:  
- **ENABLE_PRINTF**
- **PRINTF_BUF_SIZE**=80

Logging:  
- **LOG_LEVEL**=42
- **LOG_BUF_SIZE**=80

UART:  
- **ENABLE_UART**
- **UART_BAUDRATE**=115200
- **PIN_UART_TX**=PD5
- **PIN_UART_RX**=PD6

I2C:  
- **ENABLE_I2C**
- **PIN_I2C_SDA**=PC1
- **PIN_I2C_SCL**=PC2

1602 LCD:  
- **ENABLE_1602_I2C**
- **I2C_ADDR_1602**=0b0100111
