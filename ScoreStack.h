#ifndef SCORE_H
#define SCORE_H
#include "Player.h"

class ScoreStack :public Player
{

private:
    struct Node
    {
        int score;
        Node* link;
        
    };

public:
    //friend class GroupInfo;

    Node* top;

    ScoreStack()
    {
        top = nullptr;
    }

    void pushScore(int);
    int isEmpty();
    void popScore();
    void displayScore();
    int getScore();
    //void add();


};

#endif // SCORE_H