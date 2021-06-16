#ifndef GROUPINFO_H
#define GROUPINFO_H
#include <string>
#include "Game.h"
using namespace std;

class GroupInfo:public Game
{
private:
	struct PlayerList
	{
		string playerName; // Store player name
		int groupName; // Store group name
		int score; // Store player marks
		struct PlayerList* next;
	};

	PlayerList* head;

public:
	friend class ScoreStack;
	//Constructor
	GroupInfo()
	{
		head = nullptr;
	}

	//Destructor
	~GroupInfo() {}

	//Operation
	void insertPlayer(string, int);
	void displayPlayer() const;
};

#endif