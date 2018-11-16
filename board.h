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
	int count_block(int block);//보드 내부에 있는 입력받은 인자의 갯수
	int getturn();//턴 얻기
	void changeturn();//턴 바꾸기
	void startgameboard();//게임 보드 만들기
	int another_turn(int turn);//1일때 2리턴 2일때 1 리턴
	void find_block(int turn);//현재 턴의 모든 블록 찾기
	void set_block(int turn);//해당 턴의 놓을 수 있는 블록 찾기
	int find_settableblock(int turn, int location, int direction);//해당 방향으로 나가가며 놓을 수 있는 위치인지 알아보기
	bool inboard(int location);//해당 위치가 보드 내부에 있는지
	int setlandstone(int turn, int location, int direction);//landstone 내부 함수
	int getdirection(int direction);//방향에 따른 define을 더하기만 하면 되는 방향으로
	void printBoard();//프린트 함수
	bool landstone(int turn, int location);//해당위치에 돌을 놓는다. 놓을 수 없는 자리면 false return
};