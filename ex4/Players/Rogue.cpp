#include "Rogue.h"
#define DOUBLE_COINS_NUM 2

Rogue::Rogue(const std::string name, std::string job) :
        Player(name, job)
{}


void Rogue::addCoins(int coinsNum) {
    if (m_coins > 0) {
        m_coins += coinsNum * DOUBLE_COINS_NUM;
    }
}

Rogue::Rogue(std::string name):
Player(name, "Rogue")
{}