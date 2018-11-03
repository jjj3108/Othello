#pragma once
#include "Board.h"



class Gameplay{
private:
	Board b;
public:
	Gameplay();
	~Gameplay();
	void startgame();
	void getlocation();
	void endgame();
};