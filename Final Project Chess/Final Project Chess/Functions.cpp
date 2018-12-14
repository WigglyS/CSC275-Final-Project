#include "Functions.h"


Peice::Peice() {};
Peice::Peice(int x, int y) { Position.push_back(x); Position.push_back(y); };
vector<int> Peice::GetPosition() { return Position; };
void Peice::SetPosition(int x, int y) { Position[0] = x; Position[1] = y; };
void Peice::SetPlayer(int P) { Player = P; };
int Peice::GetPlayer() { return Player; };
void Peice::Settype(char t) { type = t; };
char Peice::Gettype() { return type; };


//Move functions that returns true if spot is valid to move to and constructors
bool Peice::move(int x, int y) { return true; };
//pawns can move 2 forward on their first move but every other only one // cant quite figure out how to make them attack diagnally yet
bool Pawn::move(int x, int y) {
	if ((Position[0] != x) || (Position[1] != y)) {
		if (Player == 0) {
			
			if ((Position[0] == x) && (Position[1] + 1 == y)) {
				FirstMove = 1;
				return true;
			}
			else if ((FirstMove == 0) && (Position[0] == x) && (Position[1] + 2 == y)) {
				FirstMove = 1;
				return true;
			}
			else {
				return false;
			}
		}
		if (Player == 1) {

			if ((Position[0] == x) && (Position[1] - 1 == y)) {
				return true;
			}
			else if ((FirstMove == 0) && (Position[0] == x) && (Position[1] - 2 == y)) {
				FirstMove = 1;
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		cout << "The peice is already on that space " << endl;
		return false;
	}
};
Pawn::Pawn(int x, int y) { Position.push_back(x); Position.push_back(y); }

//will make all the others limit movement if i have time :/
bool Rook::move(int x, int y) { 
	return true; 
};
Rook::Rook(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Knight::move(int x, int y) { 
	return true;
};
Knight::Knight(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Bishop::move(int x, int y) { 
	return true; 
};
Bishop::Bishop(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool Queen::move(int x, int y) { 
	return true; 
};
Queen::Queen(int x, int y) { Position.push_back(x); Position.push_back(y); }
bool King::move(int x, int y) { 
	return true; 
};
King::King(int x, int y) { Position.push_back(x); Position.push_back(y); }
King::~King() {
	if (Player == 0) {
		cout << "The Uppercase Player won the Game!" << endl;
	}
	if (Player == 1) {
		cout << "The Lowercase Player won the Game!" << endl;
	}
	
};

void Board::addpeice(Peice p) { Peices.push_back(&p); };
void Board::removePeice(Peice* p) { };
int Board::Getturn() { return turn; };
void Board::SetTurn(int t) { turn = t; };
void Board::Setnames(string name1, string name2) { Names[0] = name1; Names[1] = name2; };

//Displays the board to the consol so you can see it
void Board::Display() { 
	system("CLS");
	int Numbering[8] = { 0,1,2,3,4,5,6,7 };
	cout << "     ";
	
	for (int x = 0; x < 8; x++) {
		cout << Numbering[x] << " ";
	}
	cout << endl;
	cout << "  =====================" << endl;//

	for (int x = 0; x < rows->size(); x++) {
		cout <<Numbering[x] << " =  ";//
		for (int y = 0; y < 9; y++) {
			cout  << rows[x][y] ;
			if (y < 8) {
				cout << " ";
			}
		}
		cout << "=" << endl;//
	}
	cout << "  =====================" << endl;//
	cout << "     ";
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
		Peices.push_back(new Pawn(i,1));
		//Peices[i]->SetPosition(1, i);
		Peices[i]->SetPlayer(0);
		Peices[i]->Settype('p');
	}
	Peice* temp = new Rook(0, 0);

	Peices.push_back(temp);
	temp->SetPlayer(0);
	temp->Settype('r');

	temp = new Rook(7, 0);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	temp->Settype('r');
	
	temp = new Bishop(2, 0);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	temp->Settype('b');

	temp = new Bishop(5, 0);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	temp->Settype('b');
	
	temp = new Knight(1, 0);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	temp->Settype('n');
	
	temp = new Knight(6, 0);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	temp->Settype('n');
	
	temp = new King(4, 0);
	Peices.push_back(temp);
	temp->SetPlayer(0);
	temp->Settype('k');
	
	temp = new Queen(3, 0);
	Peices.push_back(temp);
	temp->SetPlayer(0); 
	temp->Settype('q');
	
	for (int i = 0; i < 8; i++) {
		temp = (new Pawn(i, 6));
		Peices.push_back(temp);
		temp->SetPosition(i, 6);
		temp->SetPlayer(1); 
		temp->Settype('P');
	}

	temp = new Rook(0, 7);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	temp->Settype('R');
	
	temp = new Rook(7, 7);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	temp->Settype('R');
	
	temp = new Bishop(2, 7);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	temp->Settype('B');
	
	temp = new Bishop(5, 7);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	temp->Settype('B');
	
	temp = new Knight(1, 7);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	temp->Settype('N');
	
	temp = new Knight(6, 7);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	temp->Settype('N');
	
	temp = new King(4, 7);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	temp->Settype('K');
	
	temp = new Queen(3, 7);
	Peices.push_back(temp);
	temp->SetPlayer(1);
	temp->Settype('Q');
	
	for (int i = 0; i < Peices.size(); i++) {
		vector<int >DisplayVect = Peices[i]->GetPosition();
		rows[DisplayVect[1]][DisplayVect[0]] = Peices[i]->Gettype();
	}
};

// function where the player selects the peice they want to move and moves it
void Board::select() {
	//first displays which players turn it is
	int X;
	int Y;
	if (turn == 1) {
		cout << endl << "It is " << Names[0]<<"'s turn (Uppercase letters)" << endl;
	}
	else if (turn == 0) {
		cout << endl << "It is " << Names[1] << "'s turn (Lowercase letters)" << endl;
	}
	
	// has the player pick the peice they want to move
	vector<int> Temp;
	int HasSelected = 0;
	Peice* Selected = NULL;
	do {

		cout << endl << "Enter the x coordinate of the space of the peice you would like to move : ";
		cin >> X;
		cout << endl << "Enter the Y coordinate of the space of the peice you would like to move : ";
		cin >> Y;



		for (int i = 0; i < Peices.size(); i++) {
			Temp = Peices[i]->GetPosition();
			if ((Temp[0] == X) && (Temp[1] == Y)) {
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
	
	//actually moves the peice
	int validMove = 0;
	do {
		// gets the user input of where they want to move
		int MoveX;
		int MoveY;

		cout << endl << "Enter the x coordinate of the space you would like to move to : ";
		cin >> MoveX;
		cout << endl << "Enter the Y coordinate of the space you would like to move to : ";
		cin >> MoveY;

		if (Selected->move(MoveX,MoveY) == true) {
			for (int i = 0; i < Peices.size(); i++) {
				Temp = Peices[i]->GetPosition();
				if ((Temp[0] == MoveX) && (Temp[1] == MoveY)) {
					cout << "Player " << Peices[i]->GetPlayer() << "'s " << Peices[i]->Gettype() << " has been captured" << endl; 
					if (Peices[i]->Gettype() == 'k') {
						cout << Names[0] << " won the Game! (Uppercase Letters)" << endl;
						GameEnd = 1;
						ofstream outfile;
						outfile.open("Recorded Games",ofstream::app);
						outfile << Names[0] << " Vs " << Names[1] << ", " << Names[0] << " won the game" << endl;
						outfile.close();
					}
					if (Peices[i]->Gettype() == 'K') {
						cout << Names[1] <<" won the Game! (Lowercase letters)" << endl;
						GameEnd = 1;
						ofstream outfile;
						outfile.open("Recorded Games", ofstream::app);
						outfile << Names[0] << " Vs " << Names[1] << ", " << Names[1] << " won the game" << endl;
						outfile.close();
					}
					Peices.erase(Peices.begin()+(i));
					
				}
			}
			rows[MoveY][MoveX] = Selected->Gettype();
			vector<int>temp = Selected->GetPosition();
			rows[temp[1]][temp[0]] = '.';
			Selected->SetPosition(MoveX, MoveY);
			validMove = 1;	
		}
		else {
			cout << "That is not a Valid Move" << endl;
		}
	} while (validMove == 0);
	system("pause");
};

// instructions for the game
void GameManager::Instructions(){
	cout << "Welcome to my basic chess game!!" << endl;
	cout << "The players peices are distingushed through uppercase vs lowercase letters" << endl;
	cout << "p/P = Pawn		r/R = Rook" << endl;
	cout << "n/N = Knight		b/B = Bishop" << endl;
	cout << "q/Q = Queen		k/K = King" << endl;
	cout << "Type 'Help' for Rules, 'Results' for previous game results and 'Play' to start the Game." << endl;
	int play = 0;
	do {
		string input;
		cin >> input;
		if ((input == "Help") || (input == "help")){
			cout << "rules that i havent put in yet :/" << endl;
		}
		if ((input == "Play") || (input == "play")) {
			play = 1;
		}
		if ((input == "Results") || (input == "results")) {
			ifstream infile;
			infile.open("Recorded Games");
			string oneLine;
			while (getline(infile, oneLine)) {
				cout << oneLine << endl;
			}
			infile.close();
		}
	} while (play == 0);
};
int GameManager::GetEnd() { return End; };
void GameManager::SetEnd(int i) { End = i; };


