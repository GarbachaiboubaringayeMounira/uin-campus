cmake_minimum_required(VERSION 3.25)
project(TP5TableauDynamique VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(TP5_ACTIVER_SANITIZERS "Activer AddressSanitizer et UBSan" OFF)

# Options communes à toutes les cibles
add_library(tp5_options INTERFACE)
target_compile_features(tp5_options INTERFACE cxx_std_23)
target_include_directories(tp5_options INTERFACE ${PROJECT_SOURCE_DIR}/include)

if(MSVC)
    target_compile_options(tp5_options INTERFACE /W4 /permissive-)
else()
    target_compile_options(tp5_options INTERFACE
        -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()

if(TP5_ACTIVER_SANITIZERS AND NOT MSVC)
    target_compile_options(tp5_options INTERFACE
        -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(tp5_options INTERFACE
        -fsanitize=address,undefined)
endif()

# A.1 : programme correct (aucun rapport des sanitizers)
add_executable(partie_a app/partie_a_b.cpp)
target_link_libraries(partie_a PRIVATE tp5_options)

# A.3 : sans liberer() -> LeakSanitizer signale une fuite
add_executable(a3_fuite app/partie_a_b.cpp)
target_compile_definitions(a3_fuite PRIVATE TP5_SANS_LIBERER)
target_link_libraries(a3_fuite PRIVATE tp5_options)

# A.4 : delete au lieu de delete[] -> alloc-dealloc-mismatch
add_executable(a4_mismatch app/partie_a_b.cpp)
target_compile_definitions(a4_mismatch PRIVATE TP5_DELETE_SIMPLE)
target_link_libraries(a4_mismatch PRIVATE tp5_options)

# B : copie superficielle -> double libération
add_executable(partie_b app/partie_a_b.cpp)
target_compile_definitions(partie_b PRIVATE TP5_COPIE)
target_link_libraries(partie_b PRIVATE tp5_options)

# C : std::vector
add_executable(partie_c app/partie_c.cpp)
target_link_libraries(partie_c PRIVATE tp5_options)
