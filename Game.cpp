#include "Game.h"
#include <iostream>
#include <time.h>
using namespace std;

void Game::setRound(int sr)
{
    round = sr;
}

void Game::setGroup(int sg)
{
    group = sg;
}

int Game::getRound()
{
    return round;
}

int Game::getGroup()
{
    return group;
}

Game::Game()
{
    group = 0;
    round = 0;
}
