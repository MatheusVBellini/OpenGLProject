cmake_minimum_required(VERSION 3.26)
project(OpenGLProject)

set(CMAKE_CXX_STANDARD 17)
set(OpenGlLinkers -lGL -lglfw -lGLEW)

add_executable(OpenGLProject main.cpp
        src/Application.cpp
        include/Application.h
        src/Window.cpp
        include/Window.h)
target_link_libraries(OpenGLProject ${OpenGlLinkers})
