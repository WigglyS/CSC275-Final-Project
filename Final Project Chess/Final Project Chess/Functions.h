#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//peice class to hold how the peices move and their position
class Peice {
public:
	Peice(int x,int y);
	vector<int> GetPosition();
	void SetPosition(int x, int y);

	void select();
	void move();
protected:
	vector<int>Position;
	char type;
};

 class Pawn : public Peice{
	 void move();
 };
 class Rook : public Peice {
	 void move();
 };
 class Knight : public Peice {
	 void move();
 };
 class Bishop : public Peice {
	 void move();
 };
 class Queen : public Peice {
	 void move();
 }; 
 class King : public Peice {
	 void move();
 };

//board class to display the board and keep track of the peieces
class Board {
public:
	void addpeice(Peice p);
	void removePeice(Peice p);
	void Display();
private:
	vector<Peice>Peices;
	string rows[9] = { "........","........", "........", "........", "........", "........", "........", "........" };;
};