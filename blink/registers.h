
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
#define MCO             (24)    // 3 bits
#define HPRE            (4)     // 4 bits

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

// APB2PCENR
#define PWREN           (28)
#define I2C1EN          (21)
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


#endif // __REGISTERS__
