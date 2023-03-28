//
// Created by DELL on 04-May-22.
//

#include "Mtmchkin.h"
#define FIRST_INDEX 0
#define MAX_LEVEL 10

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) :
        m_player(playerName), m_cards(new Card[numOfCards]), m_gameStatus(GameStatus::MidGame),
        m_numOfCards(numOfCards), m_index(FIRST_INDEX)
{
    for(int i = 0; i < numOfCards; i++) {
        m_cards[i] = cardsArray[i];
    }
}

Mtmchkin::Mtmchkin(const Mtmchkin& copyMtmchkin):
        m_player(copyMtmchkin.m_player),m_cards(new Card[copyMtmchkin.m_numOfCards]), m_gameStatus(copyMtmchkin.getGameStatus()),
        m_numOfCards(copyMtmchkin.m_numOfCards), m_index(copyMtmchkin.m_index)
{
    for (int i = 0; i <m_numOfCards; ++i) {
        m_cards[i]=copyMtmchkin.m_cards[i];
    }
}

GameStatus Mtmchkin::getGameStatus ()const {
    if (m_player.getLevel() == MAX_LEVEL) {
        return GameStatus::Win;
    } else if (m_player.isKnockedOut()) {
        return GameStatus::Loss;
    }
    else
        return GameStatus::MidGame;
}

void Mtmchkin::playNextCard() {
    if(m_index >= 0 && m_index < m_numOfCards) {
        m_cards[m_index].printInfo();
        m_cards[m_index].applyEncounter(m_player);
        m_player.printInfo();
        if((m_index + 1) == m_numOfCards) {
            m_index = 0;
        }
        else {
            m_index++;
        }
    }
}

bool Mtmchkin::isOver() const
{
    if (getGameStatus() == GameStatus::Win || getGameStatus() == GameStatus::Loss) {
        return true;
    }
    else {
        return false;
    }
}

Mtmchkin::~Mtmchkin() {
    delete[] m_cards;
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin &mtmchkin) {
    if (this == &mtmchkin) {
        return *this;
    }
    delete[] m_cards;
    m_cards = new Card[mtmchkin.m_numOfCards];
    m_gameStatus = mtmchkin.getGameStatus();
    m_numOfCards = mtmchkin.m_numOfCards;
    m_index = mtmchkin.m_index;
    for (int i = 0; i < m_numOfCards; ++i) {
        m_cards[i]=mtmchkin.m_cards[i];
    }
    return *this;
}
