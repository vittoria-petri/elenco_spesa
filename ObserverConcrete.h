#ifndef OBSERVERCONCRETE_H
#define OBSERVERCONCRETE_H
#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <stdexcept>

class ObserverConcrete final : public Observer {
public:
    explicit ObserverConcrete(Subject *subject) : subject(subject) {
        if (!subject) {
            throw std::invalid_argument("Subject non può essere nullptr");
        }
        ObserverConcrete::attach();
    }
    // Costruttore di copia
    ObserverConcrete(const ObserverConcrete& other) : subject(other.subject) {
        attach();
    }

    // Operatore di assegnazione
    ObserverConcrete& operator=(const ObserverConcrete& other) {
        if (this != &other) {
            detach();
            subject = other.subject;
            attach();
        }
        return *this;
    }

    ~ObserverConcrete() override {
        std::cout << "ObserverConcrete: distruttore chiamato\n";
        ObserverConcrete::detach();
    }

    void attach() override {
        subject->registerObserver(this);
    }

    void detach() override {
        subject->removeObserver(this);
    }

    void update() override {
        std::cout << "ObserverConcrete: sono stato aggiornato!" << std::endl;
    }

private:
    Subject *subject;
};

#endif // OBSERVERCONCRETE_H