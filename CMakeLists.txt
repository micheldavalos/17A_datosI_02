cmake_minimum_required(VERSION 3.6)
project(actividad02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Estacion.h Posicion.h MenuEstacion.cpp MenuEstacion.h arreglo.h)
add_executable(actividad02 ${SOURCE_FILES})