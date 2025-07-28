#ifndef OBSERVERCONCRETE_H
#define OBSERVERCONCRETE_H

#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <stdexcept>

class ObserverConcrete : public Observer {
public:
  // Passa il Subject da osservare e controllo che il puntatore non sia nullo
  explicit ObserverConcrete(Subject* subject) : subject(subject) {
    if (!subject) {
      throw std::invalid_argument("Subject non può essere nullptr");
    }
    ObserverConcrete::attach();
  }

  ~ObserverConcrete() override {
    std::cout << "ObserverConcrete: distruttore chiamato\n";
    ObserverConcrete::detach();
  }

  void attach() override {
      subject -> subscribe(this);
  }

  void detach() override {
      subject -> unsubscribe(this);
  }

  void update() override {
    std::cout << "ObserverConcrete: sono stato aggiornato!" << std::endl;
  }



private:
  Subject* subject;
};

#endif // OBSERVERCONCRETE_H
