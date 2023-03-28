#include <string>
#include <fstream>
#include <iostream>
#include <deque>

#include "Mtmchkin.h"

#define MINIMUM_NUM_CARDS 5
#define MIN_NAME_LENGTH 1
#define MAX_NAME_LENGTH 15
#define MIN_PLAYERS_AMOUNT 2
#define MAX_PLAYERS_AMOUNT 6
#define EXTRA_CHAR 1
#define DIGIT_LENGTH 1

//Constructor of Mtmchkin class:
Mtmchkin::Mtmchkin(const std::string fileName) :

        m_cardsQueue(),
        m_playersQueue(),
        m_winners(),
        m_losers(),
        m_round(0) //Before first round
{
    printStartGameMessage();
    std::ifstream file(fileName);
    if (!file) {
        throw DeckFileNotFound("Deck File Error: File not found");
    }
    checkValidFile(fileName);
    buildCardsQueue(fileName);

    int numPlayers = ValidNumPlayers(); //beginning of the game - checks input number of players
    ValidUserDetails(numPlayers);
}

///////////////////////////////////Functions of cards queue from constructor//////////////////////////////////

//Checks if the content of the file is valid:
bool Mtmchkin::checkValidFile(const std::string &fileName) {
    int counter = 0;
    bool gangMode = false;
    std::ifstream file;
    std::string line;
    file.open(fileName);
    if (file.is_open()) {
        while (!file.eof()) {
            if (getline(file, line)) {
                if ((line == "EndGang") && !gangMode) {
                    throw DeckFileFormatError("Deck File Error: File format error in line ", counter + 1);
                }
                if (line == "Gang") {
                    gangMode = true;
                }
                if (line == "EndGang") {
                    gangMode = false;
                }
                if ((line != "Gang") && (line != "EndGang") && (!(chekValidCardName(line, gangMode)))) {
                    throw DeckFileFormatError("Deck File Error: File format error in line ", counter + 1);
                }
                if (!gangMode) {
                    counter++;
                }
            }
        }
    }
    if (counter < MINIMUM_NUM_CARDS) {
        throw DeckFileInvalidSize("Deck File Error: Deck size is invalid");
    }
    return true;
}

//Checks if the given card name from the file is valid:
bool Mtmchkin::chekValidCardName(std::string& name, bool gangMode) {
    if ((!gangMode) && ((name == "Goblin") || (name == "Vampire") || (name == "Dragon") || (name == "Merchant") ||
                        (name == "Treasure") || (name == "Pitfall") || (name == "Barfight") || (name == "Fairy")
                        || (name == "EndGang"))) {
        return true;
    }
    if (gangMode && ((name == "Goblin") || (name == "Vampire") || (name == "Dragon"))) {
        return true;
    }
    return false;
}

void Mtmchkin::buildCardsQueue(const std::string &fileName) {
    std::ifstream file;
    std::string line;
    bool gangMode = false;
    file.open(fileName);
    while (!file.eof()) {
        getline(file, line);
        if (line == "Gang") {
            gangMode = true;
        }
        else {
            if (line == "EndGang") {
                gangMode = false;
            }
        }
        if (!gangMode && (line != "EndGang")) {
            addCardToQueue(line);
        }
        else if (gangMode && (line != "Gang")) {
            addGangCardToQueue(line, true);
        }
        else if (!gangMode && (line == "EndGang")) {
            addGangCardToQueue(line, false);
        }
    }
}

//Adds to the cards queue each card name given in the list:
bool Mtmchkin::addCardToQueue(std::string& name) {
    if (name == "Goblin") {
        if (addGoblin())
        {
            return true;
        }
    } else if (name == "Vampire") {
        if (addVampire())
        {
            return true;
        }
    } else if (name == "Dragon") {
        if (addDragon())
        {
            return true;
        }
    } else if (name == "Merchant") {
        if (addMerchant())
        {
            return true;
        }
    } else if (name == "Treasure") {
        if (addTreasure())
        {
            return true;
        }
    } else if (name == "Pitfall") {
        if (addPitfall())
        {
            return true;
        }
    } else if (name == "Fairy")
    {
        if (addFairy())
        {
            return true;
        }
    } else if (name == "Barfight")
    {
        if (addBarfight())
        {
            return true;
        }
    }
    return false;
}

