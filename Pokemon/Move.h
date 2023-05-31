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
 * Description: This C++ program declare the Move class
***********************************************************************/
#pragma once
#include <string>
#include <vector>

class Move
{
private:
	std::string name;
	std::string type;
	std::string attackType;
	int power;
	int accuracy;
	int powerPoint;
	std::string effect;
public:
	Move();
	Move(std::string, std::string, std::string, int, int, int, std::string);

	void setName(std::string);
	void setType(std::string);
	void setAttackType(std::string);
	void setPower(int);
	void setAccuracy(int);
	void setPowerPoint(int);
	void setEffect(std::string);

	std::string getName();
	std::string getType();
	std::string getAttackType();
	int getPower();
	int getAccuracy();
	int getPowerPoint();
	std::string getEffect();
};
