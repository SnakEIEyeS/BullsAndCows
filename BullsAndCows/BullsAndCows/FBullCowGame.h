/*
Contains declarations for class FBullCowGame, struct FBullCowCount, enum class EGuessStatus.
*/

#pragma once
#include <string>

//to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

//all values initialized to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Null_String
};

/* FBullCowGame class is used for instances of the game.
Handles all game related functionality.
Does not take care of the User Interface.
*/
class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString Guess) const;
	//void SetMaxTries();
	//void SetCurrentTry();
	//void PickIsogram();

	void Reset();
	FBullCowCount SubmitValidGuess(FString Guess);

private:
	//see constructor for initialisation
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString Guess) const;
	bool IsLowerCase(FString Guess) const;
};