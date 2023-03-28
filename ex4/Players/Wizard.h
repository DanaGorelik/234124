//
// Created by DELL on 07-Jun-22.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"

class Wizard : public Player{

public:

    explicit Wizard(const std::string& name);
    void heal(int addHP) override;
    ~Wizard() override = default;

};



#endif //EX4_WIZARD_H
