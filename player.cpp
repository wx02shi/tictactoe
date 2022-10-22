#include "player.h"

Player::Player(char type) : type{type} {}

char Player::getType() {
    return type;
}