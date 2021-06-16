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

void Game::setTotalScore(int ts)
{
	totalScore = ts;
}

int Game::getRound()
{
	return round;
}

int Game::getGroup()
{
	return group;
}

int Game::getTotalScore()
{
	return totalScore;
}


Game::Game()
{
	group = 0;
	round = 0;
	totalScore = 0;
}

void Game::numGroup()
{
	cout << "How many Group? (MAX 5) : ";
	int numGroup = 0;
	cin >> numGroup;
	setGroup(numGroup);
}

//void Game::gameSession()
//{
//	// We start Game Session Here
//    int computerChoice = 0;
//    for (int i = 1; i <= getGroup() ; ++i)
//    {
//        system("cls");
//
//        cout << "\nGROUP " << i << endl;
//        int totalScore = 0, playerChoice = 0;
//
//        for (int j = 1; j <= getGroup(); ++j)
//        {
//            cout << "\nRound No: " << j << "/" << getRound() << endl;
//            cout << "1. Rock" << endl;
//            cout << "2. Paper" << endl;
//            cout << "3. Scissor" << endl;
//            cout << "Select your choice : ";
//            cin >> playerChoice;
//
//            srand(time(0));
//            computerChoice = (rand() % 3) + 1;
//
//            // If player win
//            if (playerChoice == 1 && computerChoice == 3)
//            {
//                cout << "Player Win ! You got 1 points !" << endl;
//                pushScore(1);
//            }
//            else if (playerChoice == 2 && computerChoice == 1)
//            {
//                cout << "Player Win ! You got 1 points !" << endl;
//                pushScore(1);
//            }
//            else if (playerChoice == 3 && computerChoice == 2)
//            {
//                cout << "Player Win ! You got 1 points !" << endl;
//                pushScore(1);
//            }
//            else if (playerChoice == computerChoice)
//            {
//                cout << "Draw !" << endl;
//                cout << "No score given" << endl;
//            }
//            else
//            {
//                cout << "Computer Win" << endl;
//            }
//
//            totalScore = 
//
//        }
//
//        cout << "Total Score : " << totalScore << endl;
//        system("PAUSE");
//    }
//}

//void Game::setScoretoStack(int n)
//{
//
//}
