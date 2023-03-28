#include "Player.h"
#include "../submission (1)/utilities.h"
#define START_M_LEVEL 1
#define START_M_COINS 10
#define DEFAULT_M_FORCE 5
#define DEFAULT_M_MAX_HP 100
#define MAX_LEVEL 10
#define BEGINNING 0
#define FORCE_UNDER_ZERO -1

Player::Player(const std::string name, const std::string job):
        m_name(name), m_job(job),m_level(START_M_LEVEL), m_force(DEFAULT_M_FORCE),m_maxHP(DEFAULT_M_MAX_HP),
        m_HP(DEFAULT_M_MAX_HP), m_coins(START_M_COINS), m_rank(BEGINNING)
{}

Player::Player(const Player& player) {
    m_name = player.m_name;
    m_job=player.m_job;
    m_level = player.m_level;
    m_force = player.m_force;
    m_maxHP = player.m_maxHP;
    m_HP = player.m_HP;
    m_coins = player.m_coins;
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

    if (m_force+addForce <= 0)
    {
        m_force = 0;
    }
    else {
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
    } else
    if (damageHP==(FORCE_UNDER_ZERO))
    {
        m_HP = 0;
    }
}


void Player::addCoins(int coinsNum) {
    m_coins += coinsNum;
}

void Player::pay(int coinsNum) {
    if ((m_coins - coinsNum) > 0) {
        m_coins -= coinsNum;
    }
    else {
        m_coins = 0;
    }
}

int Player::getAttackStrength() const {
    return (m_level + m_force);
}

std::ostream& operator<<(std::ostream  &os, const Player& player)  {
    printPlayerDetails(os, player.m_name, player.m_job, player.m_level, player.m_force, player.m_HP, player.m_coins);
    return os;
}

int Player::getHP() const {
    return m_HP;
}

bool Player::hasWon()
{
    if (this->getLevel() == WIN)
    {
        return true;
    }
    return false;
}
bool Player::hasLost()
{
    if (this->getHP() == LOSE)
    {
        return true;
    }
    return false;
}

int Player::getCoins() const {
    return m_coins;
}

std::string Player::getName() const {
    return m_name;
}

std::string Player::getJob() const {
    return m_job;
}

