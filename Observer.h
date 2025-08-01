//
// Created by Vittoria Petri on 23/07/25.
//

#ifndef OBSERVER_H
#define OBSERVER_H


class Observer {  // Lista Observer
public:
  virtual ~Observer() = default;
  virtual void update() = 0;
  virtual void attach() = 0;
  virtual void detach() = 0;
};

#endif //OBSERVER_H
