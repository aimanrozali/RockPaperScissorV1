#include "Game.h"
#include <string>
using namespace std;

// Class Player inherit from Game class
class Player :public Game
{
private:
	// Queue Node
	struct NodeQ
	{
		string name;
		struct NodeQ* next;
	};
	//Linked List Node
	struct NodeLL
	{
		string playerName;
		struct NodeLL* next;
	};
	// Create required pointer to access Linked List and Queue
	NodeLL* head = NULL;
	NodeQ* front = NULL;
	NodeQ* rear = NULL;
	NodeQ* p = NULL;
	NodeQ* np = NULL;

public:
	// Member function
	void push(string);
	string remove();
	bool isEmpty();
	void insertPlayer(string);
	void allocatePlayer();

	// Destructor
	~Player();
	
};

