#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <utility>
#include <vector>
#include "player.h"
#include "subject.h"

class Board : public Subject {
    std::vector<std::vector<std::shared_ptr<Player>>> grid{3, std::vector<std::shared_ptr<Player>>(3)};
    std::shared_ptr<Player> px;
    std::shared_ptr<Player> po;
    char gameResult = 0;

public:
    Board();
    void clear();
    void setPiece(std::pair<int, int> pos, std::shared_ptr<Player> player);
    std::vector<std::pair<int, int>> getValidMoves();
    char getState(std::pair<int, int> pos) const override;
    void updateGameResult();
    char getGameResult();
    std::shared_ptr<Player> getPx();
    std::shared_ptr<Player> getPo();
};

#endif