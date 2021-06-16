#ifndef GAME
#define GAME


class Game
{
private:
	int round;
	int group;
	int totalScore;

public:
	// Setter
	void setRound(int);
	void setGroup(int);
	void setTotalScore(int);
	// Getter
	int getRound();
	int getGroup();
	int getTotalScore();

	//Constructor
	Game();
	
	// Member function
	void numGroup();
	//void gameSession();
	//void setScoretoStack(int);
	/*void pushScore(int s)
	{
		ScoreStack::pushScore(s);
	}*/
};

#endif