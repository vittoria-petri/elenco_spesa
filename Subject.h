//
//
//

#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void registerObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notifyAll() = 0;

    virtual ~Subject() = default;
};


#endif //SUBJECT_H
