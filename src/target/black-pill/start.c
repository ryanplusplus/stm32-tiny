/*!
 * @file
 * @brief
 */

#include <stdint.h>

extern uint32_t _data_rom;
extern uint32_t _data_begin;
extern uint32_t _data_end;
extern uint32_t _bss_begin;
extern uint32_t _bss_end;
extern uint32_t _stack_top;

extern void main(void);

void reset_handler(void)
{
  uint32_t* source = &_data_rom;

  for(uint32_t* destination = &_data_begin; destination < &_data_end;) {
    *(destination++) = *(source++);
  }

  for(uint32_t* destination = &_bss_begin; destination < &_bss_end;) {
    *(destination++) = 0;
  }

  main();
}

void default_handler(void)
{
  while(1) {
  }
}

// Cortex-M3
void NMI_Handler(void) __attribute__((weak, alias("default_handler")));
void HardFault_Handler(void) __attribute__((weak, alias("default_handler")));
void MemManage_Handler(void) __attribute__((weak, alias("default_handler")));
void BusFault_Handler(void) __attribute__((weak, alias("default_handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("default_handler")));
void SVC_Handler(void) __attribute__((weak, alias("default_handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("default_handler")));
void PendSV_Handler(void) __attribute__((weak, alias("default_handler")));
void SysTick_Handler(void) __attribute__((weak, alias("default_handler")));

// Peripherals
void WWDG_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void PVD_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TAMP_STAMP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RTC_WKUP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FLASH_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Stream0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Stream1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Stream2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Stream3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Stream4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Stream5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Stream6_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void ADC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_BRK_TIM9_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_UP_TIM10_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RTC_Alarm_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void OTG_FS_WKUP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Stream7_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SDIO_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Stream0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Stream1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Stream2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Stream3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Stream4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void OTG_FS_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Stream5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Stream6_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Stream7_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USART6_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C3_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C3_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FPU_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI4_IRQHandler(void) __attribute__((weak, alias("default_handler")));

typedef void (*vector_t)(void);

const vector_t vector_table[] __attribute__((section(".vectors"))) = {
  // Cortex-M3
  (vector_t)&_stack_top,
  reset_handler,
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0,
  0,
  0,
  0,
  SVC_Handler,
  DebugMon_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler,

  // Peripherals
  WWDG_IRQHandler,
  PVD_IRQHandler,
  TAMP_STAMP_IRQHandler,
  RTC_WKUP_IRQHandler,
  FLASH_IRQHandler,
  RCC_IRQHandler,
  EXTI0_IRQHandler,
  EXTI1_IRQHandler,
  EXTI2_IRQHandler,
  EXTI3_IRQHandler,
  EXTI4_IRQHandler,
  DMA1_Stream0_IRQHandler,
  DMA1_Stream1_IRQHandler,
  DMA1_Stream2_IRQHandler,
  DMA1_Stream3_IRQHandler,
  DMA1_Stream4_IRQHandler,
  DMA1_Stream5_IRQHandler,
  DMA1_Stream6_IRQHandler,
  ADC_IRQHandler,
  0,
  0,
  0,
  0,
  EXTI9_5_IRQHandler,
  TIM1_BRK_TIM9_IRQHandler,
  TIM1_UP_TIM10_IRQHandler,
  TIM1_TRG_COM_TIM11_IRQHandler,
  TIM1_CC_IRQHandler,
  TIM2_IRQHandler,
  TIM3_IRQHandler,
  TIM4_IRQHandler,
  I2C1_EV_IRQHandler,
  I2C1_ER_IRQHandler,
  I2C2_EV_IRQHandler,
  I2C2_ER_IRQHandler,
  SPI1_IRQHandler,
  SPI2_IRQHandler,
  USART1_IRQHandler,
  USART2_IRQHandler,
  0,
  EXTI15_10_IRQHandler,
  RTC_Alarm_IRQHandler,
  OTG_FS_WKUP_IRQHandler,
  0,
  0,
  0,
  0,
  DMA1_Stream7_IRQHandler,
  0,
  SDIO_IRQHandler,
  TIM5_IRQHandler,
  SPI3_IRQHandler,
  0,
  0,
  0,
  0,
  DMA2_Stream0_IRQHandler,
  DMA2_Stream1_IRQHandler,
  DMA2_Stream2_IRQHandler,
  DMA2_Stream3_IRQHandler,
  DMA2_Stream4_IRQHandler,
  0,
  0,
  0,
  0,
  0,
  0,
  OTG_FS_IRQHandler,
  DMA2_Stream5_IRQHandler,
  DMA2_Stream6_IRQHandler,
  DMA2_Stream7_IRQHandler,
  USART6_IRQHandler,
  I2C3_EV_IRQHandler,
  I2C3_ER_IRQHandler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  FPU_IRQHandler,
  0,
  0,
  SPI4_IRQHandler
};
