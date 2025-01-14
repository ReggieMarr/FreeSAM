####
# featherESP32.cmake:
#
# Adafruit ESP32 Feather V2 support.
####
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-std=c++2a -std=gnu++2a) # Force C++20 standard

set(CMAKE_SYSTEM_NAME "Generic")
set(CMAKE_SYSTEM_PROCESSOR "arm")
set(CMAKE_CROSSCOMPILING 1)
set(FPRIME_PLATFORM "AtmelFw")
set(FPRIME_USE_BAREMETAL_SCHEDULER ON)

# Prevent test program compiling
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

set(ATMEL_FQBN "esp32:esp32:adafruit_feather_esp32_v2")
add_compile_options(-D_BOARD_FEATHER_ESP32 -DNO_ONBOARD_LED -DUSE_BASIC_TIMER)
# Run the base atmel setup which should detect settings!
include("${CMAKE_CURRENT_LIST_DIR}/support/atmel-support.cmake")
