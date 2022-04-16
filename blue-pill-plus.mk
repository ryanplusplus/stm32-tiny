include tools/setup.mk

TARGET = $(subst .mk,,$(firstword $(MAKEFILE_LIST)))
BUILD_DIR ?= ./build/$(TARGET)

CPU := cortex-m3
LINKER_SCRIPT := ld/$(TARGET).ld
SVD := svd/stm32f103.svd

DEBUG_ADAPTER ?= openocd
OPENOCD_CFG_DIR := openocd/$(TARGET)
BLACK_MAGIC_PORT ?= /dev/ttyACM0
BLACK_MAGIC_POWER_TARGET ?= N

DEFINES := \
  STM32F103xB \
  HSE_VALUE=8000000 \

include tools/defaults.mk

CPPFLAGS += \
  -Wno-unused-parameter \
  -flto \
  -fwhole-program \

SRC_DIRS := \
  src/peripheral/cmsis \
  src/peripheral/stm32xxxx \
  src/target/$(TARGET) \

SRC_FILES := \
  lib/stm32cube/CMSIS/STM32F1xx/src/system_stm32f1xx.c \

INC_DIRS := \
  lib/stm32cube/CMSIS/ARM/inc \
  lib/stm32cube/CMSIS/STM32F1xx/inc \
  lib/stm32cube/HAL/STM32F1xx/inc \

include lib/tiny/lib_tiny.mk

.PHONY: all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex
	@$(SIZE) $<

.PHONY: watch
watch:
	@rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"

include tools/tools.mk
