#include "Functions.h"


void main() {
	Board B;
	GameManager GM;
	GM.Instructions();
	B.Reset();
	//do {
		B.Display();
		B.select();
	//}while();
	
		// use destructoron king object to call game over maybe?
	system("pause");
}