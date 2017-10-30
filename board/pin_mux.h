#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* PORTC6 (number 42), J1[1]/D0/UART0_RX_TGTMCU */
#define BOARD_INITPINS_DEBUG_UART_RX_PERIPHERAL                          LPUART0   /*!< Device name: LPUART0 */
#define BOARD_INITPINS_DEBUG_UART_RX_SIGNAL                                   RX   /*!< LPUART0 signal: RX */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN_NAME                           UART0_RX   /*!< Pin name */
#define BOARD_INITPINS_DEBUG_UART_RX_LABEL            "J1[1]/D0/UART0_RX_TGTMCU"   /*!< Label */
#define BOARD_INITPINS_DEBUG_UART_RX_NAME                        "DEBUG_UART_RX"   /*!< Identifier name */

/* PORTC7 (number 43), J1[2]/D1/UART0_TX_TGTMCU */
#define BOARD_INITPINS_DEBUG_UART_TX_PERIPHERAL                          LPUART0   /*!< Device name: LPUART0 */
#define BOARD_INITPINS_DEBUG_UART_TX_SIGNAL                                   TX   /*!< LPUART0 signal: TX */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN_NAME                           UART0_TX   /*!< Pin name */
#define BOARD_INITPINS_DEBUG_UART_TX_LABEL            "J1[2]/D1/UART0_TX_TGTMCU"   /*!< Label */
#define BOARD_INITPINS_DEBUG_UART_TX_NAME                        "DEBUG_UART_TX"   /*!< Identifier name */

/* PORTA18 (number 6), J2[6]/D13/RGB_BLUE */
#define BOARD_INITPINS_LED_BLUE_GPIO                                       GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_INITPINS_LED_BLUE_PORT                                       PORTA   /*!< PORT device name: PORTA */
#define BOARD_INITPINS_LED_BLUE_GPIO_PIN                                     18U   /*!< PORTA pin index: 18 */
#define BOARD_INITPINS_LED_BLUE_PIN_NAME                                   PTA18   /*!< Pin name */
#define BOARD_INITPINS_LED_BLUE_LABEL                       "J2[6]/D13/RGB_BLUE"   /*!< Label */
#define BOARD_INITPINS_LED_BLUE_NAME                                  "LED_BLUE"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
