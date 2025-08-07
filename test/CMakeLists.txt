find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES runAllTests.cpp TestOggettoLista.cpp)
add_executable(runAllTests ${SOURCE_FILES})

# linka le librerie GTest e la tua libreria core (se core è la tua libreria)
target_link_libraries(runAllTests ${GTEST_LIBRARIES} core pthread)
