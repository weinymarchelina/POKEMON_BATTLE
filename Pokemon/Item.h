/***********************************************************************
 * File: main.cpp
 * Author:	����F B11115010
 *			���K�� B11115011
 *			�Q���� B11115014
 * Create Date: 2023-05-26
 * Editor:	����F B11115010
 *			���K�� B11115011
 *			�Q���� B11115014
 * Update Date: 2023-06-
 * Description: This C++ program declare the Item class
***********************************************************************/
#pragma once
#include <string>

class Item
{
private:
	std::string name;
	int boost;
	std::string boostType;
	bool isUsed;

public:
	Item();
	Item(std::string, int, std::string);

	void setName(std::string);
	void setBoost(int);
	void setBoostType(std::string);
	void setIsUsed(bool);

	std::string getName();
	int getBoost();
	std::string getBoostType();
	bool getIsUsed();
};
