#include "Functions.h"

//peice class to hold how the peices move and their position

Peice::Peice(int x, int y) { Position.push_back(x); Position.push_back(y); };
vector<int> Peice::GetPosition() { return Position; };
void Peice::SetPosition(int x, int y) { Position[0] = x; Position[1] = y; };

void Peice::select() {}; 
void Peice::move() {};
void Pawn::move() {};
void Rook::move() {};
void Knight::move() {};
void Bishop::move() {};
void Queen::move() {};
void King::move() {};

void Board::addpeice(Peice p) { Peices.push_back(p); };
	void Board::removePeice(Peice p) {};
	void Board::Display() { 
		for (int x = 0; x < rows->size(); x++) {
			for (int y = 0; y < 9; y++) {
				cout << rows[x][y] << " " ;
			}
			cout << endl;
		}
	};
