#include "Wizard.h"
#define DOUBLE_HP 2


Wizard::Wizard(const std::string& name) :
        Player(name, "Wizard")
{}

void Wizard::heal(int addHP) {
    if (addHP > 0) {
        if (m_HP + (DOUBLE_HP * addHP) <= m_maxHP) {
            m_HP =m_HP + (DOUBLE_HP * addHP);
        }
        else {
            m_HP = m_maxHP;
        }
    }
}




