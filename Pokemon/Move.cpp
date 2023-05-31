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
 * Description: This C++ program define the Move class
***********************************************************************/
#include "Move.h"

Move::Move()
{
	this->name = "NONE";
	this->type.clear();
	this->attackType.clear();
	this->power = 0;
	this->accuracy = 0;
	this->powerPoint = 0;
	this->effect = "NONE";
}

Move::Move(std::string name, std::string type, std::string attackType, int power, int accuracy, int powerPoint, std::string effect)
{
	this->name = name;
	this->type = type;
	this->attackType = attackType;
	this->power = power;
	this->accuracy = accuracy;
	this->powerPoint = powerPoint;
	this->effect = effect;
}

void Move::setName(std::string name)
{
	this->name = name;
}

void Move::setType(std::string type)
{
	this->type = type;
}

void Move::setAttackType(std::string attackType)
{
	this->attackType = attackType;
}

void Move::setPower(int power)
{
	this->power = power;
}

void Move::setAccuracy(int accuracy)
{
	this->accuracy = accuracy;
}

void Move::setPowerPoint(int powerPoint)
{
	this->powerPoint = powerPoint;
}

void Move::setEffect(std::string effect)
{
	this->effect = effect;
}

std::string Move::getName()
{
	return this->name;
}

std::string Move::getType()
{
	return this->type;
}

std::string Move::getAttackType()
{
	return this->attackType;
}

int Move::getPower()
{
	return this->power;
}

int Move::getAccuracy()
{
	return this->accuracy;
}

int Move::getPowerPoint()
{
	return this->powerPoint;
}

std::string Move::getEffect()
{
	return this->effect;
}
