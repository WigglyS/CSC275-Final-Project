#include "Functions.h"


Peice::Peice() {};
Peice::Peice(int x, int y) { Position.push_back(x); Position.push_back(y); };
vector<int> Peice::GetPosition() { return Position; };
void Peice::SetPosition(int x, int y) { Position[0] = x; Position[1] = y; };




//returns true if spot is valid to move to
bool Peice::move() { return true; };
bool Pawn::move() { return true; };
Pawn::Pawn(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Rook::move() { return true; };
bool Knight::move() { return true; };
bool Bishop::move() { return true; };
bool Queen::move() { return true; };
bool King::move() { return true; };

void Board::addpeice(Peice p) { Peices.push_back(&p); };
void Board::removePeice(Peice p) {};
void Board::Display() { 
	for (int x = 0; x < rows->size(); x++) {
		for (int y = 0; y < 9; y++) {
			cout << rows[x][y] << " " ;
		}
		cout << endl;
	}
};
void Board::Reset() {
	Peices.clear();
	for (int i = 0; i < 9; i++){
		Peices.push_back(new Pawn(1,i));
		Peices[i]->SetPosition(1, i);
		rows[1][i] = 'p';
	}
};




void GameManager::Instructions(){
	cout << " " << endl;
	system("pause");
};
int GameManager::Getturn() { return turn; };
void GameManager::SetTurn(int t) { turn = t; };
void GameManager::select() {};
