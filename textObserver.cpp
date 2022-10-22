#include <iostream>
#include "textObserver.h"

using namespace std;

TextObserver::TextObserver(Board *board) : subject{board} {
    subject->attach(this);
}

void TextObserver::notify() {
    const int GRID_SIZE = 3;

    for (int i = 0; i < GRID_SIZE; i++) {
        if (i != 0) {
            out << "-+-+-" << endl;
        }
        for (int j = 0; j < GRID_SIZE; j++) {
            if (j != 0) {
                out << '|';
            }
            char piece = subject->getState(make_pair(i, j));
            if (piece == 0)
                out << ' ';
            else
                out << piece;
        }
        out << endl;
    }
};

TextObserver::~TextObserver() {
    subject->detach(this);
}