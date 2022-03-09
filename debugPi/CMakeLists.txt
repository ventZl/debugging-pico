cmake_minimum_required(VERSION 3.10)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_LIST_DIR}/.. ABSOLUTE)

# Tento blok IF overi, ci je pico-sdk vyklonovane v rovnakom podadresari
# ako tento projekt. Cely tento blok mozete odstranit, ak chcete mat pico-sdk
# inde, Potom je nutne cestu k nemu nastavit manualne do premennej
# PICO_SDK_PATH!
if (NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/../pico-sdk/CMakeLists.txt)
	message(FATAL_ERROR "Pico-SDK nenajdene! Prosim naklonujte SDK do adresara
	${PARENT_DIR}:

	cd ${PARENT_DIR}
	git clone https://github.com/raspberry-pi/pico-sdk.git
	cd pico-sdk
	git submodule add --init
	")
endif()

set(PICO_SDK_PATH ${CMAKE_CURRENT_LIST_DIR}/../pico-sdk)

list(APPEND CMAKE_MODULE_PATH ${PICO_SDK_PATH}/external)

# Naimportuje funkcie dostupne z Pico SDK
include(pico_sdk_import)

project(blinky LANGUAGES C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Zavola funkciu Pico SDK, ktora zinicializuje SDK pre pouzitie v projekte
pico_sdk_init()

set(blinky_SRCS main.c)
add_executable(blinky ${blinky_SRCS})
target_link_libraries(blinky pico_stdlib)

# Zabezpeci vygenerovanie extra vystupnych suborov pre projekt blinky, ako su
# subor s mapou symbolov a UF2 subor pre jednoduche flashovanie.
pico_add_extra_outputs(blinky)
