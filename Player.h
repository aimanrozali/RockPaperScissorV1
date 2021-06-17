#include <string>
#include "Game.h"
using namespace std;

class Player :public Game
{
private:
	struct NodeQ
	{
		string name;
		struct NodeQ* next;
	};
	struct NodeLL
	{
		string playerName;
		struct NodeLL* next;
	};
	NodeLL* head = NULL;
	NodeQ* front = NULL;
	NodeQ* rear = NULL;
	NodeQ* p = NULL;
	NodeQ* np = NULL;

public:
	void push(string);
	string remove();
	string disp();
	bool isEmpty();
	void insertPlayer(string);
	void allocatePlayer();

};
