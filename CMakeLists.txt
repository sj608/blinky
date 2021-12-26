cmake_minimum_required(VERSION 3.22.0)

#optional: print out extra messages to see what is going on. Comment it to have less verbose messages
set(CMAKE_VERBOSE_MAKEFILE ON)

#path to toolchain file. this one has to be before 'project()' below
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/ARM-NONE-EABI-GCC.cmake)

#setup project, output and linker file
project(Blinky)
set(EXECUTABLE ${PROJECT_NAME}.elf)

enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD ON)
set(CMAKE_C_EXTENSIONS OFF)

#optional: issue a message to be sure it uses the correct toolchain file.
message(STATUS "CMAKE_TOOLCHAIN_FILE is: ${CMAKE_TOOLCHAIN_FILE}")

#list of source files
set(
    src/main.c,
    CMSIS/system_stm32f10x.c
)
