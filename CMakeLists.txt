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
        tools/export/bitmap/Bitmap.cpp tools/export/bitmap/Bitmap.h tools/export/bitmap/Color.cpp tools/export/bitmap/Color.h tools/export/bitmap/Renderer.cpp tools/export/bitmap/Renderer.h tools/analytics/drawing/Chart.cpp tools/analytics/drawing/Chart.h tests/plane_distribution/PlaneDistributionTest.cpp tests/plane_distribution/PlaneDistributionTest.h tests/Test.h tools/export/csv/CsvExporter.cpp tools/export/csv/CsvExporter.h tools/analytics/histograms/Histograms.cpp tools/analytics/histograms/Histograms.h tests/histograms/DensityHistogramTest.cpp tests/histograms/DensityHistogramTest.h tests/histograms/EmpiricalDistributionTest.cpp tests/histograms/EmpiricalDistributionTest.h tests/numeric/NumericCharacteristicsTest.cpp tests/numeric/NumericCharacteristicsTest.h tests/cycle/CycleDetectionTest.cpp tests/cycle/CycleDetectionTest.h tests/distribution/DistributionTest.cpp tests/distribution/DistributionTest.h tests/RecordedRandom.cpp tests/RecordedRandom.h tests/TestRunner.cpp tests/TestRunner.h)