#include "Fairy.h"
#define HP_NUM 10

Fairy::Fairy() :
        SurpriseCards("Fairy", HP_NUM)
{}

void Fairy::playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) {

    if(player->getJob() == "Wizard") {
        printFairyMessage(true);
        player->heal(m_hp);
    } else {
        printFairyMessage(false);
    }
}

void Fairy::printInheritance(std::ostream &os) const {
    printCardDetails(os,m_name);
    printEndOfCardDetails(os);
}

