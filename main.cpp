#include <iostream>
#include <memory>
#include "Utente.h"
#include "ObserverConcrete.h"
#include "OggettoLista.h"
#include "ListaSpesa.h"

int main() {
    // Crea una lista condivisa
    auto listaCondivisa = std::make_shared<ListaSpesa>();

    // Crea due observer che osservano la stessa lista
    auto osservatore1 = std::make_unique<ObserverConcrete>(listaCondivisa.get());
    auto osservatore2 = std::make_unique<ObserverConcrete>(listaCondivisa.get());

    // Crea due utenti che condividono la lista
    Utente alice("Alice");
    Utente bob("Bob");

    alice.aggiungiLista(listaCondivisa);
    bob.aggiungiLista(listaCondivisa);

    // Aggiungiamo oggetti alla lista
    listaCondivisa->aggiungiOggetto(OggettoLista("Latte", 2, "Alimentari"));
    listaCondivisa->aggiungiOggetto(OggettoLista("Sapone", 1, "Igiene"));
    listaCondivisa->aggiungiOggetto(OggettoLista("Mele", 6, "Frutta"));

    // Stampa dettagliata
    std::cout << "\nContenuto lista condivisa (visibile da Alice e Bob):\n";
    listaCondivisa->stampaOggettiDettagliati();

    // Rimuoviamo un oggetto
    std::cout << "\nBob rimuove 'Sapone' dalla lista...\n";
    listaCondivisa->rimuoviOggetto("Sapone");

    // Stampa aggiornata
    std::cout << "\nLista aggiornata:\n";
    listaCondivisa->stampaOggettiDettagliati();

    // Mostra le liste di ciascun utente
    std::cout << "\nUtenti e le loro liste:\n";
    for (const auto& lista : alice.getListe()) {
        std::cout << "- Alice ha una lista con i seguenti oggetti:\n";
        lista->stampaOggettiDettagliati();
    }

    for (const auto& lista : bob.getListe()) {
        std::cout << "- Bob ha una lista con i seguenti oggetti:\n";
        lista->stampaOggettiDettagliati();
    }

    return 0;
}
