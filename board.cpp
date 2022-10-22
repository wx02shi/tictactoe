#include <memory>
#include <utility>
#include "board.h"

using namespace std;

Board::Board() {
    px = make_shared<Player>('X');
    po = make_shared<Player>('O');
    clear();
}

void Board::clear() {
    for (auto &i : grid) {
        for (auto &j : i) {
            j = nullptr;
        }
    }
    gameResult = 0;
}

void Board::setPiece(pair<int, int> pos, shared_ptr<Player> player) {
    grid[pos.first][pos.second] = player;
}

vector<pair<int, int>> Board::getValidMoves() {
    vector<pair<int, int>> result;
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid.size(); col++) {
            if (grid[row][col] == nullptr) {
                result.push_back(make_pair(row, col));
            }
        }
    }
    return result;
}

char Board::getState(pair<int, int> pos) const {
    auto piece = grid[pos.first][pos.second];
    if (piece == NULL)
        return 0;
    else
        return piece->getType();
}

void Board::updateGameResult() {
    // Check for a win first
    // check rows
    for (int row = 0; row < grid.size(); row++) {
        auto first = grid[row][0];
        int count = 1;
        if (first != nullptr) {
            for (int col = 1; col < grid.size(); col++) {
                if (grid[row][col] == first)
                    count++;
                else
                    break;
            }
        }

        if (count == grid.size()) {
            gameResult = first->getType();
            return;
        }
    }

    // check columns
    for (int col = 0; col < grid.size(); col++) {
        auto first = grid[0][col];
        int count = 1;
        if (first != nullptr) {
            for (int row = 1; row < grid.size(); row++) {
                if (grid[row][col] == first)
                    count++;
                else
                    break;
            }
        }
        if (count == grid.size()) {
            gameResult = first->getType();
            return;
        }
    }

    // check equal diagonal
    auto first = grid[0][0];
    int count = 1;
    if (first != nullptr) {
        for (int i = 1; i < grid.size(); i++) {
            if (grid[i][i] == first)
                count++;
            else
                break;
        }
    }
    if (count == grid.size()) {
        gameResult = first->getType();
        return;
    }

    // check complement diagonal
    first = grid[0][grid.size() - 1];
    count = 1;
    if (first != nullptr) {
        for (int i = 1; i < grid.size(); i++) {
            if (grid[i][grid.size() - 1 - i] == first)
                count++;
            else
                break;
        }
    }
    if (count == grid.size()) {
        gameResult = first->getType();
        return;
    }

    // check for a full board for a tie
    bool isFull = true;
    for (auto row : grid) {
        for (auto col : row) {
            if (col == nullptr) { // board is not full
                return;
            }
        }
    }
    gameResult = '=';
}

char Board::getGameResult() {
    return gameResult;
}

shared_ptr<Player> Board::getPx() {
    return px;
}

shared_ptr<Player> Board::getPo() {
    return po;
}
