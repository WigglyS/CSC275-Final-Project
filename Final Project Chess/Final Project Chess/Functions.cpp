#include "Functions.h"


Peice::Peice() {};
Peice::Peice(int x, int y) { Position.push_back(x); Position.push_back(y); };
vector<int> Peice::GetPosition() { return Position; };
void Peice::SetPosition(int x, int y) { Position[0] = x; Position[1] = y; };
void Peice::SetPlayer(int P) { Player = P; };
int Peice::GetPlayer() { return Player; };


//Move functions that returns true if spot is valid to move to and constructors
bool Peice::move() { return true; };
bool Pawn::move(int x, int y) { return true; };
Pawn::Pawn(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Rook::move(int x, int y) { return true; };
Rook::Rook(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Knight::move(int x, int y) { return true; };
Knight::Knight(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Bishop::move(int x, int y) { return true; };
Bishop::Bishop(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Queen::move(int x, int y) { return true; };
Queen::Queen(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool King::move(int x, int y) { return true; };
King::King(int x, int y) { Position.push_back(x); Position.push_back(y); }

void Board::addpeice(Peice p) { Peices.push_back(&p); };
void Board::removePeice(Peice* p) { };
int Board::Getturn() { return turn; };
void Board::SetTurn(int t) { turn = t; };

//Displays the board to the consol so you can see it
void Board::Display() { 
	system("CLS");
	int Numbering[8] = { 0,1,2,3,4,5,6,7 };
	cout << "    ";
	
	for (int x = 0; x < 8; x++) {
		cout << Numbering[x] << " ";
	}
	cout << endl;
	cout << "  ====================" << endl;//

	for (int x = 0; x < rows->size(); x++) {
		cout <<Numbering[x] << " = ";//
		for (int y = 0; y < 9; y++) {
			cout  << rows[x][y] ;
			if (y < 8) {
				cout << " ";
			}
		}
		cout << "=" << endl;//
	}
	cout << "  ====================" << endl;//
	cout << "    ";
	for (int x = 0; x < 8; x++) {
		cout << Numbering[x] << " ";
	}
	cout << endl;
};

// set the board up to the correct configuration to start in
void Board::Reset() {
	Peices.clear();
	turn = 1;
	for (int i = 0; i < 8; i++){
		Peices.push_back(new Pawn(1,i));
		//Peices[i]->SetPosition(1, i);
		Peices[i]->SetPlayer(0);
		rows[1][i] = 'p';
	}
	Peice* temp = new Rook(0, 0);

	Peices.push_back(temp);
	temp->SetPlayer(0);
	rows[0][0] = 'r';

	temp = new Rook(0, 7);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	rows[0][7] = 'r';
	
	temp = new Bishop(0, 2);
	Peices.push_back(new Bishop(0, 2));
	temp->SetPlayer(0);
	rows[0][2] = 'b';

	temp = new Bishop(0, 5);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	rows[0][5] = 'b';

	temp = new Knight(0, 1);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	rows[0][1] = 'n';

	temp = new Knight(0, 6);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	rows[0][6] = 'n';

	temp = new King(0, 4);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	rows[0][4] = 'k';

	temp = new Queen(0, 3);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	rows[0][3] = 'q';

	for (int i = 0; i < 8; i++) {
		Peices.push_back(new Pawn(6, i));
		Peices[i]->SetPosition(6, i);
		Peices[i]->SetPlayer(1);
		rows[6][i] = 'P';
	}

	temp = new Rook(7, 0);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	rows[7][0] = 'R';

	temp = new Rook(7, 7);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	rows[7][7] = 'R';

	temp = new Bishop(7, 2);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	rows[7][2] = 'B';

	temp = new Bishop(7, 5);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	rows[7][5] = 'B';

	temp = new Knight(7, 1);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	rows[7][1] = 'N';

	temp = new Knight(7, 6);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	rows[7][6] = 'N';

	temp = new King(7, 4);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	rows[7][4] = 'K';

	temp = new Queen(7, 3);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	rows[7][3] = 'Q';
};

// function where the player selects the peice they want to move
void Board::select() {
	int X;
	int Y;
	if (turn == 1) {
		cout << endl << "It is the Uppercase letters persons turn" << endl;
	}
	else if (turn == 0) {
		cout << endl << "It is the Lowercase letters persons turn" << endl;
	}
	

	vector<int> Temp;
	vector<int> coordinents = { 0,0 };
	int HasSelected = 0;
	Peice* Selected = NULL;
	do {

		cout << endl << "Enter the x coordinate of the space of the peice you would like to move : ";
		cin >> X;
		cout << endl << "Enter the Y coordinate of the space of the peice you would like to move : ";
		cin >> Y;

		coordinents[0]= X;
		coordinents[1] =Y;


		for (int i = 0; i < Peices.size(); i++) {
			Temp = Peices[i]->GetPosition();
			if ((Temp[0] == coordinents[0]) && (Temp[1] == coordinents[1])) {
				if ((Peices[i]->GetPlayer()) == turn) {
					Selected = Peices[i];
					HasSelected = 1;
					break;
				}
				else {
					cout << "That is not your Peice"<< endl;
				}
			}
		}
		if (HasSelected == 0) {
			cout << "That is not a valid peice" << endl;
		}
	} while (HasSelected == 0);
	

	int validMove = 0;
	do {
		int MoveX;
		int MoveY;

		//do the whole moving the peice thingy
		cout << endl << "Enter the x coordinate of the space you would like to move to : ";
		cin >> MoveX;
		cout << endl << "Enter the Y coordinate of the space you would like to move to : ";
		cin >> MoveY;

		if (Selected->move() == true) {
			//Actually move the peice
			cout << "valid Move";
			rows[MoveY][MoveX] = '1';
			validMove = 1;
		}
		else {
			cout << "That is not a Valid Move" << endl;
		}
	} while (validMove = 0);
};


void GameManager::Instructions(){
	cout << "Welcome to my basic chess game!!" << endl;
	cout << "The players peices are distingushed through uppercase vs lowercase letters" << endl;
	cout << "p/P = Pawn		r/R = Rook" << endl;
	cout << "n/N = Knight		b/B = Bishop" << endl;
	cout << "q/Q = Queen		k/K = King" << endl;
	cout << "Type 'Help' for Rules and 'Play' to start the Game." << endl;
	int play = 0;
	do {
		string input;
		cin >> input;
		if ((input == "Help") || (input == "help")){
			cout << "rules" << endl;
		}
		if ((input == "Play") || (input == "play")) {
			play = 1;
		}
	} while (play == 0);
};

