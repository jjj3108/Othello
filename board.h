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
	queue<int> settedblock;//�� ���� ������ �� ��ġ
	queue<int> settableblock;//���� �� �ִ� ���� ��ġ
public:
	Board();
	~Board();
	int count_block(int block);//���� ���ο� �ִ� �Է¹��� ������ ����
	int getturn();//�� ���
	void changeturn();//�� �ٲٱ�
	void startgameboard();//���� ���� �����
	int another_turn(int turn);//1�϶� 2���� 2�϶� 1 ����
	void find_block(int turn);//���� ���� ��� ��� ã��
	void set_block(int turn);//�ش� ���� ���� �� �ִ� ��� ã��
	int find_settableblock(int turn, int location, int direction);//�ش� �������� �������� ���� �� �ִ� ��ġ���� �˾ƺ���
	bool inboard(int location);//�ش� ��ġ�� ���� ���ο� �ִ���
	int setlandstone(int turn, int location, int direction);//landstone ���� �Լ�
	int getdirection(int direction);//���⿡ ���� define�� ���ϱ⸸ �ϸ� �Ǵ� ��������
	void printBoard();//����Ʈ �Լ�
	bool landstone(int turn, int location);//�ش���ġ�� ���� ���´�. ���� �� ���� �ڸ��� false return
};