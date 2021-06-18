#include <iostream>
#include "ScoreStack.h"
#include <time.h>

using namespace std;

void startGame(Game*, ScoreStack*);
void gameInstruction();
void exitGame();

int main()
{
    system("COLOR 79");

    int choice;
    ScoreStack gi[5];
    Game gm;

    do {
        system("cls");

        cout << "\n";
        cout << "\t\t ================================================\n";
        cout << "\t\t|            Rock Paper Scissor Game            |\n";
        cout << "\t\t ================================================\n\n\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t|\t          1. Start Game                 |\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t|\t          2. Instruction                |\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t|\t          3. Exit                       |\n";
        cout << "\t\t-------------------------------------------------\n";

        cout << "\t\tEnter Choice : ";
        while (!(cin >> choice) || choice < 1 || choice > 3)
        {
            cout << "\t\tInvalid input. Please enter from 1 - 3 : ";
            cin.clear();
            cin.ignore();
        }

        switch (choice)
        {
        case 1:
            system("cls");
            startGame(&gm,gi);
            break;
        case 2:
            gameInstruction();
            break;
        case 3:
            exitGame();
            break;
        }

    } while (choice != 3);


    return 0;
}

void startGame(Game* gm, ScoreStack gi[])
{
    string name1, name2, gName;
    

    cout << "\nHow many Group? (MAX 5) : ";
    int numGroup = 0;

    while (!(cin >> numGroup) || numGroup < 1 || numGroup > 5)
    {
        cout << "Invalid input. Maximum only 5 groups : ";
        cin.clear();
        cin.ignore();
    }
    gm->setGroup(numGroup);


    for (int i = 0; i < gm->getGroup(); i++)
    {
        cout << "\nEnter Information for Group " << i + 1 << "(2 Players each group)" << endl;

        //int maxPlayer = 0;



        cout << "Insert Player Name Player 1 : ";
        cin >> name1;
        cout << "Insert Player Name Player 2 : ";
        cin >> name2;

        gi[i].insertPlayer(name1);
        gi[i].insertPlayer(name2);



    }

    int numRound = 0;
    cout << "\nHow many rounds you want to play ? : ";

    while (!(cin >> numRound) || numRound < 0)
    {
        cout << "Invalid input. Please enter positive number : ";
        cin.clear();
        cin.ignore();
    }

    gm->setRound(numRound);

    int playerChoice = 0, computerChoice = 0;
    //Player

            // In round?
    for (int j = 1; j <= gm->getRound(); j++)
    {
        

        for (int i = 0; i < 2; i++)
        {   
            system("PAUSE");
            system("cls");
            //Turn Player
            cout << "\n-----------------------------------" << endl;
            cout << "Player " << i + 1 << " from each Group Turn     | \n";
            cout << "-----------------------------------" << endl;
            // From Group?
            for (int k = 0; k < gm->getGroup(); k++)
            {
                cout << "\nROUND " << j << "/" << gm->getRound();
                cout << "\n" << gi[k].remove() << "'s Turn " << endl;
                cout << "-----------------------------------" << endl;
                cout << "1. Rock" << endl;
                cout << "2. Paper" << endl;
                cout << "3. Scissor" << endl;
                cout << "Select your choice : ";

                while (!(cin >> playerChoice) || playerChoice < 1 || playerChoice > 3)
                {
                    cout << " Invalid input. Please enter from 1 -3 : ";
                    cin.clear();
                    cin.ignore();
                }

                srand(time(0));
                computerChoice = (rand() % 3) + 1;

                if (playerChoice == 1 && computerChoice == 3)
                {
                    cout << "Computer choose Scissor" << endl;
                    cout << "Player Win ! You got 2 points !" << endl;
                    gi[k].pushScore(2);

                }
                else if (playerChoice == 2 && computerChoice == 1)
                {
                    cout << "Computer Choose Rock" << endl;
                    cout << "Player Win ! You got 2 points !" << endl;
                    gi[k].pushScore(2);

                }
                else if (playerChoice == 3 && computerChoice == 2)
                {
                    cout << "Computer Choose Paper" << endl;
                    cout << "Player Win ! You got 2 points !" << endl;
                    gi[k].pushScore(2);


                }
                else if (playerChoice == computerChoice)
                {
                    cout << "Draw !" << endl;
                    cout << "No score given" << endl;
                    gi[k].pushScore(0);
                }
                else
                {
                    cout << "Computer Wins!" << endl;
                    cout << "Bodo" << endl;
                    gi[k].pushScore(0);
                }
            }
        }

       
            
    }

    system("cls");
    cout << "\n-----------------------------------" << endl;
    cout << "\t\tGAME OVER" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < gm->getGroup(); i++)
    {
        cout << "Group "<< i+1 << " Score : "<< gi[i].getScore() << endl;
    }
    
    system("PAUSE");
}

void gameInstruction()
{
    system("cls");

    cout << "\n";
    cout << "\t\t ================================================\n";
    cout << "\t\t|                  Instruction                  |\n";
    cout << "\t\t ================================================\n\n\n";
    cout << "\t\t 1. This game can be play in groups (MAX 5)\n";
    cout << "\t\t 2. Each group will have 2 players only \n";
    cout << "\t\t 3. Whoever wins will be rewarded 2 points\n";
    cout << "\t\t 4. Group with highest score wins the game\n";
    cout << "\n\t\t #Rock wins against scissors.\n";
    cout << "\t\t #Scissors win against paper.\n";
    cout << "\t\t #Paper wins against rock.\n";

    system("PAUSE");
}

void exitGame()
{
    cout << "\n\t\tThank you !" << endl;
    system("PAUSE");
    exit(1);
}