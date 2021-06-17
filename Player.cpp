#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

void Player::push(string x)
{
	np = new NodeQ;
	np->name = x;
	np->next = NULL;

	if (front == NULL)
	{
		front = rear = np;
		rear->next = NULL;
	}
	else
	{
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

		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

void Player::allocatePlayer()
{
	NodeLL* nodePtr = NULL;
	if (!head)
		cout << "No List";
	else
	{
		nodePtr = head;

		while (nodePtr->next && nodePtr->next != NULL)
		{
			push(nodePtr->playerName);
			nodePtr = nodePtr->next;

		}
			
	}
}

string Player::remove()
{
	string nm = "No Player";
	if (front == NULL)
	{
		cout << "No Player!\n";
		allocatePlayer();
		goto nx;
	}
	else
	{
		nx:
		p = front;
		nm = p->name;
		front = front->next;
		delete p;
		
	}
	return nm;
}

string Player::disp()
{
	static NodeQ* temp = front;
	string nm = "";
	if (front == NULL)
	{
		return "No Player";
	}
	else
	{
		p = temp;
		nm = p->name;
		temp = front->next;
		return nm;

	}
	
}

bool Player::isEmpty()
{
	if (front == NULL)
		return true;
	else
		return false;
}