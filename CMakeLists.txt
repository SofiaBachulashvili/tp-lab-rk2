cmake_minimum_required(VERSION 3.5)  # Указываем минимальную версию CMake, необходимую для сборки проекта.
set(CMAKE_CXX_STANDARD 17)  # Устанавливаем стандарт C++ 17.

project(AdapterPattern)

option(BUILD_TESTS "Build tests" OFF)  # Опция для сборки тестов. По умолчанию включена.

add_executable(AdapterPattern adapter/ClassAdapter.cpp
                              adapter/ClassAdapter.hpp
                              adapter/ObjectAdapter.cpp
                              adapter/ObjectAdapter.hpp)  # Создаем исполняемый файл.
                                
if(BUILD_TESTS)
  enable_testing()  # Включаем поддержку тестирования.
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)  # Получаем исходные файлы тестов.
  add_subdirectory(third-party/gtest) # Добавление библиотеки Google Test
  add_executable(RunTests ${${PROJECT_NAME}_TEST_SOURCES})  # Создаем исполняемый файл для тестов.
  target_link_libraries(RunTests gtest_main)  # Линкуем библиотеки для тестов.
  add_test(NAME RunTests COMMAND RunTests)  # Добавляем команду для запуска тестов.
endif()

add_executable(AdapterPatternClassDemo demo/ClassAdapterMain.cpp)
add_executable(AdapterPatternObjectDemo demo/ObjectAdapterMain.cpp)
