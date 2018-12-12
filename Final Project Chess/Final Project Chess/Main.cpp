#include "Functions.h"


void main() {
	Board B;
	GameManager GM;
	GM.Instructions();
	B.Reset();
	B.Display();

	system("pause");
}