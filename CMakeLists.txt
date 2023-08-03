cmake_minimum_required(VERSION 3.17...3.25)

project(BookStatistic VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 20)

if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_BUILD_TYPE Release)
elseif(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_BUILD_TYPE Debug)
else()
    message(FATAL_ERROR "Available build types: Debug and Release.")
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(BookStatistic
    src/main.cpp
    src/BookStatistic.cpp
    src/Program.cpp
    src/ProgramMode.cpp
)

set_target_properties(BookStatistic
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(MSVC)
        #ToDo: add flags for msfc
    else()
        target_compile_options(BookStatistic
                PUBLIC
                -O3 -g3 -Wall -Wextra -pedantic
            )
    endif()
else()
    if(MSVC)
        #ToDo: add flags for msfc
    else()
        target_compile_options(BookStatistic
                PUBLIC
                -O3 -Wall -Wextra -pedantic
            )
    endif()
endif()