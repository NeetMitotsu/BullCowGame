#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void PrintInfo();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();


// the entry point for our application
int main() {
	
	PrintInfo();

	do {
		PlayGame();
	} while (AskToPlayAgain());

	//	 cout << AskToPlayAgain();

	// repeat the guess back to them 

	return 0;
}

void PlayGame() {
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		string Guess = GetGuess();
		// print the guess back
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}


// introduce the game
void PrintInfo() {
	constexpr int WORLD_LENGTH = 5;
	cout << "Welcome tom Bulls and Cows, a fun word game" << endl;
	cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of? \n";
	cout << endl;
}

// get a guess from the player
string GetGuess() {
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	
	cout << "Do you want to play a game?";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

