#include "Functions.h"


void main() {
	Board B;
	GameManager GM;

	int GameLoop = 0;

	GM.Instructions();
	B.Reset();
	do {
		B.Display();
		B.select();

		if (B.Getturn() == 1) {
			B.SetTurn(0);
		}
		if (B.Getturn() == 0) {
			B.SetTurn(1);
		}
	}while(GameLoop == 0);
	
		// use destructoron king object to call game over maybe?
	system("pause");
}