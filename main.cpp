#include <iostream>
#include "GroupInfo.h"
#include "ScoreStack.h"
#include<time.h>

using namespace std;



int main()
{

    string name, gName;
    double marks;
    char prompt;
    cout << "Welcome" << endl;

    ScoreStack gi[5]; // Allocate Group

    cout << "How many Group? (MAX 5) : ";
    int numGroup = 0;
    cin >> numGroup;
    Game obj;
    obj.setGroup(numGroup);
    
    

    for (int i = 0; i < obj.getGroup(); i++)
    {
        cout << "\nEnter Information for Group " << i + 1 << "(2 Players each group)" << endl;

        int counter = 0;

        do
        {
            cout << "Insert Player Name : ";
            cin >> name;


            gi[i].insertPlayer(name, i + 1);

            counter++;
        } while (counter != 2);


    }

    int numRound = 0;
    cout << "\nHow many rounds you want to play ? : ";
    cin >> numRound;

    int playerChoice = 0, computerChoice = 0;



    for (int i = 0; i < obj.getGroup(); ++i)
    {
        system("cls");

        cout << "\nGROUP " << i+1 << endl;
        int totalScore = 0;

        for (int j = 1; j <= numRound; ++j)
        {
            cout << "\nRound No: " << j << "/" << numRound << endl;
            cout << "1. Rock" << endl;
            cout << "2. Paper" << endl;
            cout << "3. Scissor" << endl;
            cout << "Select your choice : ";
            cin >> playerChoice;

            srand(time(0));
            computerChoice = (rand() % 3) + 1;

            // If player win
            if (playerChoice == 1 && computerChoice == 3)
            {
                cout << "Player Win ! You got 1 points !" << endl;
                gi[i].pushScore(1);
            }
            else if (playerChoice == 2 && computerChoice == 1)
            {
                cout << "Player Win ! You got 1 points !" << endl;
                gi[i].pushScore(1);
            }
            else if (playerChoice == 3 && computerChoice == 2)
            {
                cout << "Player Win ! You got 1 points !" << endl;
                gi[i].pushScore(1);
            }
            else if (playerChoice == computerChoice)
            {
                cout << "Draw !" << endl;
                cout << "No score given" << endl;
            }
            else
            {
                cout << "Computer Win" << endl;
            }

            //totalScore += totalScore;

        }

        cout << "Total Score : " << gi[i].displayScore() << endl;
        system("PAUSE");
    }


    return 0;
}