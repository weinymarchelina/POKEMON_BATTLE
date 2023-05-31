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
 * Description: This C++ program define the Item class
***********************************************************************/
#include "Item.h"

Item::Item()
{
	this->name = "NONE";
	this->boost = 0;
	this->boostType = "HP";
}

Item::Item(std::string name, int, std::string boostType)
{
	this->name = name;
	this->boost = boost;
	this->boostType = boostType;
}

void Item::setName(std::string name)
{
	this->name = name;
}

void Item::setBoost(int boost)
{
	this->boost = boost;
}

void Item::setBoostType(std::string boostType)
{
	this->boostType = boostType;
}

std::string Item::getName()
{
	return this->name;
}

int Item::getBoost()
{
	return this->boost;
}

std::string Item::getBoostType()
{
	return this->boostType;
}
