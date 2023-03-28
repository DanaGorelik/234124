#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include "Player.h"


class Rogue : public Player {

public:

    explicit Rogue(std::string name);
    explicit Rogue(std::string name, std::string job);
    void addCoins(int coinsNum) override;
    ~Rogue() override = default;
};


#endif //EX4_ROGUE_H
