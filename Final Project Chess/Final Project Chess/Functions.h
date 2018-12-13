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
	bool move();
protected:
	vector<int>Position;
	char Player;
};

 class Pawn : public Peice{
 public:
	 Pawn(int x, int y);
	 bool move(int x, int y);
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
private:
	int turn;
	vector<Peice*>Peices;
	string rows[9] = { "........","........", "........", "........", "........", "........", "........", "........" };;
};

//GameManager class to hold all the miscelaneous stuff like instructions
class GameManager {
public:
	void Instructions();
private:
};