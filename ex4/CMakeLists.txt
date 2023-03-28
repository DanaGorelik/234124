cmake_minimum_required(VERSION 3.20)
project(ex4)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex4
      # tool/main.cpp
        Mtmchkin.h
        Mtmchkin.cpp
        Players/Player.cpp Players/Player.h Players/Wizard.h Players/Wizard.cpp Players/Rogue.cpp Players/Rogue.h Players/Fighter.cpp Players/Fighter.h "submission (1)/utilities.cpp" "submission (1)/utilities.h"
        Cards/Goblin.cpp Cards/Goblin.h Cards/Vampire.h Cards/Vampire.cpp Cards/BattleCards.h Cards/BattleCards.cpp Cards/Pitfall.h Cards/Pitfall.cpp Cards/SurpriseCards.cpp Cards/SurpriseCards.h Cards/Card.h Cards/Card.cpp
        Cards/Fairy.cpp Cards/Fairy.h Cards/Merchant.h Cards/Merchant.cpp Cards/Treasure.h Cards/Treasure.cpp Cards/Dragon.h Cards/Dragon.cpp Cards/Barfight.h Cards/Barfight.cpp
        Exception.h
      #  fileTests/inFiles fileTests/outFiles fileTests/tester.sh fileTests/testsMain.cpp
      test.cpp)
