#ifndef OGGETTOLISTA_H
#define OGGETTOLISTA_H
#include <stdexcept>
#include "Categoria.h"
#include <string>

class OggettoLista {
public:
    // Controllo che i dati inseriti siano validi
    OggettoLista(const std::string& nome, int quantita, const Categoria& categoria)
    : nome(nome), quantita(quantita), categoria(categoria) {
        if (nome.empty()) throw std::invalid_argument("Nome oggetto non può essere vuoto");
        if (quantita <= 0) throw std::invalid_argument("Quantità deve essere positiva");
        if (categoria.getNome().empty()) throw std::invalid_argument("Categoria non può essere vuota");
    }

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
