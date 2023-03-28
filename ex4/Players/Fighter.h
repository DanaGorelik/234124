//
// Created by DELL on 07-Jun-22.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"


class Fighter : public Player {


public:

    Fighter(const std::string name);
    int getAttackStrength() const override;
    ~Fighter() override = default;

};


#endif //EX4_FIGHTER_H
