#ifndef PLAYER_CPP_PITFALL_H
#define PLAYER_CPP_PITFALL_H
#include "SurpriseCards.h"

class Pitfall : public SurpriseCards {
public:
    Pitfall();
    ~Pitfall() override = default;
    void playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) override;
    void printInheritance(std::ostream & os) const override;
};


#endif //PLAYER_CPP_PITFALL_H
