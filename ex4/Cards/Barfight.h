#ifndef PLAYER_CPP_BARFIGHT_H
#define PLAYER_CPP_BARFIGHT_H
#include "SurpriseCards.h"

class Barfight : public SurpriseCards {
public:
    Barfight();
    ~Barfight() override = default;
    void playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) override;
    void printInheritance(std::ostream & os) const override;
};

#endif //PLAYER_CPP_BARFIGHT_H
