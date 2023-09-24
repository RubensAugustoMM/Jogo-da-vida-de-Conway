cmake_minimum_required(VERSION 3.22)
project(Jogo_da_vida_de_Conway C)

set(CMAKE_C_STANDARD 11)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(.)

add_executable(Jogo_da_vida_de_Conway
        InterfaceUsuario/InterfaceUsuario.c
        InterfaceUsuario/InterfaceUsuario.h)
target_link_libraries(Jogo_da_vida_de_Conway ${CURSES_LIBRARY})
install(TARGETS Jogo_da_vida_de_Conway RUNTIME DESTINATION ${BIN_DIR})
