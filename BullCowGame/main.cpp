/* This is the console executable, that makes use of the BUllCow class.
This acts as the view in a MVC pattern, and is responsible for all
user interaction. for game logic see the FBullCowGame class.
*/
#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>

#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintInfo();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();


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
	// loop asking for the number of turns asking for guesses
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess(); 
				
		//  Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	
	PrintGameSummary();

}


// introduce the game
void PrintInfo() {
	std::cout << "Welcome tom Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
}

// loop continually until the user gives a valid guess
FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	do {
		// get a guess from the player
		int CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << " . Enter your guess: ";
		std::getline(std::cin, Guess);
		// check status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping until we get valid input
	return Guess;
}

bool AskToPlayAgain() {
	
	std::cout << "Do you want to play a game?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "WELL DONE - YOU WIN!" << std::endl;
	} else {
		std::cout << "Better luck next time! \n";
	}
}

