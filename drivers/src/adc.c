#include <adc.h>
#include <rcc.h>
#include <gpio.h>
#include <system_init.h>

#define GPIO_BASE GPIOA

void adc_init(void)
{
    
    rcc_enable_adc(1);
    rcc_enable_gpio(GPIOA_EN);
    gpio_set_mode(GPIOA_BASE, 3, 3);

    ADC_CR1(ADC1_BASE) &= ~ADC_CR1_RES;
    ADC_CR1(ADC1_BASE) |= (0 << 24);  //As we want it to be 12 bits

    ADC_CR2(ADC1_BASE) |= ADC_CR2_ADON;
    ADC_CR2(ADC1_BASE) &= ~ADC_CR2_ALIGN;

    ADC_CR2(ADC1_BASE) &= ~ADC_CR2_CONT;
    ADC_SMPR2(ADC1_BASE) |= (7 << 9);
    ADC_SQR3(ADC1_BASE) |= (3 << 0);
    ADC_SQR1(ADC1_BASE) |= (0 << 20);

}

uint16_t adc_read(void)
{

    while(1)
    {
        ADC_CR2(ADC1_BASE) |= ADC_CR2_SWSTART;
        while(!(ADC_SR(ADC1_BASE) & ADC_SR_EOC)); //Wait until conversion is complete
        return uint16_t(ADC_DR(ADC1_BASE));
    }
    
}





/* 

void gpio_set_mode(uint32_t base, uint32_t pin, uint32_t mode);
void gpio_toggle(uint32_t base, uint32_t pin);
void gpio_write(uint32_t base, uint32_t pin, uint32_t value);
uint32_t gpio_read(uint32_t base, uint32_t pin);

void rcc_enable_gpio(uint8_t port);
void rcc_disable_gpio(uint8_t port);
void rcc_enable_uart(uint8_t uart);
void rcc_disable_uart(uint8_t uart);

void system_init(void);
void systick_init(void);
void SysTick_Handler(void);

#define ADC_SR_EOC (1 << 1)
#define ADC_CR1_RES (3 << 24)
#define ADC_CR2_SWSTART (1 << 30)
#define ADC_CR2_ADON (1 << 0)
#define ADC_CR2_CONT (1 << 1)
*/
