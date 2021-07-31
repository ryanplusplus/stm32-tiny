/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include <stdbool.h>
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_gpio.h"
#include "heartbeat.h"

enum {
  half_period_in_msec = 500,
};

static struct {
  tiny_timer_t timer;
} self;

static void blink(tiny_timer_group_t* group, void* context)
{
  (void)context;
  LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_4);
  tiny_timer_start(group, &self.timer, half_period_in_msec, NULL, blink);
}

void heartbeat_init(tiny_timer_group_t* timer_group)
{
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);

  LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_4, LL_GPIO_SPEED_FREQ_LOW);
  LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_4, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT);
  LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_4, LL_GPIO_PULL_UP);

  tiny_timer_start(timer_group, &self.timer, half_period_in_msec, NULL, blink);
}
