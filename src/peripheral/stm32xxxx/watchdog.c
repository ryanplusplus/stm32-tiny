/*!
 * @file
 * @brief
 */

#include "watchdog.h"
#include "micro.h"

static tiny_timer_t timer;

static void kick(tiny_timer_group_t* _timer_group, void* context)
{
  (void)context;
  (void)_timer_group;
  LL_IWDG_ReloadCounter(IWDG);
}

void watchdog_init(tiny_timer_group_t* timer_group)
{
  LL_IWDG_EnableWriteAccess(IWDG);
  {
    // Watchdog tick rate = 32 KHz / 32 = 1 msec
    LL_IWDG_SetPrescaler(IWDG, LL_IWDG_PRESCALER_32);

    // 1000 * tick rate = 1000 * 1 = 1 second timeout
    LL_IWDG_SetReloadCounter(IWDG, 1000);
  }
  LL_IWDG_DisableWriteAccess(IWDG);

  LL_IWDG_ReloadCounter(IWDG);
  LL_IWDG_Enable(IWDG);

  tiny_timer_start_periodic(timer_group, &timer, 500, NULL, kick);
}
