//
// Created by DELL on 03-May-22.
//

#include "Player.h"
#include "utilities.h"
#define START_M_LEVEL 1
#define START_M_COINS 0
#define DEFAULT_M_FORCE 5
#define DEFAULT_M_MAX_HP 100
#define MAX_LEVEL 10

Player::Player(const std::string name, const int maxHP, const int force) :
        m_name(name),m_level(START_M_LEVEL), m_HP(maxHP), m_coins(START_M_COINS)
{
    if (force > 0)
    {
        this->m_force = force;
    }
    else {
        m_force = DEFAULT_M_FORCE;
    }
    if (maxHP > 0) {
        this->m_maxHP = maxHP;
    }
    else {
        m_maxHP = DEFAULT_M_MAX_HP;
    }
}

Player::~Player() = default;

Player::Player(const Player& player) {
    m_name = player.m_name;
    m_level = player.m_level;
    m_force = player.m_force;
    m_maxHP = player.m_maxHP;
    m_HP = player.m_HP;
    m_coins = player.m_coins;
}

void Player::printInfo() const {
    std::string cName = m_name;
    printPlayerInfo(cName.c_str() , m_level, m_force, m_maxHP, m_coins);
}

void Player::levelUp() {
    if (m_level < MAX_LEVEL) {
        m_level++;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int addForce) {
    if(addForce > 0) {
        m_force += addForce;
    }
}

void Player::heal(int addHP) {
    if (addHP > 0) {
        if (m_HP + addHP <= m_maxHP) {
            m_HP += addHP;
        }
        else {
            m_HP = m_maxHP;
        }
    }
}

void Player::damage(int damageHP) {
    if (damageHP > 0) {
        if (m_HP >= damageHP) {
            m_HP -= damageHP;
        }
        else {
            m_HP = 0;
        }
    }
}

bool Player::isKnockedOut() const {
    if(m_HP == 0) {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsNum) {
    if(coinsNum >= 0) {
        m_coins += coinsNum;
    }
}

bool Player::pay(int coinsNum) {
    if (coinsNum <= 0) {
        return true;
    }
    if(m_coins >= coinsNum) {
        m_coins -= coinsNum;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const {
    return (m_level + m_force);
}