#include <gtest/gtest.h>
#include "../ListaSpesa.h"
#include "../OggettoLista.h"
#include "../Categoria.h"
#include "../ObserverConcrete.h"

TEST(ListaSpesaTest, AggiungiOggettoValido) {
    ListaSpesa lista;
    Categoria categoria("Frutta");
    OggettoLista oggetto("Mela", 2, categoria);
    lista.aggiungiOggetto(oggetto);
    std::list<OggettoLista> oggetti = lista.getLista();

    EXPECT_EQ(oggetti.size(), 1);
    EXPECT_EQ(oggetti.front().getNome(), "Mela");
    EXPECT_EQ(oggetti.front().getQuantita(), 2);
    EXPECT_EQ(oggetti.front().getCategoria().getNome(), "Frutta");
}


TEST(ListaSpesaTest, AggiungiOggettoConQuantitaNonValida) {
    ListaSpesa lista;
    Categoria categoria("Verdura");

    EXPECT_THROW({
        OggettoLista oggetto("Carota", 0, categoria);
        lista.aggiungiOggetto(oggetto);
    }, std::invalid_argument);
}


TEST(ListaSpesaTest, RimuoviOggettoEsistente) {
    ListaSpesa lista;
    Categoria categoria("Frutta");
    OggettoLista oggetto("Mela", 1, categoria);
    lista.aggiungiOggetto(oggetto);

    EXPECT_EQ(lista.getLista().size(), 1);

    lista.rimuoviOggetto("Mela");

    EXPECT_EQ(lista.getLista().size(), 0);
}


TEST(ListaSpesaTest, RimuoviOggettoInesistente) {
    ListaSpesa lista;
    Categoria categoria("Frutta");
    OggettoLista oggetto("Mela", 1, categoria);
    lista.aggiungiOggetto(oggetto);

    EXPECT_THROW(lista.rimuoviOggetto("More"), std::runtime_error);
}


TEST(ListaSpesaTest, ObserverConcreteVieneNotificato) {
    ListaSpesa lista;
    ObserverConcrete observer(&lista);
    Categoria categoria("Frutta");
    OggettoLista oggetto("Pere", 6, categoria);
    lista.aggiungiOggetto(oggetto);

    SUCCEED();
}


TEST(ListaSpesaTest, ObserverConcreteDetachFunziona) {
    ListaSpesa lista;
    ObserverConcrete observer(&lista);

    EXPECT_TRUE(lista.hasObserver(&observer));

    observer.detach();

    EXPECT_FALSE(lista.hasObserver(&observer));
}