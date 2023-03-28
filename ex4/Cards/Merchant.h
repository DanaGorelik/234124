#ifndef PLAYER_H_MERCHANT_H
#define PLAYER_H_MERCHANT_H
#include "Card.h"
#include <iostream>

class Merchant : public Card {
public:
    Merchant();
    ~Merchant() override = default;
private:
    int m_hpCost;
    int m_forceCost;
    void playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) override;
    void doAction (int input, std::unique_ptr<Card> &card, std::unique_ptr<Player> &player, std::ostream &os) const;
    void printInheritance(std::ostream & os) const override;
};


#endif //PLAYER_H_MERCHANT_H
