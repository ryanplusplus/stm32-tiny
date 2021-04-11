TARGET = $(subst .mk,,$(firstword $(MAKEFILE_LIST)))
BUILD_DIR ?= ./build/$(TARGET)

CPU := cortex-m4
ARCH := armv7e-m+fp
LINKER_CFG := ld/$(TARGET).ld
SVD := svd/stm32f401.svd

DEBUG_ADAPTER ?= openocd
OPENOCD_CFG_DIR := openocd/$(TARGET)
BLACK_MAGIC_PORT ?= /dev/ttyACM0
BLACK_MAGIC_POWER_TARGET ?= N

DEFINES := \
  STM32F401xE \

include tools/defaults.mk

CPPFLAGS += \
  -Wno-unused-parameter \

SRC_DIRS := \
  src/peripheral/cmsis \
  src/peripheral/stm32xxxx \
  src/target/$(TARGET) \

SRC_FILES := \
  lib/stm32cube/CMSIS/STM32F4xx/src/system_stm32f4xx.c \

INC_DIRS := \
  lib/stm32cube/CMSIS/ARM/inc \
  lib/stm32cube/CMSIS/STM32F4xx/inc \
  lib/stm32cube/HAL/STM32F4xx/inc \

include lib_tiny.mk

include tools/tools.mk

.PHONY: watch
watch:
	@rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"