void Mtmchkin::addGangCardToQueue(std::string& name, bool gangMode) {
    if (gangMode) {
        m_monsters.push_back(name);
    }
    else {
        try {
            std::unique_ptr<Card> gang(new Gang(m_monsters));
            m_cardsQueue.push(std::move(gang));
        }
        catch (const std::bad_alloc &e) {
            std::cerr << "Out of memory: " << e.what() << std::endl;
        }
        m_monsters.clear();
    }
}

bool Mtmchkin::addGoblin()
{
    try {
        std::unique_ptr<Card> goblin(new Goblin());
        m_cardsQueue.push(std::move(goblin));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}


bool Mtmchkin::addVampire()
{
    try {
        std::unique_ptr<Card> vampire(new Vampire());
        m_cardsQueue.push(std::move(vampire));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool Mtmchkin::addDragon()
{
    try {
        std::unique_ptr<Card> dragon(new Dragon());
        m_cardsQueue.push(std::move(dragon));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool Mtmchkin::addMerchant()
{
    try {
        std::unique_ptr<Card> merchant(new Merchant());
        m_cardsQueue.push(std::move(merchant));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool Mtmchkin::addTreasure()
{
    try {
        std::unique_ptr<Card> treasure(new Treasure());
        m_cardsQueue.push(std::move(treasure));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool Mtmchkin::addPitfall()
{
    try {
        std::unique_ptr<Card> pitfall(new Pitfall());
        m_cardsQueue.push(std::move(pitfall));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool Mtmchkin::addFairy()
{
    try {
        std::unique_ptr<Card> fairy(new Fairy());
        m_cardsQueue.push(std::move(fairy));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool Mtmchkin::addBarfight()
{
    try {
        std::unique_ptr<Card> barfight(new Barfight());
        m_cardsQueue.push(std::move(barfight));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}

///////////////////////////////////Functions of players queue from constructor//////////////////////////////////

//Checks if the given number of players is valid (If the given input is a number between 2-6):
int Mtmchkin::ValidNumPlayers() {

    int numPlayers;
    std::string lineNumPlayers;
    bool valid = false;
    printEnterTeamSizeMessage();
    while (!valid){
        std::getline(std::cin, lineNumPlayers);
        if (lineNumPlayers.size() > DIGIT_LENGTH)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        } else {
            try {
                numPlayers = std::stoi(lineNumPlayers);
            }
            catch (...) {
                printInvalidTeamSize();
                printEnterTeamSizeMessage();
                continue;
            }
            if (numPlayers < MIN_PLAYERS_AMOUNT || numPlayers > MAX_PLAYERS_AMOUNT) {
                printInvalidTeamSize();
                printEnterTeamSizeMessage();
                continue;
            } else {
                valid = true;
            }
        }
    }

    return numPlayers;
}

//Checks if the given name of player and the chosen character is valid:
void Mtmchkin::ValidUserDetails(int numPlayers) {
    std::string lineOfName, nameOfPlayer, character;
    while (numPlayers > 0) {
        printInsertPlayerMessage();
        int valid = false;
        while (!valid) { //adding players to the playerQueue.
            std::getline(std::cin, lineOfName);
            size_t space = lineOfName.find(' ');
            nameOfPlayer = lineOfName.substr(0, space);
            character = lineOfName.substr(space + EXTRA_CHAR, lineOfName.size() + EXTRA_CHAR);
            if (!checkUserName(nameOfPlayer))
            {
                printInvalidName();
            }
            else if (!checkCharacter(character))
            {
                printInvalidClass();
            }
            else {
                valid = true;
            }
        }
        if (addPlayerToQueue(nameOfPlayer,character))
        {
            numPlayers--;
        }
    }
}

bool Mtmchkin::checkUserName(std::string& nameOfPlayer)
{
    if (!ValidNameLength(nameOfPlayer) || !ValidCharacter(nameOfPlayer)) {
        return false;
    }
    return true;
}

bool Mtmchkin::ValidNameLength(std::string& name) const
{
    return (name.length() < MAX_NAME_LENGTH && name.length() > MIN_NAME_LENGTH);
}

bool Mtmchkin::ValidCharacter(std::string& name) const
{
    for (int i = 0; i < (int)name.length(); i++) {
        if (isalpha(name[i])==0) {
            return false;
        }
    }
    return true;
}

bool Mtmchkin::checkCharacter (std::string& character) const
{
    return (character == "Wizard" || character == "Rogue" || character == "Fighter");
}

//Adds each given player to the players queue:
bool Mtmchkin::addPlayerToQueue(std::string& name, std::string& character) {
    if (character == "Wizard") {
        if (addWizard(name))
        {
            return true;
        }
    } else if (character == "Fighter") {
        if (addFighter(name))
        {
            return true;
        }
    }
    else if (character == "Rogue") {
        if (addRogue(name))
        {
            return true;
        }
    } else {
        printInvalidClass();
    }
    return false;
}

bool Mtmchkin::addWizard(std::string& name)
{
    try {
        std::unique_ptr<Player> wizard(new Wizard(name));
        m_playersQueue.push_back(std::move(wizard));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool Mtmchkin::addFighter(std::string& name)
{
    try {
        std::unique_ptr<Player> fighter(new Fighter(name));
        m_playersQueue.push_back(std::move(fighter));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool Mtmchkin::addRogue(std::string& name)
{
    try {
        std::unique_ptr<Player> rogue(new Rogue(name));
        m_playersQueue.push_back(std::move(rogue));
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Out of memory: " << e.what() << std::endl;
        return false;
    }
    return true;
}

///////////////////////////////////Main functions of Mtmchkin Class//////////////////////////////////

//Plays a whole round of the game, in which each player receives a card and follows the instructions of it:
void Mtmchkin::playRound()
{
    if (m_round > MAX_NUMBER_OF_ROUNDS)
    {
        throw RoundLimit("You have reached the max round");
    }
    printRoundStartMessage((++m_round));
    int lengthOfQueue = (int)m_playersQueue.size();

    for (int i = 0; i < lengthOfQueue; i++)
    {
        printTurnStartMessage(m_playersQueue.front()->getName());
        std::unique_ptr<Player> currPlayer = std::move(m_playersQueue.front());
        m_playersQueue.pop_front();

        std::unique_ptr<Card> currCard = std::move(m_cardsQueue.front());
        m_cardsQueue.pop();
        if (currCard->getName() != "Gang") {
            currCard->playCard(currPlayer, false, true);
        }
        else {
            currCard->playCard(currPlayer, true, true);
        }

        if (currPlayer->hasWon()) {
            m_winners.push_back(std::move(currPlayer));
        } else if (currPlayer->hasLost()) {
            m_losers.push_back(std::move(currPlayer));
        } else {
            m_playersQueue.push_back(std::move(currPlayer)); //if player hasn't won or lost, add him back to the deque
        }

        m_cardsQueue.push(std::move(currCard));
        if (isGameOver()) {
            printGameEndMessage();
        }
    }
}

bool Mtmchkin::isGameOver() const {

    if (m_playersQueue.empty()) {
        return true;
    }
    return false;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_round;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int j = 1;
    for (unsigned int i = 0; i < m_winners.size(); i++) {
        printPlayerLeaderBoard(j, *(m_winners.at(i)));
        j++;
    }
    for (std::unique_ptr <Player> const &it: m_playersQueue) {
        printPlayerLeaderBoard(j, *it);
        j++;
    }
    for (int i = (int)m_losers.size(); i > 0; i--) {
        printPlayerLeaderBoard(j,*( m_losers.at(i - 1)));
        j++;
    }
}