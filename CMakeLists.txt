cmake_minimum_required(VERSION 3.29)

project(elenco_spesa)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        main.cpp
        Categoria.h
        ListaSpesa.h
        Observer.h
        ObserverConcrete.h
        OggettoLista.h
        Subject.h
        Utente.h
)

add_library(core ${SOURCE_FILES})
add_executable(elenco_spesa main.cpp)

target_link_libraries(elenco_spesa core)

add_subdirectory(test)