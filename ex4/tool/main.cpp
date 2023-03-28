#include <iostream>
#include "../Players/Player.h"
#include "../Players/Wizard.h"

#include "../Mtmchkin.h"
#include <vector>
#include "../Cards/Card.h"


int main() {
    Mtmchkin game("test0.deck");
game.playRound();



//    try {
//        Mtmchkin game("deck.txt");
//        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
//            game.playRound();
//        }
//        game.printLeaderBoard();
//    }
//    catch (...) {
//
//    }

    return 0;
}
//deque<int> dana;
//dana.push_front(1);
//dana.push_front(2);
//std::cout << dana.front() << std::endl;
//dana.pop_front();
//std::cout << dana.front() << std::endl;
//    Wizard w1("Dana");
//    Fighter f1("Ron");
//    Rogue r1("Alla");
//    w1.damage(30);
//    w1.heal(3);
//    r1.addCoins(50);
//    f1.levelUp();
//    std:: cout << f1.getAttackStrength() << std::endl;
//    std::cout << w1 << std::endl;
//    std::cout << f1 << std::endl;
//    std::cout << r1;



