//
// Created by Vittoria Petri on 25/07/25.
//

#ifndef LISTASPESA_H
#define LISTASPESA_H
#include <list>
#include <iostream>
#include <stdexcept>
#include "Subject.h"
#include "OggettoLista.h"

class ListaSpesa : public Subject {
public:
  ListaSpesa() = default;

  void aggiungiOggetto(const OggettoLista& oggetto) {
    if (oggetto.getQuantita() <= 0) {
      throw std::invalid_argument("Quantità deve essere maggiore di zero.");
    }
    listaSpesa.push_back(oggetto);
    notify();
  }

  // Uso gli iteratori
  void rimuoviOggetto(const std::string& nome) {
    bool trovato = false;
    for (auto it = listaSpesa.begin(); it != listaSpesa.end(); ) {
      if (it->getNome() == nome) {
        it = listaSpesa.erase(it);
        trovato = true;
        notify();
      } else {
        ++it;
      }
    }
    if (!trovato) {
      throw std::runtime_error("Oggetto '" + nome + "' non trovato nella lista.");
    }
  }


  void getOggetti() const {
    for (const auto& oggetto : listaSpesa) {
      std::cout << oggetto.getNome() << std::endl;
    }
  }

  void stampaOggettiDettagliati() const {
  	for (const auto& oggetto : listaSpesa) {
    	std::cout << oggetto.getNome() << " x" << oggetto.getQuantita() << " [" << oggetto.getCategoria().getNome() << "]\n";
  	}
  }

  const std::list<OggettoLista>& getLista() const {
    return listaSpesa;
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
  std::list<OggettoLista> listaSpesa;
  std::list<Observer*> observers;
};

#endif //LISTASPESA_H

