#include <iostream>
#include "ScoreStack.h"
#include <time.h>

using namespace std;

void startGame(Game*, ScoreStack*);
void gameInstruction();
void decideWinner(ScoreStack*, Game*);
void exitGame();
void resetPlayer(Game*, ScoreStack*);
void rock();
void scissor();
void paper();
void displayRPS(int, int);
void startSprite();

int main()
{
    system("COLOR 79");

    int choice;
    ScoreStack gi[5];
    Game gm;

    do {
        system("cls");

        startSprite();

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
                    displayRPS(playerChoice, computerChoice);
                    cout << "Computer choose Scissor" << endl;
                    cout << "Player Win ! You got 2 points !" << endl;
                    gi[k].pushScore(2);

                }
                else if (playerChoice == 2 && computerChoice == 1)
                {
                    displayRPS(playerChoice, computerChoice);
                    cout << "Computer Choose Rock" << endl;
                    cout << "Player Win ! You got 2 points !" << endl;
                    gi[k].pushScore(2);

                }
                else if (playerChoice == 3 && computerChoice == 2)
                {
                    displayRPS(playerChoice, computerChoice);
                    cout << "Computer Choose Paper" << endl;
                    cout << "Player Win ! You got 2 points !" << endl;
                    gi[k].pushScore(2);


                }
                else if (playerChoice == computerChoice)
                {
                    displayRPS(playerChoice, computerChoice);
                    cout << "Draw !" << endl;
                    cout << "No score given" << endl;
                    gi[k].pushScore(0);
                }
                else
                {
                    displayRPS(playerChoice, computerChoice);
                    cout << "Computer Wins!" << endl;
                    cout << "No Score Given" << endl;
                    gi[k].pushScore(0);
                }
            }
        }

       
            
    }
    system("PAUSE");

    system("cls");
    cout << "\t\t\t\t------------------------------------------\n";
    cout << "\t\t\t\t||\tGAME OVER\t\t\t||" << endl;
    cout << "\t\t\t\t------------------------------------------\n";
    for (int i = 0; i < gm->getGroup(); i++)
    {
        cout << "\t\t\t\t------------------------------------------\n";
        cout << "\t\t\t\t||\tGroup "<< i+1 << " Score : "<< gi[i].getScore() << "\t\t||" << endl;
        cout << "\t\t\t\t------------------------------------------\n";
    }
    decideWinner(gi,gm);
    resetPlayer(gm, gi);
    
    system("PAUSE");
}

