#include "board.h"

Board::Board() {
	turn = 1;
	fill(&board[0][0], &board[MAX_SIZE - 1][MAX_SIZE], 0);
}
Board::~Board() {

}
int Board::getturn() {//�� ���
	return this->turn;
}
void Board::changeturn() {//�� �ٲٱ�
	this->turn = another_turn(this->turn);
}
void Board::startgameboard() {//���� ���� �����
	this->board[MAX_SIZE / 2][MAX_SIZE / 2] = 1;
	this->board[MAX_SIZE / 2 - 1][MAX_SIZE / 2 - 1] = 1;
	this->board[MAX_SIZE / 2 - 1][MAX_SIZE / 2] = 2;
	this->board[MAX_SIZE / 2][MAX_SIZE / 2 - 1] = 2;
	return;
}
int Board::another_turn(int turn) {//1�϶� 2���� 2�϶� 1 ����
	return (turn % 2 == 0) ? 1 : 2;
}
int Board::count_block(int block) {//���� ���ο� �ִ� �Է¹��� ������ ����
	int count = 0;
	for (int i = 0; i < MAX_SIZE; i++){
		for (int j = 0; j < MAX_SIZE; j++) {
			if (this->board[i][j] == block) count++;
		}
	}
	return count;
}
void Board::printBoard()//����Ʈ �Լ�
{
	cout << "   0 1 2 3 4 5 6 7" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << " " << i;
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (this->board[i][j] == 1) cout << "��";
			else if (this->board[i][j] == 2) cout << "��";
			else if (this->board[i][j] == -1) cout << "��";
			else cout << "  ";
		}
		cout << endl;
	}
}
void Board::find_block(int turn) {//���� ���� ��� ��� ã��
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (this->board[i][j] == turn) this->settedblock.push(i * 10 + j);
		}
	}
	return;
}
bool Board::landstone(int turn, int location) {//�ش���ġ�� ���� ���´�. ���� �� ���� �ڸ��� false return
	int real_direction, next_loc;
	if (board[location / 10][location % 10] != -1) return false;
	for (int direction = 1; direction < 9; direction++) {
		real_direction = getdirection(direction);
		next_loc = location + real_direction;
		if (inboard(next_loc)) {//���� ��ġ�� ���� �ȿ� �ְ�
			if (board[next_loc / 10][next_loc % 10] == another_turn(turn)) {//���� ��ġ�� ��� ���̸�
				if (setlandstone(turn, next_loc, real_direction) != -1) {//�� ���� ���� �� ���� ������
					while (board[next_loc / 10][next_loc % 10] == another_turn(turn)) {//�� ���� ���� �� ���� �� �����´�.
						board[next_loc / 10][next_loc % 10] = turn;
						next_loc += real_direction;
					}
				}
			}
		}
	}
	while(!settableblock.empty()){
		board[settableblock.front() / 10][settableblock.front() % 10] = 0;
		settableblock.pop();
	}
	board[location / 10][location % 10] = turn;
	return true;
}
int Board::setlandstone(int turn, int location, int real_direction) {
	int next_loc = location + real_direction;
	if (inboard(next_loc)) {
		if (board[next_loc / 10][next_loc % 10] == turn) return 1;
		else if (board[next_loc / 10][next_loc % 10] == another_turn(turn)) return setlandstone(turn, next_loc, real_direction);
		else return -1;
	}
	else return -1;
}
void Board::set_block(int turn) {//�ش� ���� ���� �� �ִ� ��� ã��
	int set_location, real_direction, direction;
	find_block(turn);
	while (!settedblock.empty()) {
		for (direction = 1; direction < 9; direction++) {
			real_direction = getdirection(direction);
			if (inboard(settedblock.front() + real_direction)) {
				if (board[(settedblock.front() + real_direction) / 10][(settedblock.front() + real_direction) % 10] == another_turn(turn)) {
					set_location = find_settableblock(turn, settedblock.front(), real_direction);
					if (set_location != -1) {
						settableblock.push(set_location);
						board[set_location / 10][set_location % 10] = -1;
					}
				}
			}
		}
		settedblock.pop();
	}
}
int Board::find_settableblock(int turn, int location, int direction) {//�ش� �������� �������� ���� �� �ִ� ��ġ���� �˾ƺ���
	int next_loc = location + direction;
	if (inboard(next_loc)) {
		if (board[next_loc / 10][next_loc % 10] <= 0) return next_loc;
		else if (board[next_loc / 10][next_loc % 10] == turn) return -1;
		else return find_settableblock(turn, location + direction, direction);
	}
	else return -1;

}
bool Board::inboard(int location) {//�ش� ��ġ�� ���� ���ο� �ִ���
	int x = location / 10, y = location % 10;
	if ((x >= 0) && (x < MAX_SIZE) && (y >= 0) && (y < MAX_SIZE)) return true;
	else return false;
}
int Board::getdirection(int direction)//���⿡ ���� define�� ���ϱ⸸ �ϸ� �Ǵ� ��������
{
	switch (direction)
	{
	case LEFTUP:
		return -11;
	case UP:
		return -10;
	case RIGHTUP:
		return -9;
	case LEFT:
		return -1;
	case RIGHT:
		return 1;
	case LEFTDOWN:
		return 9;
	case DOWN:
		return 10;
	case RIGHTDOWN:
		return 11;
	default:
		return 0;
	}
}