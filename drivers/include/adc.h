#ifndef ADC_H
#define ADC_H

#include <stdint.h>

#define ADC1_BASE 0x40012000

#define ADC_SR(base) (*(volatile uint32_t *)((base) + 0x00))
#define ADC_CR1(base) (*(volatile uint32_t *)((base) + 0x04))
#define ADC_CR2(base) (*(volatile uint32_t *)((base) + 0x08))
#define ADC_SMPR1(base) (*(volatile uint32_t *)((base) + 0x0C))
#define ADC_SMPR2(base) (*(volatile uint32_t *)((base) + 0x10))
#define ADC_SQR1(base) (*(volatile uint32_t *)((base) + 0x2C))
#define ADC_SQR2(base) (*(volatile uint32_t *)((base) + 0x30))
#define ADC_SQR3(base) (*(volatile uint32_t *)((base) + 0x34))
#define ADC_DR(base) (*(volatile uint32_t *)((base) + 0x4C))

#define ADC_SR_EOC (1 << 1)
#define ADC_CR1_RES (3 << 24)
#define ADC_CR2_SWSTART (1 << 30)
#define ADC_CR2_ADON (1 << 0)
#define ADC_CR2_CONT (1 << 1)
#define ADC_CR2_ALIGN (1 << 11)

void adc_init();
#endif
