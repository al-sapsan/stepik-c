cmake_minimum_required(VERSION 3.10)
project(C_projects C)

# Установка стандартов и опций
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Исходный файл
set(SOURCE_FILE test.c)  # <-- Измени на своё имя файла

# Debug target
add_executable(${PROJECT_NAME}_debug ${SOURCE_FILE})
set_target_properties(${PROJECT_NAME}_debug PROPERTIES
    RUNTIME_OUTPUT_NAME "${SOURCE_FILE_NAME}_debug"
)
target_compile_definitions(${PROJECT_NAME}_debug PRIVATE DEBUG)
target_compile_options(${PROJECT_NAME}_debug PRIVATE -g)

# Release target
add_executable(${PROJECT_NAME}_release ${SOURCE_FILE})
set_target_properties(${PROJECT_NAME}_release PROPERTIES
    RUNTIME_OUTPUT_NAME "${SOURCE_FILE_NAME}_release"
)
target_compile_definitions(${PROJECT_NAME}_release PRIVATE NDEBUG)
target_compile_options(${PROJECT_NAME}_release PRIVATE -O2)

# Расчёт имени файла без расширения
get_filename_component(SOURCE_FILE_NAME ${SOURCE_FILE} NAME_WE)

