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
#include <cmath>
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

int turnCounter = 1;
bool isTestMode = false;
bool isGameOver = false;
bool isPlayerWin = false;
bool isErrorCommand = false;
bool isPlayerTurn = true;
bool isTurnFinished = false;
std::vector <Pokemon> pokedex;	// Vector to store all the pokemon from the library file
std::vector <Move> moveCodex;	// Move index to store all kind of moves
std::vector <Trainer> trainerList;

std::vector<Pokemon> playerPokemonList;
std::vector<Pokemon> enemyPokemonList;

Pokemon dummyPokemon1;
Pokemon dummyPokemon2;
Pokemon* currentPlayerPokemon;
Pokemon* currentEnemyPokemon;

void handleBattle(std::ifstream& iFile, bool isSingleEnemyAttack);
void handleBag(std::ifstream& iFile);
void handleSwap(std::ifstream& iFile, bool isSwapCommand);
void printStatus();
void printCheck();
void handleAttack(Pokemon& attacker, Move& usedMove, Pokemon& defender);
void checkHandlePlayerFainted(std::ifstream& iFile);
void checkHandleEnemyFainted();
double getDamageCalculation(Pokemon& attacker, Move& usedMove, Pokemon& defender);
int getElementTypingIndex(std::string type);
bool checkGameEnded();
bool checkHandleMoveValid(std::string moveCommand, Move& attackingMove, bool isFindingPlayerMove);
void checkHandleConditional(std::ifstream& iFile);
bool checkHandleParalyzed(Pokemon attacker);
std::string handleStringSpaces(std::string& str);

int main()
{
	std::srand(time(0));

	for (int i = 0; i < 2; i++)
	{
		trainerList.push_back(Trainer());
	}

	std::ifstream iFile;

	std::string testFile;
	std::cout << "Input case file: ";
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
					pokemonNotes.push_back(pokedex[j]);
					pokemonNotes[pokemonNotes.size() - 1].setMoves(move);
					break;
				}
			}
		}
		trainerList[index].setPokemon(pokemonNotes);
		index++;
	}

	iFile.close();

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
		// std::cout << "Test Mode in On" << std::endl;
		isTestMode = true;
	}

	//
	playerPokemonList = trainerList[0].getPokemon();
	currentPlayerPokemon = &playerPokemonList[0];
	enemyPokemonList = trainerList[1].getPokemon();
	currentEnemyPokemon = &enemyPokemonList[0];

	for (auto& trainer : trainerList) {
		std::vector<Item> itemList;

		itemList.push_back(Item("Potion", 20, "HP"));
		itemList.push_back(Item("SuperPotion", 60, "HP"));
		itemList.push_back(Item("HyperPotion", 120, "HP"));
		itemList.push_back(Item("MaxPotion", -1, "HP"));

		trainer.setItem(itemList);
	}

	//
	while (!isGameOver && !iFile.eof() && !isErrorCommand) {
		// std::cout << "\n\nTurn " << turnCounter << std::endl;

		//
		iFile >> command;

		// std::cout << "--- Reading command: " << command << std::endl;
		// std::cout << "--- Current Pokemon: " << std::endl;
		// printStatus();
		// printCheck();
		// std::cout << "======================" << std::endl;

		//
		isTurnFinished = false;

		//
		if (command == "Battle") {
			handleBattle(iFile, false);
			turnCounter++;
		}
		else if (command == "Bag") {
			handleBag(iFile);
			turnCounter++;
		}
		else if (command == "Pokemon") {
			handleSwap(iFile, true);
			turnCounter++;
		}
		else if (command == "Status") {
			printStatus();
		}
		else if (command == "Check") {
			printCheck();
		}
		else if (command == "Exit") {
			isGameOver = true;
		}
		else {
			std::cout << "Invalid command!" << std::endl;
		}

	}

	//
	// std::cout << "End of the game. Thank you for playing!" << std::endl;
}

