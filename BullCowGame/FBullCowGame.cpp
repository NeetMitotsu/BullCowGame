#include "stdafx.h"
#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "game";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}


bool FBullCowGame::IsGameWon() const {
	return false;
}




EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {

	if (false) { // if the guess isn't an isogram 
		return EGuessStatus::Not_Isogram;
//	} else if () { // if the guess isn't all lowercase 
//		return EGuessStatus::Not_Lowercase;
	} else if (Guess.length() != GetHiddenWordLength()) {// if the guess length is wrong 
		return EGuessStatus::Wrong_Length;
	} else {// otherwise 
		return EGuessStatus::OK;
	}
}



// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			// if they match then 
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // if they're in the same place
					BullCowCount.Bulls++;// incriment bulls
				}
				else {
					BullCowCount.Cows++;// must be a cow
				}
			}
		}
	}

	return BullCowCount;
}
