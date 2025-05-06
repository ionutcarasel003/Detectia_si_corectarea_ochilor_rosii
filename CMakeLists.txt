cmake_minimum_required(VERSION 3.31)
project(Proiect)

set(CMAKE_CXX_STANDARD 26)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Detectia_si_corectia_ochilor_rosii main.cpp
        ImageLoader.cpp
        ImageLoader.h
        RedEyeDetector.cpp
        RedEyeDetector.h
        RedEyeCorrector.cpp
        RedEyeCorrector.h
        RedEyeProcessor.cpp
        RedEyeProcessor.h)
target_link_libraries(Detectia_si_corectia_ochilor_rosii ${OpenCV_LIBS})