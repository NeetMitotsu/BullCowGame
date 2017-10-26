/* This is the console executable, that makes use of the BUllCow class.
This acts as the view in a MVC pattern, and is responsible for all
user interaction. for game logic see the FBullCowGame class.



*/
#include "stdafx.h"
#include <iostream>
#include <string>

#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintInfo();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game
// the entry point for our application
int main() {
	bool bPlayAgain = false;
	do {
		PrintInfo();
		PlayGame();
		// TODO add a game summary
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	// repeat the guess back to them 

	return 0;
}

void PlayGame() {
	BCGame.Reset();
	
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	// loop for the number of turns asking for guesses
	// TODO change from FOR	to WHILE loop once we are validating tries
	for (int count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess(); // TODO make loop checking valid 
		//  Submit valid guess to the game
		// Print number of bulls and cows
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO summarise game 
}


// introduce the game
void PrintInfo() {
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome tom Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
}

// get a guess from the player
FText GetGuess() { 
	int currentTry = BCGame.GetCurrentTry();
	std::cout << "Try "<< currentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	
	std::cout << "Do you want to play a game?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

