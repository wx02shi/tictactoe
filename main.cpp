#include <algorithm>
#include <iostream>
#include "board.h"
#include "textObserver.h"
#include "player.h"

using namespace std;

void nextTurn(shared_ptr<Player> &turn, Board *board) {
    if (turn == board->getPx()) {
        turn = nullptr;
        turn = board->getPo();
    } else {
        turn = nullptr;
        turn = board->getPx();
    }
}

pair<int, int> translatePos(string pos) {
    return make_pair(pos[0] - '1', pos[2] - '1');
}

int main() {
    string cmd;
    Board *board = new Board();
    TextObserver *to = new TextObserver(board);
    shared_ptr<Player> turn = board->getPx();
    char result = 0;

    cout << "Type help for a list of commands..." << endl;
    board->notifyObservers();
    cout << "Turn: " << turn->getType() << endl;

    while (cin >> cmd) {
        if (cmd == "clear") {
            board->clear();
            turn = board->getPx();
            result = 0;
            board->notifyObservers();
        } else if (cmd == "quit") {
            cout << "Thanks for playing!" << endl;
            break;
        } else if (cmd == "help") {
            cout << "i,j" << endl;
            cout << "   enter coordinates i and j to insert a piece" << endl;
            cout << "clear" << endl;
            cout << "   restarts the game" << endl;
            cout << "quit" << endl;
            cout << "   exits the program" << endl;
            cout << endl;
        } else {
            /**
             * @brief Inputted coordinate must have a NON-SPACE separator character,
             * and must be of length 3,
             * 
             * E.g.
             * 2,3
             * 2/3
             */
            auto pos = translatePos(cmd);
            auto validMoves = board->getValidMoves();
            if (result != 0) {
                cout << "The game has ended! Type 'clear' to start a new game." << endl;
            } else if (find(validMoves.begin(), validMoves.end(), pos) != validMoves.end()) {
                board->setPiece(pos, turn);
                board->notifyObservers();
                board->updateGameResult();
                result = board->getGameResult();
                if (result == '=') {
                    cout << "Tie game!" << endl;
                } else if (result != 0) {
                    cout << result << " wins!" << endl;
                } else {
                    nextTurn(turn, board);
                    cout << "Turn: " << turn->getType() << endl;
                }
            } else {
                cout << "Cannot move to (" << pos.first + 1 << ", " << pos.second + 1 << ")!" << endl;
            }
        }
    }
    delete to;
}