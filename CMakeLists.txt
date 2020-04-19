cmake_minimum_required(VERSION 3.15)
project(pseudo_random_generator)

set(CMAKE_CXX_STANDARD 14)

add_executable(pseudo_random_generator
        main.cpp
        src/Random.h
        src/linear/LinearCongruentialRandom.cpp
        src/linear/LinearCongruentialRandom.h
        src/RandomFactory.cpp
        src/RandomFactory.h
        src/middle_square/MiddleSquareRandom.cpp
        src/middle_square/MiddleSquareRandom.h
        tools/analytics/drawing/Bitmap.cpp tools/analytics/drawing/Bitmap.h tools/analytics/drawing/Color.cpp tools/analytics/drawing/Color.h tools/analytics/drawing/Renderer.cpp tools/analytics/drawing/Renderer.h tools/analytics/drawing/Chart.cpp tools/analytics/drawing/Chart.h)