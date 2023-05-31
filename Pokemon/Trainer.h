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
 * Description: This C++ program declare the Trainer class
***********************************************************************/
#pragma once
#include "Pokemon.h"
#include "Item.h"

class Trainer
{
private:
	std::vector <Pokemon> pokemon;
	std::vector <Item> item;
public:
	Trainer();
	Trainer(std::vector <Pokemon>, std::vector <Item>);

	void setPokemon(std::vector <Pokemon>);
	void setItem(std::vector <Item>);

	std::vector <Pokemon>& getPokemon();
	std::vector <Item>& getItem();
};
