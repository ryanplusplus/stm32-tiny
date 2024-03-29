/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include <stdbool.h>
#include "stm32f3xx_ll_bus.h"
#include "stm32f3xx_ll_gpio.h"
#include "heartbeat.h"

enum {
  half_period_in_msec = 500,
};

static struct {
  tiny_timer_t timer;
} self;

static void blink(void* context)
{
  (void)context;
  LL_GPIO_TogglePin(GPIOE, LL_GPIO_PIN_9);
}

void heartbeat_init(tiny_timer_group_t* timer_group)
{
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);

  LL_GPIO_SetPinSpeed(GPIOE, LL_GPIO_PIN_9, LL_GPIO_SPEED_FREQ_LOW);
  LL_GPIO_SetPinOutputType(GPIOE, LL_GPIO_PIN_9, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinMode(GPIOE, LL_GPIO_PIN_9, LL_GPIO_MODE_OUTPUT);
  LL_GPIO_SetPinPull(GPIOE, LL_GPIO_PIN_9, LL_GPIO_PULL_NO);

  tiny_timer_start_periodic(timer_group, &self.timer, half_period_in_msec, NULL, blink);
}
