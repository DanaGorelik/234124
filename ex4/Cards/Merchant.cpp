#include "Merchant.h"
#define HP_COST 5
#define FORCE_COST 10
#define NO_ACTION 0
#define BUY_HP 1
#define BUY_FORCE 2
#define NO_PAYMENT 0
#define DECREASE -1
#define SINGLE_HP 1
#define SINGLE_FORCE 1

Merchant::Merchant() :
        Card("Merchant"),
        m_hpCost(HP_COST),
        m_forceCost(FORCE_COST)
        {}

void Merchant::playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player) {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player->getName(), player->getCoins());
    int input;
    std::cin >> input;
    while ((input != NO_ACTION) && (input != BUY_HP) && (input != BUY_FORCE)) {
        printInvalidInput();
        std::cin.clear();
        printMerchantInitialMessageForInteractiveEncounter(std::cout, player->getName(), player->getCoins());
        std::cin >> input;
    }
    doAction(input, card, player, std::cout);
}

void Merchant::doAction (int input, std::unique_ptr<Card> &card, std::unique_ptr<Player> &player, std::ostream &os) const {
    if (input == NO_ACTION) {
        printMerchantSummary(os, player->getName(), NO_ACTION, NO_PAYMENT);
    } else if (input == BUY_HP) {
        if (player->getCoins() >= m_hpCost) {
            player->addCoins(DECREASE * m_hpCost);
            player->heal(SINGLE_HP);
            printMerchantSummary(os, player->getName(), BUY_HP, m_hpCost);
        } else {
            printMerchantInsufficientCoins(os);
        }
    } else if (input == BUY_FORCE) {
        if (player->getCoins() >= m_forceCost) {
            player->addCoins(DECREASE * m_forceCost);
            player->buff(SINGLE_FORCE);
            printMerchantSummary(os, player->getName(), BUY_FORCE, m_forceCost);
        } else {
            printMerchantInsufficientCoins(os);
        }
    }
}

void Merchant::printInheritance(std::ostream &os) const {
    printCardDetails(os,m_name);
    printEndOfCardDetails(os);
}

