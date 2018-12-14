#include "Functions.h"



void main() {
	Board B;
	GameManager GM;
	B.GameEnd = 0;

	GM.Instructions();
	B.Reset();
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
	
		// use destructoron king object to call game over maybe?
	cout << "Thank you for playing" << endl;
	system("pause");
}