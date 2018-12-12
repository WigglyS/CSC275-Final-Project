#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//peice class to hold how the peices move and their position
class Peice {
public:
	Peice();
	Peice(int x,int y);
	vector<int> GetPosition();
	void SetPosition(int x, int y);

	bool move();
protected:
	vector<int>Position;
	char Player;
};

 class Pawn : public Peice{
 public:
	 Pawn(int x, int y);
	 bool move();
 };
 class Rook : public Peice {
	 bool move();
 };
 class Knight : public Peice {
	 bool move();
 };
 class Bishop : public Peice {
	 bool move();
 };
 class Queen : public Peice {
	 bool move();
 }; 
 class King : public Peice {
	 bool move();
 };

//board class to display the board and keep track of the peieces
class Board {
public:
	void addpeice(Peice p);
	void removePeice(Peice p);
	void Display();
	void Reset();
private:
	vector<Peice*>Peices;
	string rows[9] = { "........","........", "........", "........", "........", "........", "........", "........" };;
};

//GameManager class to hold all the miscelaneous stuff like instructions
class GameManager {
public:
	void Instructions();
	int Getturn();
	void SetTurn(int t);
	void select();
private:
	int turn;
};