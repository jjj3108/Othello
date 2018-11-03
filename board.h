#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define MAX_SIZE 8
#define LEFTUP 1
#define UP 2
#define RIGHTUP 3
#define LEFT 4
#define RIGHT 5
#define LEFTDOWN 6
#define DOWN 7
#define RIGHTDOWN 8


class Board {
private:
	int board[MAX_SIZE][MAX_SIZE];
	int turn;
	queue<int> settedblock;//각 턴의 놓여진 돌 위치
	queue<int> settableblock;//놓을 수 있는 돌의 위치
public:
	Board();
	~Board();
	int count_block(int block);
	int getturn();
	void changeturn();
	void startgameboard();
	int another_turn(int turn);
	void find_block(int turn);
	void set_block(int turn);
	int find_settableblock(int turn, int location, int direction);
	bool inboard(int location);
	int getdirection(int direction);
	void printBoard();
	bool landstone(int turn, int location);
	int setlandstone(int turn, int location, int direction);
};