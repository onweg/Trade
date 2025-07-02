cmake_minimum_required(VERSION 3.14)
project(TradeBot)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути к заголовочным файлам
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/tradebot/models
    ${CMAKE_SOURCE_DIR}/include/tradebot/interfaces
    ${CMAKE_SOURCE_DIR}/include/tradebot/infrastructure
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/infrastructure
)

# Основные исходники
set(SRC_FILES
    src/main.cpp
    src/PluginLoader.cpp
    core/OrderManager.h
    core/TradeEngine.h
    infrastructure/ExchangeApi.h
    infrastructure/Logger.h
)

add_executable(TradeBot ${SRC_FILES})

# Добавить подпроекты для плагинов
add_subdirectory(plugins/DummyStrategy) 