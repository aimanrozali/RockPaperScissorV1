#ifndef GAME
#define GAME

// Parent Class
class Game
{
private:
	int round;
	int group;

public:
	// Setter
	void setRound(int);
	void setGroup(int);
	// Getter
	int getRound();
	int getGroup();

	//Constructor
	Game();
	// Destructor
	~Game()
	{

	}

};

#endif