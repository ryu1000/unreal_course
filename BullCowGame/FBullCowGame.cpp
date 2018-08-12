#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameWon; }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 3;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameWon = false;
	return;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	// Not isogram
	if (!IsIsogram(Guess)) {
		return EWordStatus::Not_Isogram;
	}
	// Not lowercase
	else if (!IsLowerCase(Guess)) {
		return EWordStatus::Not_Lowercase;
	}
	// Size mismatch
	else if (Guess.length() != GetHiddenWordLength()) {
		return EWordStatus::Wrong_Length;
	}
	// Alles gut!
	else {
		return EWordStatus::OK;
	}
}

bool FBullCowGame::IsIsogram(FString Guess) const {
	// Declare a map structure
	TMap <char, bool> mchar;

	// Iterate over every char of the word
	for (auto Letter : Guess) {
		Letter = tolower(Letter);
		// Check if char appears on the map
		if (mchar.count(Letter) == 0) {
			// If not, then add to the map
			mchar[Letter] = true;
		}
		else {
			// Else word is not isogram
			return false;
		}
	}

	return true;
}

bool FBullCowGame::IsLowerCase(FString Guess) const {

	// Iterate over guess
	for (auto Letter : Guess) {
		// If char is not lowercase return false
		if (!islower(Letter)) { return false; };
	}

	return true;
}

// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				}
				else {
					BullCowCount.Cows++; // must be a cow
				}
			}
		}
	}

	bGameWon = (BullCowCount.Bulls == HiddenWordLength) ? true : false;
	return BullCowCount;
}
