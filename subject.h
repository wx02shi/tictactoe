#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <utility>

class Observer;

class Subject {
    std::vector<Observer *> observers;

public:
    void attach(Observer *observer);
    void detach(Observer *observer);
    virtual char getState(std::pair<int, int> pos) const = 0;
    virtual ~Subject() = default;
    void notifyObservers();
};

#endif