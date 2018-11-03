#include "Gameplay.h"

Gameplay::Gameplay()
{
	b.startgameboard();
	b.set_block(b.getturn());
}
Gameplay::~Gameplay() {}
void Gameplay::startgame()
{
	int location;
	b.printBoard();
	while (true) {
		if (b.getturn()==1) cout << "please input row column player ¡Ü: ";
		else cout << "please input row column player ¡Û: ";
		getlocation();
		b.changeturn();
		b.set_block(b.getturn());
		if (b.count_block(-1) == 0) {
			b.changeturn();
			b.set_block(b.getturn());
			if (b.count_block(-1) == 0) break;
		}
		b.printBoard();
	}
	endgame();
}
void Gameplay::getlocation() {
	int location;
	cin >> location;
	while (!b.landstone(b.getturn(), location)) {
		cout << "you can't land there" << endl;
		cin >> location;
	}
}
void Gameplay::endgame() {
	int score1, score2;
	score1 = b.count_block(1);
	score2 = b.count_block(2);
	if(score1>score2) cout << "player ¡Ü win!!" << endl;
	else if(score1<score2) cout << "player ¡Û win!!" << endl;
	else cout << "same score!!" << endl;
	cout << "GAME OVER" << endl;
}