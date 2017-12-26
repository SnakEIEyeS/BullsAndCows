#include <iostream>

int main()
{
	constexpr int WORD_LENGTH = 8;

	std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";

	return 0;
}