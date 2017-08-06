cmake_minimum_required(VERSION 3.8)
project(MathPlayground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(SOURCE_FILES
    Source/Factorize.hpp
    Source/Factorize.cpp
    )

add_executable(MathPlayground
    UnitTest/Main.cpp
    )

add_executable(factorize
    Source/Factorize.hpp
    Source/Factorize.cpp
    )


add_executable(closest_fators
    Source/Factorize.hpp
    Source/ClosestTwoFactors.cpp
    Source/ClosestTwoFactors.hpp
    )