bool checkHandleMoveValid(std::string moveCommand, Move& attackingMove, bool isFindingPlayerMove) {
	bool isMoveUsageValid = false;
	bool isMoveHavePP = true;
	std::string status = "";
	std::vector<Move> dummyMoves;
	std::vector<Move>& currentPokemonMoves = dummyMoves;

	if (isFindingPlayerMove) {
		status = "player " + currentPlayerPokemon->getName();
		currentPokemonMoves = currentPlayerPokemon->getMoves();
	}
	else {
		status = "opponent " + currentEnemyPokemon->getName();
		currentPokemonMoves = currentEnemyPokemon->getMoves();
	}

	for (Move& move : currentPokemonMoves) {
		// std::cout << status << " have " << move.getName() << std::endl;

		if (move.getName() == moveCommand) {
			isMoveUsageValid = true;
			attackingMove = move;

			if (move.getPowerPoint() <= 0) {
				isMoveHavePP = false;
			}

			break;
		}
	}

	if (!isMoveUsageValid) {
		std::cout << moveCommand << " is not found on " << status << " " << currentPlayerPokemon->getName() << "'s move list. Ending battle..." << std::endl;
		isErrorCommand = true;
		return false;
	}
	else if (!isMoveHavePP) {
		std::cout << moveCommand << " of " << status << currentPlayerPokemon->getName() << " does not have enough PP. Ending battle..." << std::endl;
		isErrorCommand = true;
		return false;
	}

	return true;
}

void handleBattle(std::ifstream& iFile, bool isSingleEnemyAttack) {
	std::string moveCommand;
	Move dummyMove1;
	Move dummyMove2;
	Move* playerMove = nullptr;
	Move* enemyMove = nullptr;

	if (!isSingleEnemyAttack) {
		iFile >> moveCommand;
		if (checkHandleMoveValid(moveCommand, dummyMove1, true)) {
			// playerMove = &dummyMove1;
			for (auto& move : currentPlayerPokemon->getMoves()) {
				if (moveCommand == move.getName()) {
					playerMove = &move;
					break;
				}
			}
		}
		else {
			return;
		}
	}

	iFile >> moveCommand;
	if (checkHandleMoveValid(moveCommand, dummyMove2, false)) {
		// enemyMove = &dummyMove2;
		for (auto& move : currentEnemyPokemon->getMoves()) {
			if (moveCommand == move.getName()) {
				enemyMove = &move;
				break;
			}
		}
	}
	else {
		return;
	}



	// ============================= JUDGE POKEMON SPEED =============================
	Pokemon* firstActPokemon = nullptr;
	Pokemon* secondActPokemon = nullptr;

	Move* firstActMove = nullptr;
	Move* secondActMove = nullptr;

	isPlayerTurn = false;

	int playerPokemonSpeed = currentPlayerPokemon->getSpeed();
	int enemyPokemonSpeed = currentEnemyPokemon->getSpeed();

	for (auto status : currentPlayerPokemon->getStatus()) {
		if (status == "PAR") {
			playerPokemonSpeed /= 2;
			break;
		}
	}

	for (auto status : currentEnemyPokemon->getStatus()) {
		if (status == "PAR") {
			enemyPokemonSpeed /= 2;
		}
	}

	if (!isSingleEnemyAttack && playerPokemonSpeed >= enemyPokemonSpeed) {
		firstActPokemon = currentPlayerPokemon;
		secondActPokemon = currentEnemyPokemon;
		firstActMove = playerMove;
		secondActMove = enemyMove;
		isPlayerTurn = true;
	}
	else {
		firstActPokemon = currentEnemyPokemon;
		secondActPokemon = currentPlayerPokemon;
		firstActMove = enemyMove;
		secondActMove = playerMove;
	}

	// ============================= DAMAGE CALCULATION =============================
	if (!checkHandleParalyzed(*firstActPokemon)) {
		handleAttack(*firstActPokemon, *firstActMove, *secondActPokemon);

		if (isPlayerTurn) {
			checkHandleEnemyFainted();
		}
		else {
			checkHandlePlayerFainted(iFile);
		}
	}

	isPlayerTurn = !isPlayerTurn;

	if (isSingleEnemyAttack || isTurnFinished) {
		if (!isGameOver) {
			checkHandleConditional(iFile);
		}


		isTurnFinished = true;

		return;
	}

	if (!checkHandleParalyzed(*secondActPokemon) && !isTurnFinished) {
		handleAttack(*secondActPokemon, *secondActMove, *firstActPokemon);

		if (isPlayerTurn) {
			checkHandleEnemyFainted();
		}
		else {
			checkHandlePlayerFainted(iFile);
		}

		checkHandleConditional(iFile);
	}

	isTurnFinished = true;
}

