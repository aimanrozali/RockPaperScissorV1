#ifndef SCORE_H
#define SCORE_H
#include "GroupInfo.h"

class ScoreStack:public GroupInfo
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
    int displayScore();
    //void add();


};

#endif // SCORE_H