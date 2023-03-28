#include "Pitfall.h"
#define HP_NUM 10

Pitfall::Pitfall() :
        SurpriseCards("Pitfall", HP_NUM) {}

void Pitfall::playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) {
    if(!(player->getJob() == "Rogue")) {
        printPitfallMessage(false);
       player->damage(m_hp);
    } else
    {
        printPitfallMessage(true);
    }
}

void Pitfall::printInheritance(std::ostream &os) const {
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}
