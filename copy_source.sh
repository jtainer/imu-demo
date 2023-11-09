#!/bin/bash
rm src/*
rm inc/*
rm lib/usb/*
cp ~/STM32CubeIDE/workspace_1.13.2/imu_demo_f4/Core/Src/* src/
cp ~/STM32CubeIDE/workspace_1.13.2/imu_demo_f4/Core/Inc/* inc/
cp ~/STM32CubeIDE/workspace_1.13.2/imu_demo_f4/USB_DEVICE/App/* lib/usb/
cp ~/STM32CubeIDE/workspace_1.13.2/imu_demo_f4/USB_DEVICE/Target/* lib/usb/


