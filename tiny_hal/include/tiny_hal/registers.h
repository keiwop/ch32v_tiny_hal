
#ifndef 	__REGISTERS__
#define 	__REGISTERS__


///////////////////////////////////////////////////////////////////////////////
// Clock //////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define RCC_BASE        (0x40021000)
#define RCC_CTRL        (RCC_BASE + 0x00)   // Clock control register
#define RCC_CFGR0       (RCC_BASE + 0x04)   // Clock configuration register 0
#define RCC_INTR        (RCC_BASE + 0x08)   // Clock interrupt register
#define RCC_APB2PRSTR   (RCC_BASE + 0x0C)   // PB2 peripheral reset register
#define RCC_APB1PRSTR   (RCC_BASE + 0x10)   // PB1 peripheral reset register
#define RCC_AHBPCENR    (RCC_BASE + 0x14)   // HB peripheral clock enable register
#define RCC_APB2PCENR   (RCC_BASE + 0x18)   // PB2 peripheral clock enable register
#define RCC_APB1PCENR   (RCC_BASE + 0x1C)   // PB1 peripheral clock enable register
#define RCC_RSTSCKR     (RCC_BASE + 0x24)   // Control/Status register

// CFGR0
#define RCC_MCO         (24)    // 3 bits
#define HPRE            (4)     // 4 bits

// APB1PRSTR
#define RCC_I2C1RST     (21)
#define RCC_TIM2RST     (0)

// APB2PRSTR
#define RCC_SPI1RST     (12)
#define RCC_TIM1RST     (11)

// AHBPCENR
#define SRAMEN          (2)
#define DMA1EN          (0)

// APB2PCENR
#define USART1EN        (14)
#define SPI1EN          (12)
#define TIM1EN          (11)
#define ADC1EN          (9)
#define IOPDEN          (5)
#define IOPCEN          (4)
#define IOPAEN          (2)
#define AFIOEN          (0)

// APB1PCENR
#define PWREN           (28)
#define RCC_I2C1EN      (21)
#define WWDGEN          (11)
#define TIM2EN          (0)

// RSTSCKR
#define RMVF            (24)
#define LSIRDY          (1)
#define LSION           (0)


///////////////////////////////////////////////////////////////////////////////
// GPIO ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define GPIO_BASE           (0x40010800)
#define GPIO_BANK_OFFSET    (0x0400)
#define GPIO_CFGLR          (GPIO_BASE + 0x0000)    // Port configuration register low
#define GPIO_INDR           (GPIO_BASE + 0x0008)    // Port input data register
#define GPIO_OUTDR          (GPIO_BASE + 0x000C)    // Port output data register
#define GPIO_BSHR           (GPIO_BASE + 0x0010)    // Port set/reset register
#define GPIO_BCR            (GPIO_BASE + 0x0014)    // Port reset register
#define GPIO_LCKR           (GPIO_BASE + 0x0018)    // Port configuration lock register

// By laying the GPIO pins this way we can do pin % 8 to find out its number between 0-7
// And by doing pin / 8 we get the GPIO bank it's part of, between 0-3
#define PD7             (31)
#define PD6             (30)
#define PD5             (29)
#define PD4             (28)
#define PD3             (27)
#define PD2             (26)
#define PD1             (25)
#define PD0             (24)
#define PC7             (23)
#define PC6             (22)
#define PC5             (21)
#define PC4             (20)
#define PC3             (19)
#define PC2             (18)
#define PC1             (17)
#define PC0             (16)
#define PB7             (15)
#define PB6             (14)
#define PB5             (13)
#define PB4             (12)
#define PB3             (11)
#define PB2             (10)
#define PB1             (9)
#define PB0             (8)
#define PA7             (7)
#define PA6             (6)
#define PA5             (5)
#define PA4             (4)
#define PA3             (3)
#define PA2             (2)
#define PA1             (1)
#define PA0             (0)


///////////////////////////////////////////////////////////////////////////////
// AFIO ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define AFIO_PCFR1      (0x40010004)    // Remap register 1
#define AFIO_EXTICR     (0x40010008)    // External interrupt configuration register 1

// PCFR1
#define SWDCFG          (24)    // 3 bits
#define TIM1_IRM        (23)
#define I2C1_RM_H       (22)    // 2 bits with I2C1_RM_L
#define USART1_RM_H     (21)    // 2 bits with USART1_RM_L
#define ADC_ETRGREG_RM  (18)
#define ADC_ETRGINJ_RM  (17)
#define PA12_RM         (15)
#define TIM2_RM         (8)     // 2 bits
#define TIM1_RM         (6)     // 2 bits
#define USART1_RM_L     (2)
#define I2C1_RM_L       (1)
#define SPI1_RM         (0)


///////////////////////////////////////////////////////////////////////////////
// I2C ////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define I2C1_BASE       (0x40005400)
#define I2C1_CTRLR1     (I2C1_BASE + 0x0000) // I2C control register 1
#define I2C1_CTRLR2     (I2C1_BASE + 0x0004) // I2C control register 2
#define I2C1_OADDR1     (I2C1_BASE + 0x0008) // I2C address register 1
#define I2C1_OADDR2     (I2C1_BASE + 0x000C) // I2C address register 2
#define I2C1_DATAR      (I2C1_BASE + 0x0010) // I2C data register
#define I2C1_STAR1      (I2C1_BASE + 0x0014) // I2C status register 1
#define I2C1_STAR2      (I2C1_BASE + 0x0018) // I2C status register 2
#define I2C1_CKCFGR     (I2C1_BASE + 0x001C) // I2C clock register

// I2C1_CTRLR1
#define I2C1_SWRST      (15)
// #define I2C1_PEC        (12)
// #define I2C1_POS        (11)
#define I2C1_ACK        (10)
#define I2C1_STOP       (9)
#define I2C1_START      (8)
// #define I2C1_NOSTRETCH  (7)
// #define I2C1_ENGC       (6)
// #define I2C1_ENPEC      (5)
#define I2C1_PE         (0)

// I2C1_CTRLR2
#define I2C1_FREQ       (0) // 6 bits

// I2C1_DATAR
#define I2C1_DR         (0) // 8 bits

// I2C1_STAR1
#define I2C1_AF         (10)
#define I2C1_ARLO       (9)
#define I2C1_BERR       (8)
#define I2C1_TXE        (7)
#define I2C1_RXNE       (6)
#define I2C1_STOPF      (4)
#define I2C1_BTF        (2)
#define I2C1_ADDR       (1)
#define I2C1_SB         (0)

// I2C1_STAR2
#define I2C1_TRA        (2)
#define I2C1_BUSY       (1)
#define I2C1_MSL        (0)

// I2C1_CKCFGR
#define I2C1_FS         (15)
#define I2C1_DUTY       (14)
#define I2C1_CCR        (0) // 12 bits


#endif // __REGISTERS__
