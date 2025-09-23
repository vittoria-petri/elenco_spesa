#ifndef UTENTE_H
#define UTENTE_H
#include "ListaSpesa.h"
#include <string>
#include <list>
#include <memory>

class Utente {
public:
    explicit Utente(const std::string &nome) : nome(nome) {
        if (nome.empty()) {
            throw std::invalid_argument("Il nome non può essere vuoto");
        }
    }

    void aggiungiLista(const std::shared_ptr<ListaSpesa> &lista) {
        liste.push_back(lista);
    }

    const std::list<std::shared_ptr<ListaSpesa> > &getListe() const {
        return liste;
    }

    std::string getNomeUtente() const {
        return nome;
    }

private:
    std::string nome;
    std::list<std::shared_ptr<ListaSpesa> > liste;
};

#endif //UTENTE_H