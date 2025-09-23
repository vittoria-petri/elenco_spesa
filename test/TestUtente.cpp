#include <gtest/gtest.h>
#include "../Utente.h"

TEST(UtenteTest, CostruttoreConNomeNonValido) {
    EXPECT_THROW({Utente utente("");}, std::invalid_argument);
}


TEST(UtenteTest, CostruttoreValido) {
    Utente utente("Silva");

    EXPECT_EQ(utente.getNomeUtente(), "Silva");
}


TEST(UtenteTest, AggiungiListaFunziona) {
    Utente utente("Frisk");
    std::shared_ptr<ListaSpesa> lista = std::make_shared<ListaSpesa>();
    utente.aggiungiLista(lista);

    EXPECT_EQ(utente.getListe().size(), 1);
}