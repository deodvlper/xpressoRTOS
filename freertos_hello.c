/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
//#include "fsl_gpio.h"

#include "pin_mux.h"
#include <stdbool.h>
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Task priorities. */
#define hello_task_PRIORITY (configMAX_PRIORITIES - 1)

//DEFINE THE COM LIGHT LED --> PTB0 FROM THE PINMUX STUFF
#define BOARD_LED_COM_GPIO GPIOB
#define BOARD_LED_COM_GPIO_PIN 0U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void hello_task(void *pvParameters);
static void hi_task(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */
int main(void)
{
    /* Init board hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /*INIT LED*/
    gpio_pin_config_t led_config = {
		kGPIO_DigitalOutput, 0,
    };

    GPIO_PinInit(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, &led_config);
    GPIO_PinInit(BOARD_LED_COM_GPIO, BOARD_LED_COM_GPIO_PIN, &led_config); //NOTE: PTB0 == PORTB PIN 0

    /*CREATE 2 TASKS*/
    xTaskCreate(hello_task, "Hello_task", configMINIMAL_STACK_SIZE, NULL, hello_task_PRIORITY, NULL);
    xTaskCreate(hi_task, "Hi_task", configMINIMAL_STACK_SIZE, NULL, hello_task_PRIORITY, NULL); //same priority as hello_task
    vTaskStartScheduler();
    for (;;)
        ;
}

//LED BLINK TASKS

static void hello_task(void *pvParameters)
{
    while(1)
    {
        //PRINTF("WTF?\r\n");
        //GPIO_TogglePinsOutput(BOARD_LED_BLUE_GPIO, 1u << BOARD_LED_BLUE_GPIO_PIN);
    	GPIO_WritePinOutput(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, 0);
        vTaskDelay(1000);
        //GPIO_TogglePinsOutput(BOARD_LED_BLUE_GPIO, 1u << BOARD_LED_BLUE_GPIO_PIN);
        GPIO_WritePinOutput(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, 1);
        vTaskDelay(1000);
        //vTaskSuspend(NULL);
    }
}

static void hi_task(void *pvParameters)
{
	while(1)
	{
        //GPIO_TogglePinsOutput(BOARD_LED_COM_GPIO, 1u << BOARD_LED_COM_GPIO_PIN);
		GPIO_WritePinOutput(BOARD_LED_COM_GPIO, BOARD_LED_COM_GPIO_PIN, 0);
		vTaskDelay(500);
        //GPIO_TogglePinsOutput(BOARD_LED_COM_GPIO, 1u << BOARD_LED_COM_GPIO_PIN);
		GPIO_WritePinOutput(BOARD_LED_COM_GPIO, BOARD_LED_COM_GPIO_PIN, 1);
		vTaskDelay(500);
	}
}