void handleSwap(std::ifstream& iFile, bool isSwapCommand) {
	// std::cout << "Select the next pokemon: " << std::endl;

	std::vector<Pokemon> activePokemon;

	for (auto& pokemon : playerPokemonList) {
		// std::cout << pokemon.getName();

		if (pokemon.getHp() > 0) {
			// std::cout << " [ACTIVE] HP: " << pokemon.getHp() << std::endl;
			activePokemon.push_back(pokemon);
		}
		else {
			// std::cout << " [FAINTED] HP: " << pokemon.getHp() << std::endl;
		}
	}

	std::string switchedPokemon = "";

	iFile >> switchedPokemon;

	bool newPokemonFound = false;

	for (auto& pokemon : playerPokemonList) {
		if (pokemon.getName() == switchedPokemon) {
			newPokemonFound = true;

			if (isSwapCommand) {
				std::cout << "[Turn " << turnCounter << "] " << currentPlayerPokemon->getName() << ", switch out!" <<std::endl;
				std::cout << "[Turn " << turnCounter << "] " << "Come back!" << std::endl;
			}

			currentPlayerPokemon = &pokemon;

			std::cout << "[Turn " << turnCounter << "] " << "Go! " << switchedPokemon << "!" << std::endl;
			isTurnFinished = true;
			break;
		}
	}

	if (!newPokemonFound) {
		std::cout << switchedPokemon << " is not available on trainer's party. Ending battle..." << std::endl;
		isErrorCommand = true;
	}

	if (isSwapCommand) {
		handleBattle(iFile, true);
	}
}

void handleBag(std::ifstream& iFile) {
	// std::cout << "Select the items: " << std::endl;

	std::vector<Item> availableItems;

	for (auto& item : trainerList[0].getItem()) {
		// std::cout << "   " << item.getName();

		if (!isTestMode) {
			if (!item.getIsUsed()) {
				// std::cout << " [AVAILABLE]" << std::endl;
				availableItems.push_back(item);
			}
			else {
				// std::cout << " [USED]" << std::endl;
			}
		}
		else {
			// std::cout << " [AVAILABLE]" << std::endl;
			availableItems.push_back(item);
		}

	}

	std::string selectedItemName = "";

	iFile >> selectedItemName;

	Item dummyItem;
	Item& selectedItem = dummyItem;

	bool selectedItemNameFound = false;

	for (auto& item : trainerList[0].getItem()) {
		if (item.getName() == selectedItemName) {
			selectedItemNameFound = true;
			selectedItem = item;

			std::string itemName = item.getName();
			selectedItemName = handleStringSpaces(itemName);
			break;
		}
	}

	if (!selectedItemNameFound) {
		std::cout << selectedItemName << " is not available on trainer's bag. Ending battle..." << std::endl;
		isErrorCommand = true;
	}
	else {
		/*
		std::cout << "Please select pokemon target: " << std::endl;


		for (auto& pokemon : playerPokemonList) {
			std::cout << pokemon.getName();

			if (pokemon.getHp() > 0) {
				std::cout << " [ACTIVE] HP: " << pokemon.getHp() << std::endl;
			}
			else {

				std::cout << " [FAINTED] HP: " << pokemon.getHp() << std::endl;
			}
		}
		*/
	}

	std::string selectedPokemon = "";
	bool isPokemonFound = false;

	iFile >> selectedPokemon;

	


	for (auto& pokemon : playerPokemonList) {
		if (pokemon.getName() != selectedPokemon) {
			continue;
		}

		isPokemonFound = true;

		if (selectedItem.getBoostType() == "HP" && pokemon.getHp() > 0) {
			int newHp = pokemon.getHp() + selectedItem.getBoost();

			if (selectedItem.getBoost() < 0 || newHp > pokemon.getMaxHp()) {
				newHp = pokemon.getMaxHp();
			}

			pokemon.setHp(newHp);

			std::cout << "[Turn " << turnCounter << "] " << "You used a " << selectedItemName << "!" << std::endl;
			std::cout << "[Turn " << turnCounter << "] " << selectedPokemon << " had its HP restored." << std::endl;
		}
		// add others item boost later
	}

	if (!isPokemonFound) {
		std::cout << selectedPokemon << " is not available on trainer's party. Ending battle..." << std::endl;
		isErrorCommand = true;
	}

	handleBattle(iFile, true);
}

void printStatus() {
	std::cout << "[Turn " << turnCounter << "] " << currentPlayerPokemon->getName() << " " << currentPlayerPokemon->getHp() << " ";

	for (auto status : currentPlayerPokemon->getStatus()) {
		if (status != "NONE") {
			std::cout << status << " ";
		}
	}

	std::cout << currentEnemyPokemon->getName() << " " << currentEnemyPokemon->getHp() << " ";


	for (auto status : currentEnemyPokemon->getStatus()) {
		if (status != "NONE") {
			std::cout << status << " ";
		}
	}

	std::cout << std::endl;
}

