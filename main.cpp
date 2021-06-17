#include <iostream>
#include "ScoreStack.h"
#include <time.h>

using namespace std;

void startGame(Game*);
void exitGame();

int main()
{
    system("COLOR 79");

    int choice;

    Game gm;

    do {
        system("cls");

        cout << "\n";
        cout << "\t\t ================================================\n";
        cout << "\t\t|            Rock Paper Scissor Game            |\n";
        cout << "\t\t ================================================\n\n\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t|\t             1. Start Game              |\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t|\t             2. Exit                    |\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\tEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            startGame(&gm);
            break;
        case 2:
            exitGame();
            break;
        }

    } while (choice != 2);


    return 0;
}

void startGame(Game* gm)
{
    string name1,name2, gName;
    ScoreStack gi[5];

    cout << "\nHow many Group? (MAX 5) : ";
    int numGroup = 0;
    cin >> numGroup;
    gm->setGroup(numGroup);


    for (int i = 0; i < numGroup; i++)
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
    cin >> numRound;
    gm->setRound(numRound);

    int playerChoice = 0, computerChoice = 0;
    //Player
    
        

        
            // In round?
            for (int j = 0; j < gm->getRound(); j++)
            {
                for (int i = 0; i < 2; i++)
                {
                    //Turn Player
                    cout << "Player " << i + 1 << " from each Group Turn\n";
                // From Group?
                for (int k = 0; k < gm->getGroup(); k++)
                {
                    cout << "Player " << gi[k].remove() << endl;
                    cout << "Round " << j + 1;

                    cout << "1. Rock" << endl;
                    cout << "2. Paper" << endl;
                    cout << "3. Scissor" << endl;
                    cout << "Select your choice : ";
                    cin >> playerChoice;

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
                    }
                }
            }
        
    }
}

void exitGame()
{
    cout << "\n\t\tThank you !" << endl;
    system("PAUSE");
    exit(1);
}