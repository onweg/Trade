cmake_minimum_required(VERSION 3.14)
project(DummyStrategy)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(DummyStrategy SHARED DummyStrategy.cpp ../../infrastructure/Logger.cpp)

target_include_directories(DummyStrategy PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/tradebot/models
    ${CMAKE_SOURCE_DIR}/include/tradebot/interfaces
)

set_target_properties(DummyStrategy PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/DummyStrategy
    OUTPUT_NAME "DummyStrategy"
)