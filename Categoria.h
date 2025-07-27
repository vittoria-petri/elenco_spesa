//
// Created by Vittoria Petri on 25/07/25.
//

#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>
using namespace std;

class Categoria {
public:
  Categoria(const std::string& nome) : nome(nome) {}

  std::string getNome() const {
    return nome;
  }

private:
  std::string nome;
};

#endif //CATEGORIA_H