void decideWinner(ScoreStack gi[], Game* gm)
{
    int maxi=-1,max=0, drawi=0;
    bool draw = false;
    for (int i = 0; i < gm->getGroup(); i++)
    {
        if (gi[i].getScore() > max)
        {
            maxi = i;
            max = gi[i].getScore();
        }
    }

    for (int n = 0; n < gm->getGroup(); n++)
    {
        if (max == gi[n].getScore() && !(gi[maxi].getScore()))
        {
            drawi = n;
            draw = true;
        }

    }
    if (draw == false)
    {
        cout << "\t\t\t\t------------------------------------------\n";
        cout << "\t\t\t\t||\tGroup " << maxi + 1 << " win with " << max << " points\t||" << endl;
        cout << "\t\t\t\t------------------------------------------\n";
    }
    else
    {
        cout << "\t\t\t\t------------------------------------------\n";
        cout << "\t\t\t\t||\tGroup " << maxi + 1 << " and Group " << drawi + 1 << " is draw with " << max << "\t||" << endl;
        cout << "\t\t\t\t------------------------------------------\n";
    }
    
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

void resetPlayer(Game* gm, ScoreStack gi[])
{
    shared_ptr<Player> obj = make_shared<ScoreStack>();   
}

void displayRPS(int player, int pc)
{

    //player win
    if (player == 1 && pc==3)
    {
        rock();
        cout << "\n\n\n\t\t\t\t VS \n\n\n";
        scissor();
    }
    else if (player == 2 && pc==1)
    {
        paper();
        cout << "\n\n\n\t\t\t\t VS \n\n\n";
        rock();
    }
    else if (player == 3 && pc==2)
    {
        scissor();
        cout << "\n\n\n\t\t\t\t VS \n\n\n";
        paper();
    }
    // draw
    else if (player == pc)
    {
        if (player == 1 && pc == 1)
        {
            rock();
            cout << "\n\n\n\t\t\t\t VS \n\n\n";
            rock();
        }
        else if (player = 2 && pc == 2)
        {
            paper();
            cout << "\n\n\n\t\t\t\t VS \n\n\n";
            paper();
        }
        else
        {
            scissor();
            cout << "\n\n\n\t\t\t\t VS \n\n\n";
            scissor();
        }
    }

    //computer win
    else
    {
        if (player == 3 && pc == 1)
        {
            scissor();
            cout << "\n\n\n\t\t\t\t VS \n\n\n";
            rock();
        }
        else if (player == 1 && pc == 2)
        {
            rock();
            cout << "\n\n\n\t\t\t\t VS \n\n\n";
            paper();
        }
        else if (player == 2 && pc == 3)
        {
            paper();
            cout << "\n\n\n\t\t\t\t VS \n\n\n";
            scissor();
        }
        
        
    }
}

void rock()
{
    cout << "\t\t\t\t    _______" << endl;
    cout << "\t\t\t\t---'   ____)" << endl;
    cout << "\t\t\t\t      (_____)" << endl;
    cout << "\t\t\t\t      (_____)" << endl;
    cout << "\t\t\t\t      (____)" << endl;
    cout << "\t\t\t\t---.__(___)" << endl;
}

void paper()
{
    cout << "\t\t\t\t     _______" << endl;
    cout << "\t\t\t\t---'    ____)____" << endl;
    cout << "\t\t\t\t           ______)" << endl;
    cout << "\t\t\t\t          _______)" << endl;
    cout << "\t\t\t\t         _______)" << endl;
    cout << "\t\t\t\t---.__________)" << endl;
}

void scissor()
{
    cout << "\t\t\t\t    _______" << endl;
    cout << "\t\t\t\t---'   ____)____" << endl;
    cout << "\t\t\t\t          ______)" << endl;
    cout << "\t\t\t\t       __________)" << endl;
    cout << "\t\t\t\t      (____)" << endl;
    cout << "\t\t\t\t---.__(___)" << endl;
}

void startSprite()
{
    cout << "\n";
    cout << "\t\t\t\t ================================================\n";
    cout << "\t\t\t\t|            Rock Paper Scissor Game            |\n";
    cout << "\t\t\t\t ================================================\n\n\n";
    cout << flush;
    cout << "\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t1." << endl;
    cout << "\t\t\t   _________ __                 __      ________" << endl;
    cout << "\t\t\t  /   _____//  |______ ________/  |_   /  _____/_____    _____   ____" << endl;
    cout << "\t\t\t  \\_____  \\\\   __\\__  \\\\_  __ \\   __\\ /   \\  ___\\__  \\  /     \\_/ __ \\ " << endl;
    cout << "\t\t\t  /        \\|  |  / __ \\|  | \\/|  |   \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ " << endl;
    cout << "\t\t\t\ /_______  /|__| (____  /__|   |__|    \\______  (____  /__|_|  /\\___  > " << endl;
    cout << "\t\t\t         \\/           \\/                      \\/     \\/      \\/     \\/" << endl;
    cout << "\t\t\t\t-------------------------------------------------\n";

    cout << "\t\t\t2." << endl;
    cout << "\t\t\t.___                 __                        __  .__" << endl;
    cout << "\t\t\t|   | ____   _______/  |________ __ __   _____/  |_|__| ____   ____" << endl;
    cout << "\t\t\t|   |/    \\ /  ___/\\   __\\_  __ \\  |  \\_/ ___\\   __\\  |/  _ \\ /    \\ " << endl;
    cout << "\t\t\t|   |   |  \\\\___ \\  |  |  |  | \\/  |  /\\  \\___|  | |  (  <_> )   |  \\ " << endl;
    cout << "\t\t\t|___|___|  /____  > |__|  |__|  |____/  \\___  >__| |__|\\____/|___|  /" << endl;
    cout << "\t\t\t         \\/     \\/                          \\/                    \\/" << endl;

    cout << "\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t3. " << endl;
    cout << "\t\t\t\t\t  ___________      .__  __ " << endl;
    cout << "\t\t\t\t\t  \\_   _____/__  __|__|/  | " << endl;
    cout << "\t\t\t\t\t   |    __)_\\  \\/  /  \\   __\\ " << endl;
    cout << "\t\t\t\t\t   |        \\>    <|  ||  | " << endl;
    cout << "\t\t\t\t\t  /_______  /__/\\_ \\__||__| " << endl;
    cout << "\t\t\t\t\t\t          \\/      \\/         " << endl;
    cout << "\t\t\t\t-------------------------------------------------\n";
}