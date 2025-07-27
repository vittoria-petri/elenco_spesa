#ifndef OGGETTOLISTA_H
#define OGGETTOLISTA_H
#include "Categoria.h"
#include <string>

class OggettoLista {
public:
    OggettoLista(std::string nome, int quantita, std::string categoria)
        : nome(nome), quantita(quantita), categoria(categoria) {}

    ~OggettoLista() = default;

    std::string getNome() const {
        return nome;
    }

    int getQuantita() const {
        return quantita;
    }

    Categoria getCategoria() const {
        return categoria;
    }

private:
    std::string nome;
    int quantita;
    Categoria categoria;
};

#endif // OGGETTOLISTA_H
