#include "stdafx.h"
#include <iostream>
#include <string>


void PrintInfo();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();


// the entry point for our application
int main() {
	bool isAskToPlay = false;
	do {
		PrintInfo();
		PlayGame();
		isAskToPlay = AskToPlayAgain();
	} while (isAskToPlay);

	// repeat the guess back to them 

	return 0;
}

void PlayGame() {
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		std::string Guess = GetGuess();
		// print the guess back
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}


// introduce the game
void PrintInfo() {
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Welcome tom Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
}

// get a guess from the player
std::string GetGuess() { 
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	
	std::cout << "Do you want to play a game?";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

