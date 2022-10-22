#ifndef TEXT_OBSERVER_H
#define TEXT_OBSERVER_H

#include <iostream>
#include "observer.h"
#include "board.h"

class TextObserver : public Observer {
    Board *subject;
    std::ostream &out = std::cout;

public:
    TextObserver(Board *board);
    void notify() override;
    ~TextObserver();
};

#endif