#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include <memory>
#include <iostream>
#include <deque>

#include "Players/Player.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"

#include "Cards/Card.h"
#include "Cards/Goblin.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Barfight.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
#include "Cards/Gang.h"

const int MAX_NUMBER_OF_ROUNDS = 100;

class Mtmchkin {

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    Mtmchkin(const Mtmchkin& mtmchkin)=delete;
    Mtmchkin& operator=(const Mtmchkin& mtmchkin)=delete;

    ~Mtmchkin()=default;
    bool addPlayerToQueue(std::string& name, std::string& character);
    bool addCardToQueue(std::string& name);
    void addGangCardToQueue(std::string& name, bool gangMode);
    void buildCardsQueue(const std::string &fileName);

    //checks user details functions
    int ValidNumPlayers();
    bool checkCharacter (std::string& character) const;
    bool chekValidCardName(std::string& name, bool gangMode);
    bool checkValidFile(const std::string& fileName);
    bool ValidNameLength(std::string& name) const;
    void ValidUserDetails(int numPlayers);

private:
    std::queue<std::unique_ptr<Card>> m_cardsQueue;
    std::deque<std::unique_ptr<Player>> m_playersQueue;
    std::vector<std::unique_ptr<Player>> m_winners;
    std::vector<std::unique_ptr<Player>> m_losers;
    std::vector<std::string> m_monsters;
    int m_round;

    //adding cards functions
    bool addWizard(std::string &name);

    bool addFighter(std::string &name);

    bool addRogue(std::string &name);

    bool addFairy();

    bool addBarfight();

    bool addPitfall();

    bool addTreasure();

    bool addMerchant();

    bool addDragon();

    bool addVampire();

    bool addGoblin();

    bool ValidCharacter(std::string &name) const;

    bool checkUserName(std::string &nameOfPlayer);
};

#endif /* MTMCHKIN_H_ */