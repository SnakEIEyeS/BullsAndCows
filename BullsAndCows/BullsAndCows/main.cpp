#include <iostream>
#include <string>

void PrintIntro();
std::string GetGuessAndPrintBack();

//The entry point for our game
int main()
{
	PrintIntro();
	
	GetGuessAndPrintBack();
	GetGuessAndPrintBack();

	return 0;
}

//Introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 8;

	std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

//Get the player's Guess
std::string GetGuessAndPrintBack()
{
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);

	//Repeat the Guess back to the player
	std::cout << "Your guess was: " << Guess << std::endl;

	return Guess;
}