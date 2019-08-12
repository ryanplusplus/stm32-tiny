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

void reset_handler(void) {
  uint32_t* source = &_data_rom;

  for(uint32_t* destination = &_data_begin; destination < &_data_end;) {
    *(destination++) = *(source++);
  }

  for(uint32_t* destination = &_bss_begin; destination < &_bss_end;) {
    *(destination++) = 0;
  }

  main();
}

void default_handler(void) {
  while(1) {
  }
}

// Cortex-M4
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
void WDT_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RTC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void MCIA_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void MCIB_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void UART0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void UART1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void UART2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void UART4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void AACI_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void CLCD_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void ENET_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USBDC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USBHC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void CHLCD_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FLEXRAY_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void CAN_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void LIN_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void CPU_CLCD_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void UART3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI_IRQHandler(void) __attribute__((weak, alias("default_handler")));

typedef void (*vector_t)(void);

const vector_t vector_table[] __attribute__((section(".vectors"))) = {
  // Cortex-M4
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
  WDT_IRQHandler,
  RTC_IRQHandler,
  TIM0_IRQHandler,
  TIM2_IRQHandler,
  MCIA_IRQHandler,
  MCIB_IRQHandler,
  UART0_IRQHandler,
  UART1_IRQHandler,
  UART2_IRQHandler,
  UART4_IRQHandler,
  AACI_IRQHandler,
  CLCD_IRQHandler,
  ENET_IRQHandler,
  USBDC_IRQHandler,
  USBHC_IRQHandler,
  CHLCD_IRQHandler,
  FLEXRAY_IRQHandler,
  CAN_IRQHandler,
  LIN_IRQHandler,
  I2C_IRQHandler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  CPU_CLCD_IRQHandler,
  0,
  UART3_IRQHandler,
  SPI_IRQHandler
};
