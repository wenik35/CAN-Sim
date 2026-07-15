# Remote-Lab "CAN-Sim"

"CAN-Sim" is an [edrys-lite](https://github.com/edrys-labs/edrys-Lite) based remote lab project for simulating CAN (Controller Area Network) communication using STM32 microcontrollers. The repository contains multiple subprojects that provide firmware examples for STM32F4 devices, demonstrating CAN peripheral usage and USB host support.

## Repository structure

- `cad-files` - Contains CAD files for the hardware setup used in the remote lab. The car model is a modified version of [Turtleman's Remastered Low Poly BMW 2002 Turbo](https://www.printables.com/model/342150-remastered-low-poly-bmw-2002-turbo), which is licensed under Creative Commons Attribution 4.0 International (CC BY 4.0).
- `can-f407-makefile/` - Full STM32F407 makefile project with HAL drivers and USB host support.
- `can-f407-makefile-slim/` - Slimmed-down STM32F407 makefile project with CAN and USB host support.
- `can-f413-makefile/` - Full STM32F413 makefile project with HAL drivers.
- `can-f413-makefile-slim/` - Slimmed-down STM32F413 makefile project.
- `python-terminal/` - [module-pyxtermjs](https://github.com/edrys-labs/module-pyxtermjs) fork with additional utilities for compiling and flashing STM32 firmware

## Key features

- STM32F407 and STM32F413 examples
- CAN peripheral initialization and transmit/receive support
- USB host support in the `can-f407-makefile-slim` project
- Generated `Makefile` targets for build, clean, and flash

## Requirements

- Docker
- Chromium Browser

No really, thats it. Just run the `docker compose up` command in the `/python-terminal`, it will install all the necessary dependecies itself. The remote lab itself is built for edrys-lite, which runs fully p2p in your browser. Just upload the provided yaml file and you are ready to go.

## Building

Build a subproject by changing to its directory and running `make`.

Example:

```bash
cd can-f407-makefile-slim
make
```

For the STM32F413 project:

```bash
cd can-f413-makefile-slim
make
```

If the toolchain is not on `PATH`, provide the `GCC_PATH` variable:

```bash
cd can-f407-makefile-slim
make GCC_PATH="C:/path/to/arm-none-eabi"
```

## Cleaning

Remove generated build artifacts with:

```bash
cd can-f407-makefile-slim
make clean
```

## Flashing

The makefiles include a `flash` target that uses OpenOCD with `target/stm32f4x.cfg`.

```bash
cd can-f407-makefile-slim
make flash
```

You will need to find out the serial number of your boards and provide them to the `flash` target at the bottom of the Makefile. Just connect the board the board to your computer and run `lsusb -v -d 0483:374b | grep iSerial` to find it.

## Notes

- `can-f407-makefile-slim` is a slimmed down version for the remote lab, which 
- The STM32F407 does not have a USB serial connection, so a separate TTL-to-USB module is needed
- The terminal module is currently only configured to include the STM32F407 example, but it can be easily modified to include the STM32F413 example as well. Just change the `Dockerfile` in the `python-terminal` directory to include the `can-f413-makefile` project and rebuild the docker image.