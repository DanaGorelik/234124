#include "Treasure.h"
#define COINS_NUM 10

Treasure::Treasure() :
        Card("Treasure"),
        m_coins(COINS_NUM)
        {}

void Treasure::playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) {
    player->addCoins(m_coins);
    printTreasureMessage();
}

void Treasure::printInheritance(std::ostream &os) const {
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

