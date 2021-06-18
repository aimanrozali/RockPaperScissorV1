#include "Game.h"
#include <iostream>
using namespace std;

//Setter
void Game::setRound(int sr)
{
    round = sr;
}

void Game::setGroup(int sg)
{
    group = sg;
}

// Getter
int Game::getRound()
{
    return round;
}

int Game::getGroup()
{
    return group;
}

//Constructor
Game::Game()
{
    group = 0;
    round = 0;
}
 