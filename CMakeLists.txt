cmake_minimum_required(VERSION 3.0)
project(AdapterPattern)

# Добавляем исполняемый файл для ClassAdapter.cpp
add_executable(ClassAdapter adapter/ClassAdapter.cpp)

# Добавляем исполняемый файл для ObjectAdapter.cpp
add_executable(ObjectAdapter adapter/ObjectAdapter.cpp)
