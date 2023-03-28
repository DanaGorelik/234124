#include "Dragon.h"
#define FORCE_NUM 25
#define LOOT_COINS_NUM 1000
#define RESET_HP -1

Dragon::Dragon() :
        BattleCards( "Dragon", FORCE_NUM, LOOT_COINS_NUM, RESET_HP) {}