#ifndef EX4_CARD_H
#define EX4_CARD_H

#include "../Players/Player.h"
#include "../submission (1)/utilities.h"

//enum class cardName {Goblin, Vampire, Dragon, Merchant, Treasure, Pitfall, Barfight, Fairy}; // The name of the Card

class Card {
public:
    explicit Card(std::string name);
    virtual ~Card() = default;
    virtual void playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) = 0;
    std::string getName() const;
  //  virtual std::ostream& operator<<(std::ostream& os)=0;

     virtual void printInheritance(std::ostream& os) const = 0;

protected:
    std::string m_name;
};


std::ostream& operator<<(std::ostream& os, const Card& card);


#endif //EX4_CARD_H
