#include <iostream>
#include <string>

#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

//The entry point for our game
int main()
{
	bool bPlayAgain = true;
	do
	{
		PrintIntro(); 
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		std::cout << std::endl;
	} 
	while (bPlayAgain);
	
	return 0;
}

//Introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 8;

	std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	//loop for the number of tries asking for guesses
	//TODO change from FOR to WHILE loop based on number of valid tries
	for (int32 i = 0; i < MaxTries; i++)
	{
		//TODO make loop check if guess is valid
		FText Guess = GetGuess();
		//Repeat the Guess back to the player
		std::cout << "Your guess was: " << Guess << std::endl;

		//submit valid guess to the game
		//print the number of bulls and cows

		std::cout << std::endl;
	}

	//TODO summarize the game
}

//Get the player's Guess
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " <<  CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) : ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
