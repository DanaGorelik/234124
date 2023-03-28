#ifndef PLAYER_H_BATTLECARDS_H
#define PLAYER_H_BATTLECARDS_H
#include "Card.h"
#include <memory>

class BattleCards : public Card{

public:
     BattleCards(std::string name, int force, int loot, int damage);
    ~BattleCards() override = default;
    void playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) override;
    static std::string getName(std::string &name);
    void printInheritance(std::ostream & os) const override;

protected:
    int m_force;
    int m_loot;
    int m_damage;
};


#endif //PLAYER_H_BATTLECARDS_H
