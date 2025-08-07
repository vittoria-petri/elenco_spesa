//
// Created by Vittoria Petri on 31/07/25.
//
#include <gtest/gtest.h>
#include <stdexcept>
#include "../Categoria.h"
#include "../OggettoLista.h"

TEST(OggettoListaTest, CostruzioneConQuantitaZero) {
    Categoria cat("Frutta");
    EXPECT_THROW({
        OggettoLista mora("Mora", 0, cat);
    }, std::invalid_argument);

}