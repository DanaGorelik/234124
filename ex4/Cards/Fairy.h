#ifndef PLAYER_CPP_FAIRY_H
#define PLAYER_CPP_FAIRY_H
#include "SurpriseCards.h"

class Fairy : public SurpriseCards {
public:
    Fairy();
    ~Fairy() override = default;
    void playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) override;
    void printInheritance(std::ostream & os) const override;
};


#endif //PLAYER_CPP_FAIRY_H
