add_executable(core_tests TestOggettoLista.cpp TestListaSpesa.cpp TestObserver.cpp)

target_link_libraries(core_tests gtest gtest_main core pthread)

include(GoogleTest)
gtest_discover_tests(core_tests)