void printCheck() {
	std::cout << "[Turn " << turnCounter << "] ";

	for (auto& move : currentPlayerPokemon->getMoves()) {
		std::cout << move.getName() << " " << move.getPowerPoint() << " ";
	}

	std::cout << std::endl;
}

double getDamageCalculation(Pokemon& attacker, Move& usedMove, Pokemon& defender) {
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

	if (attackPower > 0) {
		if (damageMultiplier > 1.0) {
			std::cout << "[Turn " << turnCounter << "] " << "It's super effective!" << std::endl;
		}
		else if (damageMultiplier < 1.0) {
			std::cout << "[Turn " << turnCounter << "] " << "It's not very effective..." << std::endl;
		}
	}



	std::string effect = usedMove.getEffect();

	if (effect != "NONE") {
		bool isSameEffect = false;

		for (auto& status : defender.getStatus()) {
			if (status == effect) {
				isSameEffect = true;
				break;
			}
		}

		if (!isSameEffect) {
			std::vector<std::string> currentStatus = defender.getStatus();
			currentStatus.push_back(effect);

			defender.setStatus(currentStatus);
		}

		std::string turn = "";
		std::string status = "";

		if (isPlayerTurn) {
			turn = "The opposing ";
		}

		if (effect == "PAR") {
			status = " is paralyzed, so it may be unable to move!";
		}
		else if (effect == "BRN") {
			status = " was burned!";
		}
		else if (effect == "PSN") {
			status = " was poisoned!";
		}

		std::cout << "[Turn " << turnCounter << "] " << turn << defender.getName() << status << std::endl;
	}

	if (usedMove.getAttackType() == "Physical") {
		attackValue = attacker.getAttack();
		defenseValue = defender.getDefense();
	}
	else if (usedMove.getAttackType() == "Special") {
		attackValue = attacker.getSpAttack();
		defenseValue = defender.getSpDefense();
	}
	else {
		usedMove.setPowerPoint(usedMove.getPowerPoint() - 1);
		return -1.0;
	}

	double step1 = (2.0 * 50.0) + 10.0;
	double step2 = step1 / 250.0;
	double step3 = step2 * attackPower;
	double step4 = step3 * (attackValue / defenseValue);
	double step5 = step4 + 2.0;
	double step6 = step5 * criticalValue;
	double step7 = step6 * STABValue;
	damageValue = step7 * damageMultiplier;

	/*
	std::cout << "Step 1: " << step1 << std::endl;
	std::cout << "Step 2: " << step2 << std::endl;
	std::cout << "Step 3: " << step3 << std::endl;
	std::cout << "Step 4: " << step4 << std::endl;
	std::cout << "Step 5: " << step5 << std::endl;
	std::cout << "Step 6: " << step6 << std::endl;
	std::cout << "Step 7: " << step7 << std::endl;
	*/

	// std::cout << "Final Damage Value: " << damageValue << std::endl;

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

std::string handleStringSpaces(std::string& str) {
	std::string result;
	result += str[0];  // Keep the first letter as is
	for (size_t i = 1; i < str.length(); ++i) {
		if (isupper(str[i])) {
			result += ' ';  // Insert a space before the capital letter
		}
		result += str[i];
	}
	return result;
}

void handleAttack(Pokemon& attacker, Move& usedMove, Pokemon& defender) {
	int damage = 0;
	int moveAccuracy = usedMove.getAccuracy();

	if (isTestMode) {
		moveAccuracy = 100;
	}

	std::string attackerStatus = "";
	std::string defenderStatus = "opponent ";

	if (!isPlayerTurn) {
		attackerStatus = "The opposing ";
		defenderStatus = "";
	}

	if (1 + (rand() % 100) <= moveAccuracy) {
		std::cout << "[Turn " << turnCounter << "] " << attackerStatus << attacker.getName() << " used " << usedMove.getName() << "!" << std::endl;
		damage = std::round(getDamageCalculation(attacker, usedMove, defender));

		if (damage < 0) {
			return;
		}

		usedMove.setPowerPoint(usedMove.getPowerPoint() - 1);

		// std::cout << "\t" << attackerStatus << attacker.getName() << " dealt " << damage << " damage to " << defenderStatus << defender.getName() << std::endl;

		int newHealth = defender.getHp() - damage;

		if (newHealth <= 0) {
			defender.setHp(0);
		}
		else {
			defender.setHp(newHealth);
		}
	}
	else {
		std::cout << "[Turn " << turnCounter << "] " << attackerStatus << attacker.getName() << "'s move is missed!" << std::endl;
	}
}

void checkHandlePlayerFainted(std::ifstream& iFile) {
	if (currentPlayerPokemon->getHp() > 0) {
		return;
	}

	std::cout << "[Turn " << turnCounter << "] " << currentPlayerPokemon->getName() << " fainted!" << std::endl;

	if (checkGameEnded()) {
		return;
	}

	handleSwap(iFile, false);
}

void checkHandleEnemyFainted() {
	if (currentEnemyPokemon->getHp() > 0) {
		return;
	}

	std::cout << "[Turn " << turnCounter << "] " << "The opposing " << currentEnemyPokemon->getName() << " fainted!" << std::endl;

	if (checkGameEnded()) {
		return;
	}

	/*
	for (auto& pokemon : enemyPokemonList) {
		std::cout << "Enemy's pokemon: " << pokemon.getName() << " with HP " << pokemon.getHp() << std::endl;
	}
	*/

	for (auto& pokemon : enemyPokemonList) {

		if (pokemon.getHp() > 0) {
			currentEnemyPokemon = &pokemon;
			// std::cout << "[Turn " << turnCounter << "] " << "Enemy sends out " << pokemon.getName() << "!" << std::endl;
			isTurnFinished = true;
			break;
		}
	}
}

bool checkGameEnded() {
	bool isAllFainted = true;

	for (auto& pokemon : playerPokemonList) {
		if (pokemon.getHp() > 0) {
			isAllFainted = false;
			break;
		}
	}

	if (isAllFainted) {
		isGameOver = true;
		isPlayerWin = false;
		isTurnFinished = true;
		std::cout << "[Turn " << turnCounter << "] " << "You lose" << std::endl;
		return true;
	}

	isAllFainted = true;

	for (auto& pokemon : enemyPokemonList) {
		if (pokemon.getHp() > 0) {
			isAllFainted = false;
			break;
		}
	}

	if (isAllFainted) {
		isGameOver = true;
		isPlayerWin = true;
		isTurnFinished = true;
		std::cout << "[Turn " << turnCounter << "] " << "You win" << std::endl;
		return true;
	}

	return false;
}

void checkHandleConditional(std::ifstream& iFile) {

	for (auto conditional : currentPlayerPokemon->getStatus()) {
		if (conditional == "PSN" || conditional == "BRN") {
			int damage = std::round((double)(0.0625 * currentPlayerPokemon->getMaxHp()));

			if (conditional == "PSN") {
				std::cout << "[Turn " << turnCounter << "] " << currentPlayerPokemon->getName() << " is hurt by its poisoning!" << std::endl;
			}
			else if (conditional == "BRN") {
				std::cout << "[Turn " << turnCounter << "] " << currentPlayerPokemon->getName() << " is hurt by its burn!" << std::endl;
			}

			currentPlayerPokemon->setHp(currentPlayerPokemon->getHp() - damage);

			checkHandlePlayerFainted(iFile);
		}
	}

	for (auto conditional : currentEnemyPokemon->getStatus()) {
		if (conditional == "PSN" || conditional == "BRN") {
			int damage = std::round((double)(0.0625 * currentEnemyPokemon->getMaxHp()));

			if (conditional == "PSN") {
				std::cout << "[Turn " << turnCounter << "] " << "The opposing " << currentEnemyPokemon->getName() << " is hurt by its poisoning!" << std::endl;
			}
			else if (conditional == "BRN") {
				std::cout << "[Turn " << turnCounter << "] " << "The opposing " << currentEnemyPokemon->getName() << " is hurt by its burn!" << std::endl;
			}

			currentEnemyPokemon->setHp(currentEnemyPokemon->getHp() - damage);

			checkHandleEnemyFainted();
		}
	}
}

bool checkHandleParalyzed(Pokemon attacker) {
	for (auto conditional : attacker.getStatus()) {
		if (conditional == "PAR") {
			std::string turn = "";

			if (!isPlayerTurn) turn = "Opposing ";

			std::cout << "[Turn " << turnCounter << "] " << turn << attacker.getName() << " is paralyzed!" << std::endl;

			int rate = 25;

			if (isTestMode) {
				rate = 100;
			}

			if ((1 + rand() % 100) <= rate) {
				std::cout << "[Turn " << turnCounter << "] " << "It can't move!" << std::endl;
				return true;
			}
		}
	}

	return false;
}

