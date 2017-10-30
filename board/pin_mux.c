/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: MKW41Z512xxx4
package_id: MKW41Z512VHT4
mcu_data: ksdk2_0
processor_version: 2.0.1
board: FRDM-KW41Z
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

/*FUNCTION**********************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 *END**************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */
#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port */
#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port */
#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */
#define SOPT5_LPUART0RXSRC_LPUART_RX  0x00u   /*!< LPUART0 Receive Data Source Select: LPUART_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX  0x00u   /*!< LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '42', peripheral: LPUART0, signal: RX, pin_signal: TSI0_CH2/PTC6/LLWU_P14/XTAL_OUT_EN/I2C1_SCL/UART0_RX/TPM2_CH0/BSM_FRAME}
  - {pin_num: '43', peripheral: LPUART0, signal: TX, pin_signal: TSI0_CH3/PTC7/LLWU_P15/SPI0_PCS2/I2C1_SDA/UART0_TX/TPM2_CH1/BSM_DATA}
  - {pin_num: '6', peripheral: GPIOA, signal: 'GPIO, 18', pin_signal: TSI0_CH12/PTA18/LLWU_P6/SPI1_SCK/TPM2_CH0}
  - {pin_num: '16', peripheral: GPIOB, signal: 'GPIO, 0', pin_signal: PTB0/LLWU_P8/XTAL_OUT_EN/I2C0_SCL/CMP0_OUT/TPM0_CH1/CLKOUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN18_IDX, kPORT_MuxAsGpio);         /* PORTA18 (pin 6) is configured as PTA18 */
  PORT_SetPinMux(PORTB, PIN0_IDX, kPORT_MuxAsGpio);          /* PORTB0 (pin 16) is configured as PTB0 */
  PORT_SetPinMux(PORTC, PIN6_IDX, kPORT_MuxAlt4);            /* PORTC6 (pin 42) is configured as UART0_RX */
  PORT_SetPinMux(PORTC, PIN7_IDX, kPORT_MuxAlt4);            /* PORTC7 (pin 43) is configured as UART0_TX */
  SIM->SOPT5 = ((SIM->SOPT5 &
    (~(SIM_SOPT5_LPUART0TXSRC_MASK | SIM_SOPT5_LPUART0RXSRC_MASK))) /* Mask bits to zero which are setting */
      | SIM_SOPT5_LPUART0TXSRC(SOPT5_LPUART0TXSRC_LPUART_TX) /* LPUART0 Transmit Data Source Select: LPUART0_TX pin */
      | SIM_SOPT5_LPUART0RXSRC(SOPT5_LPUART0RXSRC_LPUART_RX) /* LPUART0 Receive Data Source Select: LPUART_RX pin */
    );
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
