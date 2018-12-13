#include "Functions.h"


Peice::Peice() {};
Peice::Peice(int x, int y) { Position.push_back(x); Position.push_back(y); };
vector<int> Peice::GetPosition() { return Position; };
void Peice::SetPosition(int x, int y) { Position[0] = x; Position[1] = y; };
void Peice::SetPlayer(int P) { Player = P; };



//returns true if spot is valid to move to
bool Peice::move() { return true; };
bool Pawn::move() { return true; };
Pawn::Pawn(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Rook::move() { return true; };
Rook::Rook(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Knight::move() { return true; };
Knight::Knight(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Bishop::move() { return true; };
Bishop::Bishop(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Queen::move() { return true; };
Queen::Queen(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool King::move() { return true; };
King::King(int x, int y) { Position.push_back(x); Position.push_back(y); }

void Board::addpeice(Peice p) { Peices.push_back(&p); };
void Board::removePeice(Peice* p) { };
int Board::Getturn() { return turn; };
void Board::SetTurn(int t) { turn = t; };

//Displays the board to the consol so you can see it
void Board::Display() { 
	system("CLS");
	int Numbering[8] = { 0,1,2,3,4,5,6,7 };
	cout << "  ";
	for (int x = 0; x < 8; x++) {
		cout << Numbering[x] << " ";
	}
	cout << endl;
	for (int x = 0; x < rows->size(); x++) {
		cout <<Numbering[x] << " ";
		for (int y = 0; y < 9; y++) {
			cout  << rows[x][y] << " " ;
		}
		cout << endl;
	}
};

// set the board up to the correct configuration to start in
void Board::Reset() {
	Peices.clear();
	turn = 0;
	for (int i = 0; i < 8; i++){
		Peices.push_back(new Pawn(1,i));
		Peices[i]->SetPosition(1, i);
		Peices[i]->SetPlayer(0);
		rows[1][i] = 'p';
	}
	Peices.push_back(new Rook(0, 0));
	rows[0][0] = 'r';
	Peices.push_back(new Rook(0, 7));
	rows[0][7] = 'r';

	Peices.push_back(new Bishop(0, 2));
	rows[0][2] = 'b';
	Peices.push_back(new Bishop(0, 5));
	rows[0][5] = 'b';

	Peices.push_back(new Knight(0, 1));
	rows[0][1] = 'n';
	Peices.push_back(new Knight(0, 6));
	rows[0][6] = 'n';

	Peices.push_back(new King(0, 4));
	rows[0][4] = 'k';
	Peices.push_back(new Queen(0, 3));
	rows[0][3] = 'q';

	for (int i = 0; i < 8; i++) {
		Peices.push_back(new Pawn(6, i));
		Peices[i]->SetPosition(6, i);
		Peices[i]->SetPlayer(1);
		rows[6][i] = 'P';
	}

	Peices.push_back(new Rook(7, 0));
	rows[7][0] = 'R';
	Peices.push_back(new Rook(7, 7));
	rows[7][7] = 'R';

	Peices.push_back(new Bishop(7, 2));
	rows[7][2] = 'B';
	Peices.push_back(new Bishop(7, 5));
	rows[7][5] = 'B';

	Peices.push_back(new Knight(7, 1));
	rows[7][1] = 'N';
	Peices.push_back(new Knight(7, 6));
	rows[7][6] = 'N';

	Peices.push_back(new King(7, 4));
	rows[7][4] = 'K';
	Peices.push_back(new Queen(7, 3));
	rows[7][3] = 'Q';
};

// function where the player selects the peice they want to move
void Board::select() {
	int X;
	int Y;
	vector<int> coordinents;
	vector<int> Temp;
	if (turn == 0) {
		cout << "It is the Uppercase letters persons turn" << endl;
	}
	else if (turn == 1) {
		cout << "It is the Lowercase letters persons turn" << endl;
	}
	

	cout << endl << "Enter the x coridnent of the space of the peice you would like to move : ";
	cin >> X;
	cout << endl << "Enter the Y coridnent of the space of the peice you would like to move : ";
	cin >> Y;

	coordinents.push_back(X);
	coordinents.push_back(Y);
	
	for (int i = 0; i < Peices.size(); i++) {
		Temp = Peices[i]->GetPosition();
		if ((Temp[0] == coordinents[0]) && (Temp[1] == coordinents[1])) {

			cout << "move";
			//do the whole moving the peice thingy;
		}
		else{
			cout << "That is not a valid peice" << endl;
		}
	}
};


void GameManager::Instructions(){
	cout << " " << endl;
	system("pause");
};

