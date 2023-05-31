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
 * Description: This C++ program define the Pokemon class
***********************************************************************/

#include "Pokemon.h"

Pokemon::Pokemon()
{
	this->name = "NONE";
	this->type.clear();
	this->hp = 0;
	this->attack = 0;
	this->spAttack = 0;
	this->defense = 0;
	this->spDefense = 0;
	this->speed = 0;
	this->status = "NONE";
	this->moves.clear();
}

Pokemon::Pokemon(std::string name, std::vector <std::string> type, int hp, int attack, int spAttack, int defense, int spDefense, int speed, std::string status, std::vector<Move> moves)
{
	this->name = name;
	this->type = type;
	this->hp = hp;
	this->attack = attack;
	this->spAttack = spAttack;
	this->defense = defense;
	this->spDefense = spDefense;
	this->speed = speed;
	this->status = status;
	this->moves = moves;
}

Pokemon::Pokemon(std::string name, std::vector <std::string> type, int hp, int attack, int spAttack, int defense, int spDefense, int speed)
{
	this->name = name;
	this->type = type;
	this->hp = hp;
	this->attack = attack;
	this->spAttack = spAttack;
	this->defense = defense;
	this->spDefense = spDefense;
	this->speed = speed;
	this->status = "NONE";
	this->moves.clear();
}

void Pokemon::setName(std::string name)
{
	this->name = name;
}

void Pokemon::setType(std::vector <std::string> type)
{
	this->type = type;
}

void Pokemon::setHp(int hp)
{
	this->hp = hp;
}

void Pokemon::setAttack(int attack)
{
	this->attack = attack;
}

void Pokemon::setSpAttack(int spAttack)
{
	this->spAttack = spAttack;
}

void Pokemon::setDefense(int defense)
{
	this->defense = defense;
}

void Pokemon::setSpDefense(int spDefense)
{
	this->spDefense = spDefense;
}

void Pokemon::setSpeed(int speed)
{
	this->speed = speed;
}

void Pokemon::setStatus(std::string status)
{
	this->status = status;
}

void Pokemon::setMoves(std::vector<Move> moves)
{
	this->moves = moves;
}

std::string Pokemon::getName()
{
	return this->name;
}

std::vector <std::string> Pokemon::getType()
{
	return this->type;
}

int Pokemon::getHp()
{
	return this->hp;
}

int Pokemon::getAttack()
{
	return this->attack;
}

int Pokemon::getSpAttack()
{
	return this->spAttack;
}

int Pokemon::getDefense()
{
	return this->defense;
}

int Pokemon::getSpDefense()
{
	return this->spDefense;
}

int Pokemon::getSpeed()
{
	return this->speed;
}

std::string Pokemon::getStatus()
{
	return this->status;
}

std::vector <Move> Pokemon::getMoves()
{
	return this->moves;
}
