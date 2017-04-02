cmake_minimum_required(VERSION 3.7)
project(actividad02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Estacion.h Posicion.h MenuEstacion.cpp MenuEstacion.h)
add_executable(actividad02 ${SOURCE_FILES})