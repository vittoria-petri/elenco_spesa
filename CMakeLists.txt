cmake_minimum_required(VERSION 3.29)
project(elenco_spesa)

add_subdirectory(test)
enable_testing()

add_subdirectory(test/googletest)

set(SOURCE_FILES
        main.cpp
)

add_executable(elenco_spesa main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(elenco_spesa core)

set(CMAKE_CXX_STANDARD 20)



