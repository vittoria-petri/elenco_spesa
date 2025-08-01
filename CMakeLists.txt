cmake_minimum_required(VERSION 3.29)
project(elenco_spesa)

add_subdirectory(test/googletest)

set(SOURCE_FILES
        main.cpp
)

add_library(core ${SOURCE_FILES})

set(CMAKE_CXX_STANDARD 20)

add_executable(elenco_spesa main.cpp)
target_link_libraries(elenco_spesa core)

add_subdirectory(test)
enable_testing()