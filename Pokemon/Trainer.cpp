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
 * Description: This C++ program define the Trainer class
***********************************************************************/
#include "Trainer.h"

Trainer::Trainer()
{
	this->pokemon.clear();
	this->item.clear();
}

Trainer::Trainer(std::vector <Pokemon> pokemon, std::vector <Item> item)
{
	this->pokemon = pokemon;
	this->item = item;
}

void Trainer::setPokemon(std::vector <Pokemon> pokemon)
{
	this->pokemon = pokemon;
}

void Trainer::setItem(std::vector <Item> item)
{
	this->item = item;
}

std::vector <Pokemon>& Trainer::getPokemon()
{
	return this->pokemon;
}

std::vector <Item>& Trainer::getItem()
{
	return this->item;
}
