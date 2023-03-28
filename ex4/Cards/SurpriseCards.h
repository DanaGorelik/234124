#ifndef PLAYER_CPP_SURPRISECARDS_H
#define PLAYER_CPP_SURPRISECARDS_H
#include "Card.h"


class SurpriseCards : public Card {
public:
    SurpriseCards(std::string name, int hp);
    ~SurpriseCards() override = default;
    void playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) override = 0;

protected:
    int m_hp;
};


#endif //PLAYER_CPP_SURPRISECARDS_H
