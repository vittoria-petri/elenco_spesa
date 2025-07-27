//
// Created by Vittoria Petri on 25/07/25.
//

#ifndef LISTASPESA_H
#define LISTASPESA_H
#include <list>
#include <iostream>
using namespace std;
#include "Subject.h"
#include "OggettoLista.h"

class ListaSpesa : public Subject {
public:
  ListaSpesa() = default;

  void registra() {}

  void aggiungiOggetto(const OggettoLista& oggetto) {
    listaSpesa.push_back(oggetto);
    notify();
  }

  // Uso gli iteratori
  void rimuoviOggetto(const string& nome) {
    for (auto it = listaSpesa.begin(); it != listaSpesa.end(); ++it) {
      if (it->getNome() == nome) {
        listaSpesa.erase(it);
          notify();
      }
    }
  }

  void getOggetti() const {
    for (const auto& oggetto : listaSpesa) {
      cout << oggetto.getNome() << endl;
    }
  }

  void stampaOggettiDettagliati() const {
  	for (const auto& oggetto : listaSpesa) {
    	std::cout << oggetto.getNome() << " x" << oggetto.getQuantita() << " [" << oggetto.getCategoria().getNome() << "]\n";
  	}
  }

  void subscribe(Observer* o) override {
    observers.push_back(o);
  }

  void unsubscribe(Observer* o) override {
    observers.remove(o);
  }

  void notify() override {
    // Copia gli observer per evitare modifiche durante l'iterazione
    auto copiaObservers = observers;
    for (auto* o : copiaObservers) {
      if (o) o->update();
    }
  }

private:
  list<OggettoLista> listaSpesa;
  list<Observer*> observers;
};

#endif //LISTASPESA_H

