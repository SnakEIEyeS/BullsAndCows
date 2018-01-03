#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//all values initialized to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Null_String
};

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	EWordStatus CheckGuessValidity(FString Guess) const;
	//void SetMaxTries();
	//void SetCurrentTry();
	//void PickIsogram();
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value
	FBullCowCount SubmitGuess(FString Guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};