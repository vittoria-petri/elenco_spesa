#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>

class Categoria {
public:
    explicit Categoria(const std::string &nome) : nome(nome) {
        if (nome.empty()) {
            throw std::invalid_argument("Il nome della categoria non può essere vuoto");
        }
    }

    std::string getNome() const {
        return nome;
    }

private:
    std::string nome;
};

#endif //CATEGORIA_H