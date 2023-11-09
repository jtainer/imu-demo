# IMU Demo Firmware

Firmware for STM32F103C8T6 to read orientation data from MPU6050 IMU.

## Requirements

- PlatformIO

## Build instructions:

1. After cloning repository, pull down git submodules with `git submodule update --init --recursive`
2. Build with `pio run`
3. Binary is located at `.pio/build/stm32f103/firmware.elf`

## Notes:

- Generated files are located in the directories src, inc, and lib/usb. Do not mess with these.
