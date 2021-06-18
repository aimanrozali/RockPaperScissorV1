#include "ScoreStack.h"
#include<iostream>
using namespace std;

void ScoreStack::pushScore(int s)
{

    // Create new node temp and allocate memory
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    // Initialize data into temp data field
    temp->score = s;

    // Put top pointer reference into temp link
    temp->link = top;

    // Make temp as top of Stack
    top = temp;

}

// Utility function to check if
// the stack is empty or not
bool ScoreStack::isEmpty()
{
    if (!top)
        return true;
    else
        return false;
}
 
// Utility function to pop top
// element from the stack
void ScoreStack::popScore()
{
    struct Node* temp;

    // Check for stack underflow
    if (top == NULL)
    {
        cout << "No Marks Received!" << endl;
    }
    else
    {

        // Top assign into temp
        temp = top;

        // Assign second node to top
        top = top->link;

        // Destroy connection between
        // first and second
        temp->link = NULL;

        // Release memory of top node
        delete top;

    }
}


int ScoreStack::getScore()
{
    struct Node* temp;
    int total = 0;

    // Check for stack underflow
    if (top == NULL)
    {
        return 0;
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {

            // Print node data

            total += temp->score;
            // Assign temp link to temp

            temp = temp->link;

        }
        return total;
    }

}

ScoreStack::~ScoreStack()
{
    Node* temp, * nextNode;

    //Position nodePtr at the top of the stack
    temp = top;

    //Traverse the list deleting each node
    while (temp != nullptr)
    {
        nextNode = temp->link;
        delete temp;
        temp = nextNode;
    }
}