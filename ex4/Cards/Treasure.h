#ifndef PLAYER_H_TREASURE_H
#define PLAYER_H_TREASURE_H
#include "Card.h"

class Treasure : public Card{
public:
    Treasure();
    ~Treasure() override = default;
    void playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) override;
    void printInheritance(std::ostream & os) const override;
private:

    int m_coins;
};

#endif //PLAYER_H_TREASURE_H
