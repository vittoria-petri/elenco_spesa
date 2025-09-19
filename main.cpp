#include <iostream>
#include <memory>           // std::shared_ptr, std::make_shared
#include <stdexcept>        // per std::runtime_error
#include "Utente.h"
#include "ObserverConcrete.h"
#include "OggettoLista.h"
#include "ListaSpesa.h"

int main() {
    // Crea una lista condivisa
    auto listaCondivisa = std::make_shared<ListaSpesa>();

    // Crea due observer che osservano la stessa lista
    auto osservatore1 = std::make_shared<ObserverConcrete>(listaCondivisa.get());
    auto osservatore2 = std::make_shared<ObserverConcrete>(listaCondivisa.get());

    // Crea due utenti che condividono la lista
    Utente alice("Alice");
    Utente bob("Bob");

    alice.aggiungiLista(listaCondivisa);
    bob.aggiungiLista(listaCondivisa);
    Categoria alimentari("Alimentari");
    Categoria igiene("Igiene");
    Categoria frutta("Frutta");
    // Aggiungiamo oggetti alla lista
    listaCondivisa->aggiungiOggetto(OggettoLista("Latte", 2, alimentari));
    listaCondivisa->aggiungiOggetto(OggettoLista("Sapone", 1, igiene));
    listaCondivisa->aggiungiOggetto(OggettoLista("Mele", 6, frutta));


    // Stampa dettagliata
    std::cout << "\nContenuto lista condivisa (visibile da Alice e Bob):\n";
    listaCondivisa->stampaOggettiDettagliati();

    // Rimuoviamo un oggetto esistente
    std::cout << "\nBob rimuove 'Sapone' dalla lista...\n";
    try {
        listaCondivisa->rimuoviOggetto("Sapone");
    } catch (const std::runtime_error &e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    // Rimuoviamo un oggetto **NON esistente** per vedere l’eccezione
    std::cout << "\nBob prova a rimuovere 'Pane' (non presente)...\n";
    try {
        listaCondivisa->rimuoviOggetto("Pane");
    } catch (const std::runtime_error &e) {
        std::cerr << "Eccezione catturata: " << e.what() << std::endl;
    }

    // Stampa aggiornata
    std::cout << "\nLista aggiornata:\n";
    listaCondivisa->stampaOggettiDettagliati();


    // Mostra le liste di ciascun utente
    std::cout << "\nUtenti e le loro liste:\n";
    for (const auto &lista: alice.getListe()) {
        std::cout << "- Alice ha una lista con i seguenti oggetti:\n";
        lista->stampaOggettiDettagliati();
    }

    for (const auto &lista: bob.getListe()) {
        std::cout << "- Bob ha una lista con i seguenti oggetti:\n";
        lista->stampaOggettiDettagliati();
    }

    return 0;
}
