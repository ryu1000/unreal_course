/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>	
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	return 0; // exit the application
}

 
// introduce the game
void PrintIntro() {
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int32 count = 1; count <= MaxTries; count++) {
		// Get user guess
		FText Guess = GetGuess();
		
		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	// TODO summarise game
}


// Stay in a loop until user enters a valid guess
FText GetGuess() {
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	EWordStatus Status = EWordStatus::Invalid;

	do {
		// get a guess from the player
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		// Take action based on status
		switch (Status) {
		case EWordStatus::Not_Isogram:
			std::cout << "Guess is not an isogram\n";
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Guess is not in lowercase\n";
			break;
		case EWordStatus::Wrong_Length:
			std::cout << "Guess is not " << BCGame.GetHiddenWordLength() << " letters long\n";
			break;
		default:
			// No error catched
			return Guess;
		}

		std::cout << std::endl;
	} while (Status != EWordStatus::OK);
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
