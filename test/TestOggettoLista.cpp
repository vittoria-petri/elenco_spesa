#include <gtest/gtest.h>
#include "../OggettoLista.h"

TEST(OggettoListaTest, CostruttoreValido) {
    Categoria cat("Frutta");
    OggettoLista og("Mela", 2, cat);

    EXPECT_EQ(og.getNome(), "Mela");
    EXPECT_EQ(og.getQuantita(), 2);
    EXPECT_EQ(og.getCategoria().getNome(), "Frutta");

}

TEST(OggettoListaTest, CostruttoreConNomeNonValido) {
    Categoria cat("Frutta");

    EXPECT_THROW({OggettoLista og("", 2, cat);} , std::invalid_argument);
}

TEST(OggettoListaTest, CostruttoreConQuantitaZero) {
    Categoria cat("Frutta");

    EXPECT_THROW({OggettoLista og("Mela", 0, cat);}, std::invalid_argument);
}

TEST(OggettoListaTest, CostruttoreConQuantitaNonValida) {
    Categoria cat("Frutta");

    EXPECT_THROW({OggettoLista og("Mela", -1, cat);}, std::invalid_argument);
}

TEST(OggettoListaTest, ConstruttoreCopia) {
    Categoria cat("Frutta");
    OggettoLista originale("Banana", 3, cat);
    OggettoLista copia = originale;

    EXPECT_EQ(copia.getNome(), "Banana");
    EXPECT_EQ(copia.getQuantita(), 3);
    EXPECT_EQ(copia.getCategoria().getNome(), "Frutta");
}

TEST(OggettoListaTest, OperatoreAssegnazione) {
    Categoria cat1("Frutta");
    Categoria cat2("Alimentari");

    OggettoLista og1("Mela", 5, cat1);
    OggettoLista og2("Pane", 2, cat2);

    og2 = og1;

    EXPECT_EQ(og2.getNome(), "Mela");
    EXPECT_EQ(og2.getQuantita(), 5);
    EXPECT_EQ(og2.getCategoria().getNome(), "Frutta");
}