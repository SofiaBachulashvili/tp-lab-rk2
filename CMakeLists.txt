cmake_minimum_required(VERSION 3.0)

option(BUILD_TESTS "Build tests" OFF)

project(AdapterPattern)

# Добавляем исполняемый файл для ClassAdapter.cpp
add_executable(ClassAdapter adapter/ClassAdapter.cpp)

# Добавляем исполняемый файл для ObjectAdapter.cpp
add_executable(ObjectAdapter adapter/ObjectAdapter.cpp)

if(BUILD_TESTS)
  enable_testing()
  # Добавление библиотеки Google Test
  add_subdirectory(third-party/gtest)
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  # Добавляем исполняемый файл для тестов
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(RunTests ${PROJECT_NAME} gtest_main)
  # Добавляем тесты в проект
  add_test(NAME RunTests COMMAND RunTests)
endif()
