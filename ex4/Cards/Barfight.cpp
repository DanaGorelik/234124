#include "Barfight.h"
#define HP_NUM 10

Barfight::Barfight() :
        SurpriseCards("Barfight", HP_NUM)
        {}

void Barfight::playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) {
    if(!(player->getJob() == "Fighter")) {
        printBarfightMessage(false);
        player->damage(m_hp);
    } else
        printBarfightMessage(true);
}

void Barfight::printInheritance(std::ostream &os) const {
    printCardDetails(os,m_name);
    printEndOfCardDetails(os);
}


