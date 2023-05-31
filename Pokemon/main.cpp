/***********************************************************************
 * File: main.cpp
 * Author:	鍾詩靈 B11115010
 *			陳仕興 B11115011
 *			魏美芳 B11115014
 * Create Date: 2023-05-26
 * Editor:	鍾詩靈 B11115010
 *			陳仕興 B11115011
 *			魏美芳 B11115014
 * Update Date: 2023-06-
 * Description: This C++ program is the main program
***********************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include "Trainer.h"

std::vector<std::vector<double>> effectivenessChart = {
 {1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  0.5,  0.0,  1.0,  1.0,  0.5,  1.0},
 {1.0,  0.5,  0.5,  1.0,  2.0,  2.0,  1.0,  1.0,  1.0,  1.0,  1.0,  2.0,  0.5,  1.0,  0.5,  1.0,  2.0,  1.0},
 {1.0,  2.0,  0.5,  1.0,  0.5,  1.0,  1.0,  1.0,  2.0,  1.0,  1.0,  1.0,  2.0,  1.0,  0.5,  1.0,  1.0,  1.0},
 {1.0,  1.0,  2.0,  0.5,  0.5,  1.0,  1.0,  1.0,  0.0,  2.0,  1.0,  1.0,  1.0,  1.0,  0.5,  1.0,  1.0,  1.0},
 {1.0,  0.5,  2.0,  1.0,  0.5,  1.0,  1.0,  0.5,  2.0,  0.5,  1.0,  0.5,  2.0,  1.0,  0.5,  1.0,  0.5,  1.0},
 {1.0,  0.5,  0.5,  1.0,  2.0,  0.5,  1.0,  1.0,  2.0,  2.0,  1.0,  1.0,  1.0,  1.0,  2.0,  1.0,  0.5,  1.0},
 {2.0,  1.0,  1.0,  1.0,  1.0,  2.0,  1.0,  0.5,  1.0,  0.5,  0.5,  0.5,  2.0,  0.0,  1.0,  2.0,  2.0,  0.5},
 {1.0,  1.0,  1.0,  1.0,  2.0,  1.0,  1.0,  0.5,  0.5,  1.0,  1.0,  1.0,  0.5,  0.5,  1.0,  1.0,  0.0,  2.0},
 {1.0,  2.0,  1.0,  2.0,  0.5,  1.0,  1.0,  2.0,  1.0,  0.0,  1.0,  0.5,  2.0,  1.0,  1.0,  1.0,  2.0,  1.0},
 {1.0,  1.0,  1.0,  0.5,  2.0,  1.0,  2.0,  1.0,  1.0,  1.0,  1.0,  2.0,  0.5,  1.0,  1.0,  1.0,  0.5,  1.0},
 {1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  2.0,  2.0,  1.0,  1.0,  0.5,  1.0,  1.0,  1.0,  1.0,  0.0,  0.5,  1.0},
 {1.0,  0.5,  1.0,  1.0,  2.0,  1.0,  0.5,  0.5,  1.0,  0.5,  2.0,  1.0,  1.0,  0.5,  1.0,  2.0,  0.5,  0.5},
 {1.0,  2.0,  1.0,  1.0,  1.0,  2.0,  0.5,  1.0,  0.5,  2.0,  1.0,  2.0,  1.0,  1.0,  1.0,  1.0,  0.5,  1.0},
 {0.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  2.0,  1.0,  1.0,  2.0,  1.0,  0.5,  1.0,  1.0},
 {1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  2.0,  1.0,  0.5,  0.0},
 {1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  0.5,  1.0,  1.0,  1.0,  2.0,  1.0,  1.0,  2.0,  1.0,  0.5,  1.0,  0.5},
 {1.0,  0.5,  0.5,  0.5,  1.0,  2.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  2.0,  1.0,  1.0,  1.0,  0.5,  2.0},
 {1.0,  0.5,  1.0,  1.0,  1.0,  1.0,  2.0,  0.5,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  2.0,  2.0,  0.5,  1.0}
};

int roundCount = 0;
bool isTestMode = false;
bool isGameOver = false;
bool isPlayerWin = false;
bool isErrorCommand = false;
bool isPlayerTurn = true;
bool isTurnFinished = false;
std::vector <Pokemon> pokedex;	// Vector to store all the pokemon from the library file
std::vector <Move> moveCodex;	// Move index to store all kind of moves
std::vector <Trainer> trainerList;

Pokemon currentPlayerPokemon;
Pokemon currentEnemyPokemon;

void handleBattle(std::ifstream& iFile);
void handleBag(std::ifstream& iFile);
void handleSwap(std::ifstream& iFile);
void printStatus(std::ifstream& iFile);
void printCheck(std::ifstream& iFile);
void updateNewestPokemon();
void handleAttack(Pokemon attacker, Move usedMove, Pokemon defender);
void handleFainted(Pokemon pokemon);
double getDamageCalculation(Pokemon attacker, Move usedMove, Pokemon defender);
int getElementTypingIndex(std::string type);

int main()
{
	std::srand(time(0));

	for (int i = 0; i < 2; i++)
	{
		trainerList.push_back(Trainer());
	}

	std::ifstream iFile;

	std::string testFile;
	std::cout << "Input case File 2: ";
	std::cin >> testFile;
	iFile.open(testFile + ".txt");
	while (!iFile.is_open())
	{
		std::cout << "Invalid file, please input an valid file!\n";
		std::cout << "Input case File : ";
		std::cin >> testFile;
		iFile.open(testFile + ".txt");
	}

	std::vector <std::string> fileList;

	// Read the first three lines in the testFile (Pokemons file, Moves files, Game Data files)
	for (int i = 0; i < 3; i++)
	{
		std::string fileName;
		iFile >> fileName;
		fileList.push_back(fileName);
	}

	iFile.close();	// Close the input file

	//=======================================================================================================================
	// Read the Pokemon library file
	iFile.open(fileList[0]);
	if (!iFile.is_open())
	{
		std::cout << "Failed to read <" << fileList[0] << ".txt>" << std::endl;
		return 1;
	}

	std::string pokemonName;
	while (iFile >> pokemonName)
	{
		int typeAmount, hp, atk, deff, spAtk, spDef, speed;
		std::vector <std::string> type;

		// Read the types of the pokemon
		iFile >> typeAmount;
		for (int i = 0; i < typeAmount; i++)
		{
			std::string typeTemp;
			iFile >> typeTemp;
			type.push_back(typeTemp);
		}

		// Read the hp, attack, defense, special attack, special defense, speed of the pokemon
		iFile >> hp >> atk >> deff >> spAtk >> spDef >> speed;
		pokedex.push_back(Pokemon(pokemonName, type, hp, atk, spAtk, deff, spDef, speed));
	}

	iFile.close();

	// DEBUGGING TO VIEW POKEDEX
	std::cout << "\nDEBUGGING" << std::endl;

	for (int i = 0; i < pokedex.size(); i++)
	{
		std::cout << pokedex[i].getName() << std::endl;
		std::vector<std::string> temp = pokedex[i].getType();
		std::cout << temp.size() << " ";
		for (int j = 0; j < temp.size(); j++)
		{
			std::cout << temp[j] << " ";
		}
		std::cout << std::endl;
		std::cout << pokedex[i].getHp() << " " << pokedex[i].getAttack() << " " << pokedex[i].getDefense() << " "
			<< pokedex[i].getSpAttack() << " " << pokedex[i].getSpDefense() << " " << pokedex[i].getSpeed();
		std::cout << std::endl;
	}

	//=======================================================================================================================

	//=======================================================================================================================
	// Read the Move Library
	iFile.open(fileList[1]);
	if (!iFile.is_open())
	{
		std::cout << "Failed to read <" << fileList[1] << ".txt>" << std::endl;
		return 1;
	}

	std::string moveName;
	iFile >> moveName;
	int count = 0;
	while (!iFile.eof())
	{
		std::string type, atkType, effect;
		int power, accuracy, powerPoint;
		iFile >> type >> atkType >> power >> accuracy >> powerPoint >> effect;
		bool hasEffect = (effect == "PAR" || effect == "BRN" || effect == "PSN") ? true : false;
		if (hasEffect)
		{
			moveCodex.push_back(Move(moveName, type, atkType, power, accuracy, powerPoint, effect));
			iFile >> moveName;
		}
		else
		{
			moveCodex.push_back(Move(moveName, type, atkType, power, accuracy, powerPoint, "NONE"));
			moveName = effect;
		}
		count++;
	}

	iFile.close();

	// DEBUGGING TO VIEW MOVE CODEX
	std::cout << "\nDEBUGGING" << std::endl;
	for (int i = 0; i < moveCodex.size(); i++)
	{
		std::cout << moveCodex[i].getName() << " " << moveCodex[i].getType() << " " << moveCodex[i].getAttackType() << " "
			<< moveCodex[i].getPower() << " " << moveCodex[i].getAccuracy() << " " << moveCodex[i].getPowerPoint() << " "
			<< moveCodex[i].getEffect() << std::endl;
	}

	//=======================================================================================================================

	//=======================================================================================================================
	// Read the Game Data
	iFile.open(fileList[2]);
	if (!iFile.is_open())
	{
		std::cout << "Failed to read <" << fileList[2] << ".txt>" << std::endl;
		return 1;
	}

	int amount;
	int index = 0;
	while (iFile >> amount)
	{
		std::vector <Pokemon> pokemonNotes;
		for (int i = 0; i < amount; i++)
		{
			std::string name;
			std::vector <Move> move;
			int moveAmount;
			iFile >> name >> moveAmount;

			// Read all the Pokemon's moves
			for (int j = 0; j < moveAmount; j++)
			{
				std::string moveName;
				iFile >> moveName;
				// Search the move in the moveCodex
				for (int k = 0; k < moveCodex.size(); k++)
				{
					// If the move is in the codex, add it to the move vector
					if (moveName == moveCodex[k].getName())
					{
						move.push_back(moveCodex[k]);
						break;
					}
				}
			}

			// Search the given pokemon in the pokedex
			for (int j = 0; j < pokedex.size(); j++)
			{
				// If the pokemon is on the pokedex, appends the pokemon to the pokemonNotes and add the skills too
				if (pokedex[j].getName() == name)
				{
					pokemonNotes.push_back(pokedex[i]);
					pokemonNotes[pokemonNotes.size() - 1].setMoves(move);
					break;
				}
			}
		}
		trainerList[index].setPokemon(pokemonNotes);
		index++;
	}

	iFile.close();

	// DEBUGGING TO VIEW EACH TRAINER'S POKEMON AND EACH POKEMON'S SKILLS
	// note : it will also print the type of the skill to show that the skill is saved not only the name
	std::cout << "\nDEBUGGING" << std::endl;
	for (int i = 0; i < trainerList.size(); i++)
	{
		std::vector <Pokemon> pokeDum = trainerList[i].getPokemon();
		std::cout << pokeDum.size() << std::endl;
		for (int j = 0; j < pokeDum.size(); j++)
		{
			std::cout << pokeDum[j].getName() << " " << pokeDum[j].getMoves().size() << std::endl;
			std::vector <Move> dummy = pokeDum[j].getMoves();
			for (int k = 0; k < dummy.size(); k++)
			{
				std::cout << dummy[k].getName() << " (" << dummy[k].getType() << ") ";
			}
			std::cout << std::endl;
		}
	}

	//=======================================================================================================================

	//=======================================================================================================================
	// Read the rest of the test case code
	iFile.open(testFile + ".txt");

	std::string command = "";

	// Skip the first three file name, then get the next command
	for (int i = 0; i < 4; i++)
	{
		iFile >> command;
	}

	// 
	if (command == "Test") {
		isTestMode = true;
	}

	//
	updateNewestPokemon();

	//
	while (!isGameOver) {
		roundCount++;

		std::cout << "\n\nRound " << roundCount << std::endl;

		//
		iFile >> command;

		//
		isTurnFinished = false;

		//
		if (command == "Battle") {
			handleBattle(iFile);
		}
		else if (command == "Bag") {
			handleBag(iFile);
		}
		else if (command == "Pokemon") {
			handleSwap(iFile);
		}
		else if (command == "Status") {
			printStatus(iFile);
		}
		else if (command == "Check") {
			printCheck(iFile);
		}
		else if (command == "Exit") {
			isGameOver = true;
		}
		else {
			std::cout << "Invalid command!" << std::endl;
		}


	}

	//
	std::cout << "End of the game. Thank you for playing!" << std::endl;
}


void handleBattle(std::ifstream& iFile) {
	std::string moveCommand;
	Move playerMove;
	Move enemyMove;

	// ============================= PLAYER POKEMON'S MOVE VALIDITY CHECKER =============================
	iFile >> moveCommand;

	bool isMoveUsageValid = false;
	bool isMoveHavePP = true;

	std::vector<Move> currentPlayerPokemonMoves = currentPlayerPokemon.getMoves();

	for (Move& move : currentPlayerPokemonMoves) {
		if (move.getName() == moveCommand) {
			isMoveUsageValid = true;
			playerMove = move;

			if (move.getPowerPoint() <= 0) {
				isMoveHavePP = false;
			}
		}
	}

	if (!isMoveUsageValid) {
		std::cout << moveCommand << " is not found on player " << currentPlayerPokemon.getName() << "'s move list. Ending battle..." << std::endl;
		isErrorCommand = true;
		return;
	}
	else if (!isMoveHavePP) {
		std::cout << moveCommand << " of player " << currentPlayerPokemon.getName() << " does not have enough PP. Ending battle..." << std::endl;
		isErrorCommand = true;
		return;
	}


	// ============================= ENEMY POKEMON'S MOVE VALIDITY CHECKER =============================
	iFile >> moveCommand;

	isMoveUsageValid = false;
	isMoveHavePP = true;

	std::vector<Move> enemyPlayerPokemonMoves = currentEnemyPokemon.getMoves();

	for (Move& move : enemyPlayerPokemonMoves) {
		if (move.getName() == moveCommand) {
			isMoveUsageValid = true;
			enemyMove = move;

			if (move.getPowerPoint() <= 0) {
				isMoveHavePP = false;
			}
		}
	}

	if (!isMoveUsageValid) {
		std::cout << moveCommand << " is not found on enemy " << currentEnemyPokemon.getName() << "'s move list. Ending battle..." << std::endl;
		isErrorCommand = true;
		return;
	}
	else if (!isMoveHavePP) {
		std::cout << moveCommand << " of enemy " << currentEnemyPokemon.getName() << " does not have enough PP. Ending battle..." << std::endl;
		isErrorCommand = true;
		return;
	}


	// ============================= JUDGE POKEMON SPEED =============================
	Pokemon firstActPokemon = currentPlayerPokemon;
	Pokemon secondActPokemon = currentEnemyPokemon;
	Move firstActMove = playerMove;
	Move secondActMove = enemyMove;

	if (firstActPokemon.getSpeed() < secondActPokemon.getSpeed()) {
		firstActPokemon = currentEnemyPokemon;
		secondActPokemon = currentPlayerPokemon;

		firstActMove = enemyMove;
		secondActMove = playerMove;
	}

	// ============================= DAMAGE CALCULATION =============================
	handleAttack(firstActPokemon, firstActMove, secondActPokemon);

	if (currentPlayerPokemon.getHp() > 0) {
		handleSwap(iFile);
	}

	if (isTurnFinished) {
		return;
	}

	handleAttack(secondActPokemon, secondActMove, firstActPokemon);

	if (currentPlayerPokemon.getHp() > 0) {
		handleSwap(iFile);
	}

	isTurnFinished = true;
}

void handleBag(std::ifstream& iFile) {

}

void handleSwap(std::ifstream& iFile) {
	std::cout << "Select the next pokemon: " << std::endl;

	std::vector<Pokemon> activePokemon;

	for (auto& pokemon : trainerList[0].getPokemon()) {
		std::cout << pokemon.getName();

		if (pokemon.getHp() > 0) {
			std::cout << " [ACTIVE]" << std::endl;
			activePokemon.push_back(pokemon);
		}
		else {

			std::cout << " [FAINTED]" << std::endl;
		}
	}

	std::string switchedPokemon = "";

	iFile >> switchedPokemon;

	bool newPokemonFound = false;

	for (auto& pokemon : trainerList[0].getPokemon()) {
		if (pokemon.getName() == switchedPokemon) {
			newPokemonFound = true;
			currentPlayerPokemon = pokemon;
			std::cout << "Go, " << switchedPokemon << "!" << std::endl;
			break;
		}
	}

	if (!newPokemonFound) {
		std::cout << switchedPokemon << " is not available on trainer's party. Ending battle..." << std::endl;
		isErrorCommand = true;
	}
}

void printStatus(std::ifstream& iFile) {

}

void printCheck(std::ifstream& iFile) {

}

void updateNewestPokemon() {
	//
	std::vector<Pokemon> playerPokemonList = trainerList[0].getPokemon();
	currentPlayerPokemon = playerPokemonList[0];

	//
	std::vector<Pokemon> enemyPokemonList = trainerList[1].getPokemon();
	currentEnemyPokemon = enemyPokemonList[0];
}

double getDamageCalculation(Pokemon attacker, Move usedMove, Pokemon defender) {
	// ============================= TYPE EFFECTIVENESS AND STAB =============================
	//
	double damageMultiplier = 1.0;
	double STABValue = 1.0;

	//
	int attackingElementIndex = getElementTypingIndex(usedMove.getType());

	//
	std::vector<std::string> defenderElements = defender.getType();
	std::vector<std::string> attackerElements = attacker.getType();

	//
	for (const auto& defenderElement : defenderElements) {
		int defenderElementIndex = getElementTypingIndex(defenderElement);

		double effectiveness = effectivenessChart[attackingElementIndex][defenderElementIndex];

		damageMultiplier *= effectiveness;
	}

	//
	for (const auto& attackerElement : attackerElements) {
		if (usedMove.getType() == attackerElement) {
			STABValue = 1.5;
			break;
		}
	}


	// ============================= DAMAGE CALCULATION =============================
	double damageValue = 0;
	int attackPower = usedMove.getPower();
	double attackValue = 0;
	double defenseValue = 0;
	double criticalValue = 1.0;
	
	if (usedMove.getAttackType() == "Physical") {
		attackValue = attacker.getAttack();
		defenseValue = defender.getDefense();
	}
	else {
		attackValue = attacker.getSpAttack();
		defenseValue = defender.getSpDefense();
	}

	damageValue = ((((2 * 50) + 10) / 250) * attackPower * (attackValue / defenseValue) + 2) * criticalValue * STABValue * damageMultiplier;

	if (damageMultiplier > 1.0) {
		std::cout << "It's super effective!" << std::endl;
	}
	else if (damageMultiplier < 1.0) {
		std::cout << "It's not very effective..." << std::endl;
	}

	return damageValue;
}

int getElementTypingIndex(std::string type) {
	int index = 0;

	if (type == "Normal") {
		index = 0;
	}
	else if (type == "Fire") {
		index = 1;
	}
	else if (type == "Water") {
		index = 2;
	}
	else if (type == "Electric") {
		index = 3;
	}
	else if (type == "Grass") {
		index = 4;
	}
	else if (type == "Ice") {
		index = 5;
	}
	else if (type == "Fighting") {
		index = 6;
	}
	else if (type == "Poison") {
		index = 7;
	}
	else if (type == "Ground") {
		index = 8;
	}
	else if (type == "Flying") {
		index = 9;
	}
	else if (type == "Psychic") {
		index = 10;
	}
	else if (type == "Bug") {
		index = 11;
	}
	else if (type == "Rock") {
		index = 12;
	}
	else if (type == "Ghost") {
		index = 13;
	}
	else if (type == "Dragon") {
		index = 14;
	}
	else if (type == "Dark") {
		index = 15;
	}
	else if (type == "Steel") {
		index = 16;
	}
	else if (type == "Fairy") {
		index = 17;
	}

	return index;
}

void handleAttack(Pokemon attacker, Move usedMove, Pokemon defender) {
	double damage = 0;
	int moveAccuracy = usedMove.getAccuracy();

	if (isTestMode) {
		moveAccuracy = 100;
	}

	if (1 + (rand() % 100) <= moveAccuracy) {
		damage = getDamageCalculation(attacker, usedMove, defender);
		std::cout << attacker.getName() << " dealt " << damage << " to " << defender.getName() << std::endl;

		int newHealth = defender.getHp() - damage;

		if (newHealth <= 0) {
			defender.setHp(0);
			handleFainted(defender);
		}
		else {
			defender.setHp(newHealth);
		}
	}
	else {
		std::cout << attacker.getName() << "'s move is missed!" << std::endl;
	}
}

void handleFainted(Pokemon pokemon) {
	// Print message
	std::string msg = "";

	if (!isPlayerTurn) {
		msg = "The opposing ";
	}

	std::cout << msg << pokemon.getName() << " is fainted!" << std::endl;

	isTurnFinished = true;

	if (checkGameEnded()) {
		return;
	}

	// Switch next pokemon (for enemy)
	if (!isPlayerTurn) {
		for (auto& pokemon : trainerList[1].getPokemon()) {
			if (pokemon.getHp() > 0) {
				currentEnemyPokemon = pokemon;
				std::cout << "Enemy sends out " << pokemon.getName() << "!" << std::endl;
				break;
			}
		}
	}
}

bool checkGameEnded() {
	bool isAllFainted = true;

	for (auto& pokemon : trainerList[0].getPokemon()) {
		if (pokemon.getHp() > 0) {
			isAllFainted = false;
			break;
		}
	}

	if (isAllFainted) {
		isGameOver = true;
		isPlayerWin = false;
		return true;
	}

	isAllFainted = true;

	for (auto& pokemon : trainerList[1].getPokemon()) {
		if (pokemon.getHp() > 0) {
			isAllFainted = false;
			break;
		}
	}

	if (isAllFainted) {
		isGameOver = true;
		isPlayerWin = true;
		return true;
	}

	return false;
}