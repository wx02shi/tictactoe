#include <iostream>
#include <vector>
#include "subject.h"
#include "observer.h"

using namespace std;

void Subject::attach(Observer *observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer *observer) {
    for (auto it = observers.begin(); it != observers.end();) {
        if (*it == observer)
            it = observers.erase(it);
        else
            ++it;
    }
}

void Subject::notifyObservers() {
    for (auto observer : observers)
        observer->notify();
}