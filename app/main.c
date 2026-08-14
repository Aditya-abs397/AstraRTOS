#include <stdint.h>
#include "adc.h"
#include "rcc.h"
#include "gpio.h"
#include "system_init.h"
#include "uart.h"
#include "task.h"
#include "heap.h"

#define UART_BASE USART1_BASE

static void adc_test_task(void) {
    while(1) {
        uart_send_string(UART_BASE, "alive\r\n");
        os_delay(100);
    }
}

int main(void) {
    system_init();
    uart_init(UART_BASE);
    os_heap_init();
    adc_init();
    uart_send_string(UART_BASE, "adc_init() returned without fault.\r\n");
    os_task_create(adc_test_task, 1, 128);
    os_start();

    return 0;
}
