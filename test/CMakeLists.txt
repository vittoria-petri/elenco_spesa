add_subdirectory(googletest)

set(gtest_SOURCE_DIR, googletest/)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES
        runAllTests.cpp
        TestOggettoLista.cpp
        ../Categoria.h
        ../ListaSpesa.h
        ../Observer.h
        ../ObserverConcrete.h
        ../OggettoLista.h
        ../Subject.h
        ../Utente.h
        TestObserverConcrete.cpp
        TestUtente.cpp
        TestCategoria.cpp
        TestListaSpesa.cpp
)

add_executable(runAllTests ${SOURCE_FILES})

target_link_libraries(runAllTests gtest gtest_main gmock core)