#ifndef OBSERVERCONCRETE_H
#define OBSERVERCONCRETE_H

#include "Observer.h"
#include "Subject.h"
#include <iostream>

class ObserverConcrete : public Observer {
public:
  // Passa il Subject da osservare
  ObserverConcrete(Subject* subject) : subject(subject) {
    attach();
  }

  ~ObserverConcrete() override {
    std::cout << "ObserverConcrete: distruttore chiamato\n";
    detach();
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
