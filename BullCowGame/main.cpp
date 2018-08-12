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
void PrintEndGame();
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
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n\n";
	return;
}


void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		// Get user guess
		FText Guess = GetGuess();
		
		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintEndGame();
	return;
}

void PrintEndGame() {
	if (BCGame.IsGameWon()) {
		std::cout << "\nYou Won!!!\n";
	}
	else {
		std::cout << "\nYou lost :(\n";
	}
}

// Stay in a loop until user enters a valid guess
FText GetGuess() {
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	EWordStatus Status = EWordStatus::Invalid;

	while (Status != EWordStatus::OK) {
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
			break;
		}
		std::cout << std::endl;
	};

	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
