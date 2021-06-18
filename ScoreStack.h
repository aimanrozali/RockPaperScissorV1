#ifndef SCORE_H
#define SCORE_H
#include "Player.h"

//Inherit from Player class
class ScoreStack :public Player
{

private:
    //Create node structure
    struct Node
    {
        int score;
        Node* link;
        
    };
    // Create Node at top
    Node* top;

public:
    // Constructor
    ScoreStack()
    {
        top = nullptr;
    }
    // Member Function
    void pushScore(int);
    int isEmpty();
    void popScore();
    int getScore();

    //Destructor
    ~ScoreStack();

};

#endif // SCORE_H