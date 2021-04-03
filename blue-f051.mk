TARGET = tiny
BUILD_DIR ?= ./build/blue-f051

CPU := cortex-m0
ARCH := armv6-m
OPENOCD_CFG := openocd/blue-f051
LINKER_CFG := ld/blue-f051.ld

DEFINES := \
  STM32F051x8 \
  HSE_VALUE=8000000 \

SRC_DIRS := \
  src/target/blue-f051 \

LIB_FILES := \
  lib/stm32cube/CMSIS/STM32F0xx/src/system_stm32f0xx.c \

LIB_DIRS := \
  lib/tiny/src \
  src/peripheral/cmsis \
  src/peripheral/stm32xxxx \

INC_DIRS := \
  lib/stm32cube/CMSIS/ARM/inc \
  lib/stm32cube/CMSIS/STM32F0xx/inc \
  lib/stm32cube/HAL/STM32F0xx/inc \
  lib/tiny/include \

include makefile-worker.mk
