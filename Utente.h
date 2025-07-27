//
// Created by Vittoria Petri on 25/07/25.
//

#ifndef UTENTE_H
#define UTENTE_H
#include "ListaSpesa.h"
#include <string>
#include <list>
#include <memory>
using namespace std;


class Utente {
public:
  Utente(std::string nome) : nome(nome) {}

  void aggiungiLista(shared_ptr<ListaSpesa> lista) {
    liste.push_back(lista);
  }

  const std::list<std::shared_ptr<ListaSpesa>>& getListe() const {
    return liste;
  }

  string getNomeUtente() const {
    return nome;
  }

private:
  string nome;
  list<std::shared_ptr<ListaSpesa>> liste;
};


#endif //UTENTE_H
