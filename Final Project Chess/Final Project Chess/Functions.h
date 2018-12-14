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
	void SetPlayer(int P);
	int GetPlayer();
	bool move(int x, int y);
	void Settype(char t);
	char Gettype();
protected:
	char type;
	vector<int>Position;
	char Player;
};

// all the peice subclasses have difrent ways to move
 class Pawn : public Peice{
 public:
	 Pawn(int x, int y);
	 bool move(int x, int y);
 private:
	 char type;
 };
 class Rook : public Peice {
 public:
	 Rook(int x, int y);
	 bool move(int x, int y);
 };
 class Knight : public Peice {
 public:
	 Knight(int x, int y);
	 bool move(int x, int y);
 };
 class Bishop : public Peice {
 public:
	 Bishop(int x, int y);
	 bool move(int x, int y);
 };
 class Queen : public Peice {
 public:
	 Queen(int x, int y);
	 bool move(int x, int y);
 }; 
 class King : public Peice {
 public:
	 King(int x, int y);
	 bool move(int x, int y);
 };

//board class to display the board and keep track of the peieces turns etc.
class Board {
public:
	void addpeice(Peice p);
	void removePeice(Peice* p);
	void Display();
	void Reset();
	void select();
	void SetTurn(int t);
	int Getturn();
	string rows[9] = { "........","........", "........", "........", "........", "........", "........", "........" };
private:
	int turn;
	vector<Peice*>Peices;
	
};

//GameManager class to hold all the miscelaneous stuff like instructions
class GameManager {
public:
	void Instructions();
private:
};