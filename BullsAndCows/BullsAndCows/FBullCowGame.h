#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	//void SetMaxTries();
	//void SetCurrentTry();
	//void PickIsogram();
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value
	bool CheckGuessValidity(FString Guess); //TODO make a more rich return value
	//provide a function for counting bulls and cows and increasing try # accordingly

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
};