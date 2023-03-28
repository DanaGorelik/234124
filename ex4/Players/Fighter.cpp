#include "Fighter.h"
#define DOUBLE 2


Fighter::Fighter(const std::string name) :
        Player(name, "Fighter")
{}

int Fighter::getAttackStrength() const {
    return (m_level + (DOUBLE * m_force));
}

