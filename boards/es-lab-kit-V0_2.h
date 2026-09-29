/**
 * Board description for ES-Lab-Kit V0.2
 */

#ifndef _BOARDS_ES_LAB_KIT_V0_2_H
#define _BOARDS_ES_LAB_KIT_V0_2_H

pico_board_cmake_set(PICO_PLATFORM, rp2350)

// For board detection
#define ES_LAB_KIT_V0_2

// --- RP2350 VARIANT ---
#define PICO_RP2350A 0

// --- UART ---
#ifndef PICO_DEFAULT_UART
#define PICO_DEFAULT_UART 0
#endif
#ifndef PICO_DEFAULT_UART_TX_PIN
#define PICO_DEFAULT_UART_TX_PIN 0
#endif
#ifndef PICO_DEFAULT_UART_RX_PIN
#define PICO_DEFAULT_UART_RX_PIN 1
#endif

// --- LED ---
#ifndef PICO_DEFAULT_LED_PIN
#define PICO_DEFAULT_LED_PIN 25
#endif

// --- I2C ---
#ifndef PICO_DEFAULT_I2C
#define PICO_DEFAULT_I2C 0
#endif
#ifndef PICO_DEFAULT_I2C_SDA_PIN
#define PICO_DEFAULT_I2C_SDA_PIN 4
#endif
#ifndef PICO_DEFAULT_I2C_SCL_PIN
#define PICO_DEFAULT_I2C_SCL_PIN 5
#endif

// --- SPI ---
#ifndef PICO_DEFAULT_SPI
#define PICO_DEFAULT_SPI 0
#endif
#ifndef PICO_DEFAULT_SPI_SCK_PIN
#define PICO_DEFAULT_SPI_SCK_PIN 18
#endif
#ifndef PICO_DEFAULT_SPI_TX_PIN
#define PICO_DEFAULT_SPI_TX_PIN 19
#endif
#ifndef PICO_DEFAULT_SPI_RX_PIN
#define PICO_DEFAULT_SPI_RX_PIN 16
#endif
#ifndef PICO_DEFAULT_SPI_CSN_PIN
#define PICO_DEFAULT_SPI_CSN_PIN 17
#endif

// --- FLASH ---

#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1

#ifndef PICO_FLASH_SPI_CLKDIV
#define PICO_FLASH_SPI_CLKDIV 2
#endif

pico_board_cmake_set_default(PICO_FLASH_SIZE_BYTES, (16 * 1024 * 1024))
#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (16 * 1024 * 1024)
#endif
// Drive high to force power supply into PWM mode (lower ripple on 3V3 at light loads)
#define PICO_SMPS_MODE_PIN 23

pico_board_cmake_set_default(PICO_RP2350_A2_SUPPORTED, 1)
#ifndef PICO_RP2350_A2_SUPPORTED
#define PICO_RP2350_A2_SUPPORTED 1
#endif

/**
 * @brief CS pin of the PSRAM chip.
 */
#define PSRAM_CS    8

/**
 * @brief LEDs directly connected to the MCU.
 */
#define LED_GREEN   25
#define LED_YELLOW  24
#define LED_RED     23

/**
 * @brief I2C pins used.
 */
#define I2C_SDA     20
#define I2C_SCL     21
#define I2C_PORT    i2c0

/**
 * @brief Shift register.
 */
#define SR_OE       37
#define SR_SD       35
#define SR_SHCP     39
#define SR_STCP     36
#define SPI_PORT    spi1
#define SR_MR    39

/**
 * @brief Push buttons.
 */
#define SW_5        22
#define SW_6        15
#define SW_7        16
#define SW_8        17

/**
 * @brief Switches.
 */
#define SW_10     26
#define SW_11     27
#define SW_12     28
#define SW_13     29
#define SW_14     30
#define SW_15     31
#define SW_16     13
#define SW_17     14

/**
 * @brief Interrupt pins of the accelerometer (main connection via I2C).
 */
#define ACC_INT1    18
#define ACC_INT2    19

#endif  //_BOARDS_ES_LAB_KIT_V0_2_H