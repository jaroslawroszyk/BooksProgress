cmake_minimum_required(VERSION 3.17)

project(howamanypages VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_BUILD_TYPE Release)
elseif(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_BUILD_TYPE Debug)
else()
    message(FATAL_ERROR "Available build types: Debug and Release.")
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(howamanypages
    src/main.cpp
    src/pages.cpp
)

set_target_properties(howamanypages
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(MSVC)
        #ToDo: add flags for msfc
    else()
        target_compile_options(howamanypages
                PUBLIC
                -O3 -g3 -Wall -Wextra -pedantic
            )
    endif()
else()
    if(MSVC)
        #ToDo: add flags for msfc
    else()
        target_compile_options(howamanypages
                PUBLIC
                -O3 -Wall -Wextra -pedantic
            )
    endif()
endif()