/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include "stm32f3xx.h"
#include "clock.h"
#include "systick.h"
#include "accelerometer_plugin.h"
#include "display_plugin.h"
#include "tiny_timer.h"
#include "watchdog.h"
#include "i2c1_pins.h"
#include "async_i2c1.h"
#include "leds.h"
#include "tiny_message_bus.h"

static tiny_timer_group_t timer_group;
static tiny_message_bus_t message_bus;

static accelerometer_plugin_t accelerometer_plugin;
static display_plugin_t display_plugin;

int main(void)
{
  __disable_irq();
  {
    clock_init();

    tiny_timer_group_init(&timer_group, systick_init());
    watchdog_init(&timer_group);

    tiny_message_bus_init(&message_bus);

    i2c1_pins_init();
    i_tiny_async_i2c_t* i2c1 = async_i2c1_init();

    accelerometer_plugin_init(
      &accelerometer_plugin,
      &timer_group,
      &message_bus.interface,
      i2c1);

    display_plugin_init(
      &display_plugin,
      &message_bus.interface,
      leds_init());
  }
  __enable_irq();

  while(1) {
    tiny_timer_group_run(&timer_group);
    __WFI();
  }
}
