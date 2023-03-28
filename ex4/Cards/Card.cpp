#include "Card.h"

Card::Card(std::string name) :
        m_name(name)
{}


std::string Card::getName() const {
    return m_name;
}

std::ostream& operator<<(std::ostream &os, const Card& card) {
    card.printInheritance(os);
    return os;
}



