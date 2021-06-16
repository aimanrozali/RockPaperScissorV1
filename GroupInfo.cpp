#include "GroupInfo.h"
#include <iostream>
#include <string>
using namespace std;

//template <class T>
void GroupInfo::insertPlayer(string newPlayer, int gName)
{
	PlayerList* newNode; // Point to new node
	PlayerList* nodePtr; // Move through the list

	// Allocate new node
	newNode = new PlayerList;
	newNode->playerName = newPlayer;
	newNode->groupName = gName;
	newNode->next = nullptr;

	// If no node in the list, make newNode the firstnode
	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;

		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

//template <class T>
void GroupInfo::displayPlayer() const
{
	PlayerList* nodePtr; // To move through the list

	// Position nodeptr at the head of the list
	nodePtr = head;

	//while nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		//Display player information
		cout << nodePtr->playerName << endl;


		//Move to next node
		nodePtr = nodePtr->next;
	}
}