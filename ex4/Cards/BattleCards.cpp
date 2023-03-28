#include "BattleCards.h"
#define SINGLE_FORCE -1

BattleCards::BattleCards(std::string name, int force, int loot, int damage) :
        Card(name),
        m_force(force),
        m_loot(loot),
        m_damage(damage)
{}

//if a player is in gangmode and lost, he continues to lose all the rest of the function
bool BattleCards::playCard(std::unique_ptr<Player> &player, bool gangMode, bool hasWon) {
    if(hasWon && (player->getAttackStrength()) >= m_force) {
        if (!gangMode) {
            player->levelUp();
            printWinBattle(player->getName(), m_name);
        }
        player->addCoins(m_loot);
        return true;
    }
    else {
        player->damage(m_damage);
        if (m_name == "Vampire") {
            player->buff(SINGLE_FORCE);
        }
        printLossBattle(player->getName(), m_name);
        return false;
    }
}

void BattleCards::printInheritance(std::ostream &os) const {
    printCardDetails(os, m_name);
    bool isDragon = false;
    if (m_damage == (SINGLE_FORCE)) {
        isDragon = true;
    }
    printMonsterDetails(os,m_force,m_damage,m_loot,isDragon);
    printEndOfCardDetails(os);
}