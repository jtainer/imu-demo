# IMU Demo Firmware

Firmware for STM32F103C8T6 to read orientation data from MPU6050 IMU.

## Requirements

- PlatformIO

## Build instructions:

1. After cloning repository, pull down git submodules with `git submodule update --init --recursive`.
2. Build with `pio run`.
3. Binary is located at `.pio/build/stm32f103/firmware.elf`.

## Notes:

- Generated files are located in the directories src, inc, and lib/usb. Do not mess with these.
- `copy_source.sh` is a shell script for copying generated files from a STM32 project into the repo. I made this for my own personal convenience, but if you need to use this then you will have to change the paths according to the name of your workspace and project directories.
