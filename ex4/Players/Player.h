#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>
#include <memory>

#define WIN 10
#define LOSE 0

class Player {


public:
    Player(std::string name, std::string job);
    virtual ~Player()=default;
    Player(const Player&);
    void levelUp();
    int getLevel() const;
    int getCoins() const;
    void pay(int coinsNum);
    int getHP() const;
    void buff(int addForce);
    virtual void heal(int addHP);
    void damage(int damageHP);
    virtual void addCoins(int coinsNum);
    virtual int getAttackStrength() const;
    std::string getName() const;
    std::string getJob() const;

    bool hasWon();
    bool hasLost();

    friend std::ostream& operator<<(std::ostream& os, const Player& player) ;

protected:

    std::string m_name;
    std::string m_job;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
    int m_rank;
};

#endif //EX4_PLAYER_H