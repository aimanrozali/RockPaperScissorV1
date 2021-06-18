#include <iostream>
#include "ScoreStack.h"
#include <time.h>

using namespace std;

// Function protoype
void startGame(Game*, ScoreStack*);
void gameInstruction();
void decideWinner(ScoreStack*, Game*);
void exitGame();

//Function For UI
void displayRPS(int, int);
void startSprite();
void rock();
void scissor();
void paper();
void winnerSprite();

int main()
{
    // change console color
    system("COLOR 79");


    // Object declaration
    ScoreStack gi[5];
    Game gm;


    int choice;

    do {

        //clear console screen
        system("cls");

        //function call
        startSprite();



        cout << "\t\t\t\tEnter Choice : ";

        //Input validation
        while (!(cin >> choice) || choice < 1 || choice > 3)
        {
            cout << "\t\t\t\tInvalid input. Please enter from 1 - 3 : ";
            cin.clear();
            cin.ignore();
        }

        //switch case 
        switch (choice)
        {
        case 1:
            system("cls");
            startGame(&gm, gi);
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


//This function accepts player information and start the game process
void startGame(Game* gm, ScoreStack gi[])
{
    // variable declaration
    string name1, name2;

    cout << "\n\t\t\t\t----------------------------------------------" << endl;
    cout << "\n\t\t\t\t\tHow many Group? (MAX 5) : ";
    int numGroup = 0;

    // Input validation
    while (!(cin >> numGroup) || numGroup < 2 || numGroup > 5)
    {
        cout << "\t\t\t\t\tInvalid input. Minimum is 2 groups and maximum only 5 groups : ";
        cin.clear();
        cin.ignore();
    }
    //set group
    gm->setGroup(numGroup);
    cout << "\t\t\t\t----------------------------------------------" << endl;

    //loop to get player name by each group
    for (int i = 0; i < gm->getGroup(); i++)
    {
        cout << "\n\t\t\t\t----------------------------------------------" << endl;
        cout << "\n\t\t\t\tEnter Information for Group " << i + 1 << "(2 Players each group)" << endl;
        cout << "\n\t\t\t\t----------------------------------------------" << endl;

        cout << "\n\t\t\t\t\tInsert Player Name Player 1 : ";
        cin >> name1;
        cout << "\n\n\t\t\t\t\tInsert Player Name Player 2 : ";
        cin >> name2;

        cout << "\n\t\t\t\t----------------------------------------------" << endl;

        gi[i].insertPlayer(name1);  //store player name in Player linked list
        gi[i].insertPlayer(name2);  // store player name in Player linked list

    }

    // initialize round to 0
    int numRound = 0;

    //Prompt user to enter round
    cout << "\n\t\t\t\t----------------------------------------------" << endl;
    cout << "\n\t\t\t\t\tHow many rounds you want to play ? : ";

    //input validation
    while (!(cin >> numRound) || numRound < 0)
    {
        cout << "\t\t\tInvalid input. Please enter positive number : ";
        cin.clear();
        cin.ignore();
    }
    cout << "\n\t\t\t\t----------------------------------------------" << endl;

    // set round number into object
    gm->setRound(numRound);

    int playerChoice = 0, computerChoice = 0;

    // loop by each round
    for (int j = 1; j <= gm->getRound(); j++)
    {
        // loop for each player in a group 
        for (int i = 0; i < 2; i++)
        {
            system("PAUSE");
            system("cls");
            //Turn Player
            cout << "\n\t\t\t\t-----------------------------------" << endl;
            cout << "\t\t\t\t||   Player " << i + 1 << " from each Group Turn     || \n";
            cout << "\t\t\t\t-----------------------------------" << endl;

            //loop for player to take turn
            for (int k = 0; k < gm->getGroup(); k++)
            {
                cout << "\n\t\t\t\t-----------------------------------" << endl;
                cout << "\n\t\t\t\t||\tROUND " << j << "/" << gm->getRound() << "\t\t||" << endl;
                cout << "\n\t\t\t\t-----------------------------------" << endl;
                cout << "\n\t\t\t\t" << gi[k].remove() << "'s Turn \n" << endl;  //diplay player name from queue
                cout << "\t\t\t\t-----------------------------------" << endl;
                cout << "\t\t\t\t1. Rock" << endl;
                cout << "\t\t\t\t2. Paper" << endl;
                cout << "\t\t\t\t3. Scissor" << endl;
                cout << "\t\t\t\tSelect your choice : ";

                //input validation
                while (!(cin >> playerChoice) || playerChoice < 1 || playerChoice > 3)
                {
                    cout << "\t\t\t\tInvalid input. Please enter from 1 -3 : ";
                    cin.clear();
                    cin.ignore();
                }

                // Use current time as seed for random generator
                srand(time(0));
                // generate random number from 1 to 3
                computerChoice = (rand() % 3) + 1;

                // if player choose rock and computer choose scissor
                if (playerChoice == 1 && computerChoice == 3)
                {
                    displayRPS(playerChoice, computerChoice);
                    cout << "\t\t\t\tComputer choose Scissor" << endl;
                    cout << "\t\t\t\tPlayer Win ! You got 2 points !" << endl;
                    // push score into stack
                    gi[k].pushScore(2);

                }
                // if player choose paper and computer choose rock
                else if (playerChoice == 2 && computerChoice == 1)
                {
                    //function call
                    displayRPS(playerChoice, computerChoice);

                    cout << "\t\t\t\tComputer Choose Rock" << endl;
                    cout << "\t\t\t\tPlayer Win ! You got 2 points !" << endl;
                    // push score into stack
                    gi[k].pushScore(2);

                }
                // if player choose scissor and computer choose paper
                else if (playerChoice == 3 && computerChoice == 2)
                {
                    //function call
                    displayRPS(playerChoice, computerChoice);

                    cout << "\t\t\t\tComputer Choose Paper" << endl;
                    cout << "\t\t\t\tPlayer Win ! You got 2 points !" << endl;
                    // push score into stack
                    gi[k].pushScore(2);


                }
                // if player choice same with computer
                else if (playerChoice == computerChoice)
                {
                    //function call
                    displayRPS(playerChoice, computerChoice);

                    cout << "\t\t\t\tDraw !" << endl;
                    cout << "\t\t\t\tNo score given" << endl;

                }
                else
                {
                    // if player loses to computer 
                    displayRPS(playerChoice, computerChoice);
                    cout << "\t\t\t\tComputer Wins!" << endl;

                }
            }
        }
    }
    system("PAUSE");

    system("cls");

    //display when game is over
    cout << "\t\t\t\t==========================================\n";
    cout << "\t\t\t\t||\tGAME OVER\t\t\t||" << endl;
    cout << "\t\t\t\t==========================================\n";

    //for loop to show score by each score
    for (int i = 0; i < gm->getGroup(); i++)
    {
        cout << "\t\t\t\t------------------------------------------\n";
        cout << "\t\t\t\t||\tGroup " << i + 1 << " Score : " << gi[i].getScore() << "\t\t||" << endl;
        cout << "\t\t\t\t------------------------------------------\n";
    }

    //Display Sprite Winner
    winnerSprite();

    //function call to display winner
    decideWinner(gi, gm);

    exitGame();

    system("PAUSE");
}

// This function compares the highest score and displays the winner
void decideWinner(ScoreStack gi[], Game* gm)
{
    // variable hold the highest
    // variable to hold the index of highest and draw
    int maxi = -1, max = 0, drawi = 0,

    //flags to indicate if the score draw
    bool draw = false;

    //loop to compare score in arraay
    for (int i = 0; i < gm->getGroup(); i++)
    {
        if (gi[i].getScore() > max)
        {
            maxi = i;
            max = gi[i].getScore();
            
        }
        
    }

    // Loop to check if there is draw
    for (int n = 0; n < gm->getGroup(); n++)
    {
        if (max == gi[n].getScore())
        {
            if (!(maxi == n))
            {
                drawi = n;
                draw = true;
            }
        }
    }

    //if score not draw
    if (draw == false)
    {
        cout << "\t\t\t\t------------------------------------------\n";
        cout << "\t\t\t\t||\tGroup " << maxi + 1 << " win with " << max << " points\t||" << endl;
        cout << "\t\t\t\t------------------------------------------\n";
    }
    // if score draw
    else
    {
        cout << "\t\t\t\t------------------------------------------\n";
        cout << "\t\t\t\t||\tGroup " << maxi + 1 << " and Group " << drawi + 1 << " is draw with " << max << "\t||" << endl;
        cout << "\t\t\t\t------------------------------------------\n";
    }

}


// This function displays game instruction
void gameInstruction()
{
    system("cls");

    cout << "\n";
    cout << "\t\t\t\t================================================\n";
    cout << "\t\t\t\t|                  Instruction                  |\n";
    cout << "\t\t\t\t================================================\n\n\n";
    cout << "\t\t\t\t 1. This game can be play in groups (MAX 5)\n";
    cout << "\t\t\t\t 2. Each group will have 2 players only \n";
    cout << "\t\t\t\t 3. Whoever wins will be rewarded 2 points\n";
    cout << "\t\t\t\t 4. Group with highest score wins the game\n";
    cout << "\n\t\t\t\t #Rock wins against scissors.\n";
    cout << "\t\t\t\t #Scissors win against paper.\n";
    cout << "\t\t\t\t #Paper wins against rock.\n";

    system("PAUSE");
}

//This functions will exit the game
void exitGame()
{
    cout << "\n\t\t\t\tThank you !" << endl;
    system("PAUSE");
    exit(1);
}

// This function is to display the game UI
void displayRPS(int player, int pc)
{

    //player win
    if (player == 1 && pc == 3)
    {
        rock();
        cout << "\n\n\n\t\t\t\t===================== VS ===================== \n\n\n";
        scissor();
    }
    else if (player == 2 && pc == 1)
    {
        paper();
        cout << "\n\n\n\t\t\t\t===================== VS ===================== \n\n\n";
        rock();
    }
    else if (player == 3 && pc == 2)
    {
        scissor();
        cout << "\n\n\n\t\t\t\t===================== VS ===================== \n\n\n";
        paper();
    }
    // draw
    else if (player == pc)
    {
        if (player == 1 && pc == 1)
        {
            rock();
            cout << "\n\n\n\t\t\t\t===================== VS ===================== \n\n\n";
            rock();
        }
        else if (player = 2 && pc == 2)
        {
            paper();
            cout << "\n\n\n\t\t\t\t===================== VS ===================== \n\n\n";
            paper();
        }
        else
        {
            scissor();
            cout << "\n\n\n\t\t\t\t===================== VS ===================== \n\n\n";
            scissor();
        }
    }

    //computer win
    else
    {
        if (player == 3 && pc == 1)
        {
            scissor();
            cout << "\n\n\n\t\t\t\t===================== VS ===================== \n\n\n";
            rock();
        }
        else if (player == 1 && pc == 2)
        {
            rock();
            cout << "\n\n\n\t\t\t\t===================== VS ===================== \n\n\n";
            paper();
        }
        else if (player == 2 && pc == 3)
        {
            paper();
            cout << "\n\n\n\t\t\t\t===================== VS ===================== \n\n\n";
            scissor();
        }


    }
}

// This function displays Rock shape
void rock()
{
    cout << "\t\t\t\t\t\t    _______" << endl;
    cout << "\t\t\t\t\t\t---'   ____)" << endl;
    cout << "\t\t\t\t\t\t      (_____)" << endl;
    cout << "\t\t\t\t\t\t      (_____)" << endl;
    cout << "\t\t\t\t\t\t      (____)" << endl;
    cout << "\t\t\t\t\t\t---.__(___)" << endl;
}

// This function displays Paper shape
void paper()
{
    cout << "\t\t\t\t\t\t     _______" << endl;
    cout << "\t\t\t\t\t\t---'    ____)____" << endl;
    cout << "\t\t\t\t\t\t           ______)" << endl;
    cout << "\t\t\t\t\t\t          _______)" << endl;
    cout << "\t\t\t\t\t\t         _______)" << endl;
    cout << "\t\t\t\t\t\t---.__________)" << endl;
}

// This function displays Scissor shape
void scissor()
{
    cout << "\t\t\t\t\t\t    _______" << endl;
    cout << "\t\t\t\t\t\t---'   ____)____" << endl;
    cout << "\t\t\t\t\t\t          ______)" << endl;
    cout << "\t\t\t\t\t\t       __________)" << endl;
    cout << "\t\t\t\t\t\t      (____)" << endl;
    cout << "\t\t\t\t\t\t---.__(___)" << endl;
}

// This function display Menu UI
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

void winnerSprite()
{
    cout << "\t\t\t\t$$\\      $$\\       $$$$$$\\       $$\\   $$\\       $$\\   $$\\       $$$$$$$$\\       $$$$$$$\\\\" << endl;
    cout << "\t\t\t\t$$ | $\\  $$ |      \\_$$  _|      $$$\\  $$ |      $$$\\  $$ |      $$  _____|      $$  __$$\\\\" << endl;
    cout << "\t\t\t\t$$ |$$$\\ $$ |        $$ |        $$$$\\ $$ |      $$$$\\ $$ |      $$ |            $$ |  $$ |" << endl;
    cout << "\t\t\t\t$$ $$ $$\\$$ |        $$ |        $$ $$\\$$ |      $$ $$\\$$ |      $$$$$\\         $$$$$$$  |" << endl;
    cout << "\t\t\t\t$$$$  _$$$$ |        $$ |        $$ \\$$$$ |      $$ \\$$$$ |      $$  __|         $$  __$$< " << endl;
    cout << "\t\t\t\t$$$  / \\$$$ |        $$ |        $$ |\\$$$ |      $$ |\\$$$ |      $$ |            $$ |  $$ |" << endl;
    cout << "\t\t\t\t$$  /   \\$$ |      $$$$$$\\       $$ | \\$$ |      $$ | \\$$ |      $$$$$$$$\\       $$ |  $$ |" << endl;
    cout << "\t\t\t\t\\__/     \\__|      \\______|      \\__|  \\__|      \\__|  \\__|      \\________|      \\__|  \\__|" << endl;
}