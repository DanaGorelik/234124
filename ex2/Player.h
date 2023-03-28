//
// Created by DELL on 03-May-22.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include <string>

class Player {

public:
    //Player();
    explicit Player(std::string name, int maxHP = 100, int force = 5);
    ~Player();
    Player(const Player&);
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int addForce);
    void heal(int addHP);
    void damage(int damageHP);
    bool isKnockedOut() const;
    void addCoins(int coinsNum);
    bool pay(int coinsNum);
    int getAttackStrength() const;

private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
};

#endif //EX2_PLAYER_H