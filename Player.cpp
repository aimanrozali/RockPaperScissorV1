#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

void Player::push(string x)
{
	//Assign np to new node
	np = new NodeQ;

	//Pass name to new node
	np->name = x;

	//Link its next to null
	np->next = NULL;

	//Check if there is no data yet
	if (front == NULL)
	{
		// If there is no data yet
		// put new node to front
		//assign rear and front to new node
		front = rear = np;
		rear->next = NULL;
	}
	else //If there is already have element in queue
	{
		// Put new node to last list of queue
		rear->next = np;
		rear = np;
		rear->next = NULL;
	}
} 

void Player::insertPlayer(string nm)
{
	NodeLL* newNode; // Point to new node
	NodeLL* nodePtr; // Move through the list

	// Allocate new node
	newNode = new NodeLL;
	newNode->playerName = nm;
	newNode->next = nullptr;

	// If no node in the list, make newNode the firstnode
	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;

		// traverse linked list to the end
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

// This function is to copy data from linked list
// to queue after completed each round
void Player::allocatePlayer()
{
	NodeLL* nodePtr = NULL;
	if (!head)
		cout << "No List";
	else
	{
		nodePtr = head;

		while (nodePtr)
		{
			push(nodePtr->playerName);
			nodePtr = nodePtr->next;
			

		}
			
	}
}

// Dequeue for player turn
string Player::remove()
{
	string nm = "";
	if (front == NULL)
	{
		allocatePlayer();		
	}

	p = front;
	nm = p->name;
	front = front->next;
	delete p;
		
	return nm;
}

//Function to check if queue is empty
bool Player::isEmpty()
{
	if (front == NULL)
		return true;
	else
		return false;
}

// destructor
Player::~Player()
{
	NodeLL* nodePtr; // To traverse the list
	NodeLL* nextNode; //To point to the next node

	//Position nodePtr at the head of the list.
	nodePtr = head;

	//While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		//Save a pointer to the next node.
		nextNode = nodePtr->next;

		//Delete the current node.
		delete nodePtr;

		//Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}
