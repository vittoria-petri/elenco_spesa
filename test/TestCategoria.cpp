#include <gtest/gtest.h>
#include "../Categoria.h"

TEST(CategoriaTest, CostruttoreConNomeValido) {
    Categoria cat("Frutta");

    EXPECT_EQ(cat.getNome(), "Frutta");
}


TEST(CategoriaTest, CostruttoreConNomeVuoto) {
    EXPECT_THROW({Categoria cat("");}, std::invalid_argument);
}


TEST(CategoriaTest, CostruttoreCopia) {
    Categoria originale("Frutta");
    Categoria copia = originale;

    EXPECT_EQ(copia.getNome(), "Frutta");
}


TEST(CategoriaTest, OperatoreAssegnazione) {
    Categoria cat1("Frutta");
    Categoria cat2("Alimentari");
    cat2 = cat1;

    EXPECT_EQ(cat2.getNome(), "Frutta");
}