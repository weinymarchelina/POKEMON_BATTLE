/***********************************************************************
 * File: main.cpp
 * Author:	Áé¸ÖÆF B11115010
 *			³¯¥K¿³ B11115011
 *			ÃQ¬üªÚ B11115014
 * Create Date: 2023-05-26
 * Editor:	Áé¸ÖÆF B11115010
 *			³¯¥K¿³ B11115011
 *			ÃQ¬üªÚ B11115014
 * Update Date: 2023-06-
 * Description: This C++ program declare the Pokemon class
***********************************************************************/
#pragma once
#include <string>
#include <vector>
#include "Move.h"

class Pokemon
{
private:
	std::string name;
	std::vector <std::string> type;
	int hp;
	int attack;
	int spAttack;
	int defense;
	int spDefense;
	int speed;
	std::string status;
	std::vector <Move> moves;

public:
	Pokemon();
	Pokemon(std::string, std::vector <std::string>, int, int, int, int, int, int, std::string, std::vector<Move>);
	Pokemon(std::string, std::vector <std::string>, int, int, int, int, int, int);

	void setName(std::string);
	void setType(std::vector <std::string>);
	void setHp(int);
	void setAttack(int);
	void setSpAttack(int);
	void setDefense(int);
	void setSpDefense(int);
	void setSpeed(int);
	void setStatus(std::string);
	void setMoves(std::vector<Move>);

	std::string getName();
	std::vector <std::string> getType();
	int getHp();
	int getAttack();
	int getSpAttack();
	int getDefense();
	int getSpDefense();
	int getSpeed();
	std::string getStatus();
	std::vector <Move> getMoves();

	//Pokemon& operator= (const Pokemon&);
};
