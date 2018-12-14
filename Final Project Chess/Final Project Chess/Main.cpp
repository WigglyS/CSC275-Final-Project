#include "Functions.h"



void main() {
	Board B;
	GameManager GM;
	B.GameEnd = 0;

	GM.Instructions();
	B.Reset();
	string name1;
	string name2;
	cout << "Enter players names: \nUpperCase Player(goes first) :";
	cin >> name1;
	cout << endl << "Lowercase Player(goes second) :";
	cin >> name2;

	B.Setnames(name1, name2);
	do {
		B.Display();
		B.select();

		if (B.Getturn() == 1) {
			B.SetTurn(0);
		}
		else if (B.Getturn() == 0) {
			B.SetTurn(1);
		}

	}while(B.GameEnd == 0);
	
	cout << "Thank you for playing" << endl;
	system("pause");
}