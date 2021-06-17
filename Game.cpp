#include "Game.h"
#include"ScoreStack.h"
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


//void Game::startGame()
//{
//    string name, gName;
//    ScoreStack gi[5];
//
//    cout << "\nHow many Group? (MAX 5) : ";
//    int numGroup = 0;
//    cin >> numGroup;
//    setGroup(numGroup);
//
//    for (int i = 0; i < numGroup; i++)
//    {
//        cout << "\nEnter Information for Group " << i + 1 << "(2 Players each group)" << endl;
//
//        int maxPlayer = 0;
//
//        do
//        {
//            cout << "Insert Player Name : ";
//            cin >> name;
//
//
//            gi[i].insertPlayer(name);
//
//            maxPlayer++;
//        } while (maxPlayer != 2);
//    }
//
//
//
//    int numRound = 0;
//    cout << "\nHow many rounds you want to play ? : ";
//    cin >> numRound;
//
//    int playerChoice = 0, computerChoice = 0;
//
//    for (int i = 0; i < numGroup; ++i)
//    {
//
//        system("cls");
//
//        cout << "\nGROUP " << i + 1 << endl;
//
//
//        for (int j = 1; j <= numRound; ++j)
//        {
//            cout << "\nRound No: " << j << "/" << numRound << endl;
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
//                cout << "Computer choose Scissor" << endl;
//                cout << "Player Win ! You got 2 points !" << endl;
//                gi[i].pushScore(2);
//
//            }
//            else if (playerChoice == 2 && computerChoice == 1)
//            {
//                cout << "Computer Choose Rock" << endl;
//                cout << "Player Win ! You got 2 points !" << endl;
//                gi[i].pushScore(2);
//
//            }
//            else if (playerChoice == 3 && computerChoice == 2)
//            {
//                cout << "Computer Choose Paper" << endl;
//                cout << "Player Win ! You got 2 points !" << endl;
//                gi[i].pushScore(2);
//
//
//            }
//            else if (playerChoice == computerChoice)
//            {
//                cout << "Draw !" << endl;
//                cout << "No score given" << endl;
//
//            }
//            else
//            {
//
//                cout << "Computer Win" << endl;
//                gi[i].popScore();
//
//            }
//
//        }
//
//        cout << "Group " << i + 1 << " Total Score : " << gi[i].getScore() << endl;
//
//        system("PAUSE");
//    }
//
//}

//void Game::exitGame()
//{
//    cout << "\n\t\tThank you !" << endl;
//    system("PAUSE");
//    exit(1);
//}