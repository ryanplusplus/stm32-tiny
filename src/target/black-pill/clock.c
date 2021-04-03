/*!
 * @file
 * @brief
 */

#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_system.h"
#include "clock.h"

// /**
//   * @brief  System Clock Configuration
//   *         The system Clock is configured as follow :
//   *            System Clock source            = PLL (HSE)
//   *            SYSCLK(Hz)                     = 84000000
//   *            HCLK(Hz)                       = 84000000
//   *            AHB Prescaler                  = 1
//   *            APB1 Prescaler                 = 1
//   *            APB2 Prescaler                 = 2
//   *            HSE Frequency(Hz)              = 8000000
//   *            PLL_M                          = 8
//   *            PLL_N                          = 336
//   *            PLL_P                          = 4
//   *            VDD(V)                         = 3.3
//   *            Main regulator output voltage  = Scale2 mode
//   *            Flash Latency(WS)              = 2
//   * @param  None
//   * @retval None
//   */
// void SystemClock_Config(void)
// {
//   /* Enable HSE oscillator */
//   LL_RCC_HSE_EnableBypass();
//   LL_RCC_HSE_Enable();
//   while(LL_RCC_HSE_IsReady() != 1)
//   {
//   };

//   /* Set FLASH latency */
//   LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);

//   /* Main PLL configuration and activation */
//   LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_8, 336, LL_RCC_PLLP_DIV_4);
//   LL_RCC_PLL_Enable();
//   while(LL_RCC_PLL_IsReady() != 1)
//   {
//   };

//   /* Sysclk activation on the main PLL */
//   LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
//   LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
//   while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
//   {
//   };

//   /* Set APB1 & APB2 prescaler */
//   LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
//   LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_2);

//   /* Set systick to 1ms */
//   SysTick_Config(84000000 / 1000);

//   /* Update CMSIS variable (which can be updated also through SystemCoreClockUpdate function) */
//   SystemCoreClock = 84000000;
// }

void clock_init(void)
{
  LL_FLASH_EnablePrefetch();

  // 84 MHz requires 2 wait states at 3.3V
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);

  // VCO = PLL_in * (N / M)
  // PLL_out = VCO / P
  // USB/SDIO/RNG = VCO / Q
  // PLL_in = 16 MHz
  // N = 336
  // M = 16
  // P = 4
  // PLL_out = 16 MHz * (336 / 16) / 4 => 84 MHz
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI, LL_RCC_PLLM_DIV_16, 336, LL_RCC_PLLP_DIV_4);
  LL_RCC_PLL_Enable();
  while(LL_RCC_PLL_IsReady() != 1) {
  };

  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL) {
  };

  // APB1 max frequency is 42 MHz
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
  // APB2 max frequency is 84 MHz
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB1_DIV_1);

  SystemCoreClockUpdate();
}
