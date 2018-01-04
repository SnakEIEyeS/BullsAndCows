/*
Contains implementations for class FBullCowGame.
*/

#pragma once

#include "FBullCowGame.h"

#include <map>

//to make syntax Unreal friendly
#define TMap std::map
using FString = std::string; 
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } //default constructor

int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const 
{	//set maximum tries according to length of hidden word
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "plane"; //this MUST be an isogram
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	bGameIsWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
	{	//if the guess is not an isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess))
	{	//if the guess is not lowercase
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{	//if the guess is the wrong length
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

//receives a VALID guess, increments try, returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assuming same length as guess

	//loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		//compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
				{	//if they're  in the same place
					BullCowCount.Bulls++; //increment Bulls
				}				
				else
				{
					BullCowCount.Cows++; //increment Cows
				}				
			}		
		}	
	}

	if (BullCowCount.Bulls == WordLength)
	{	//all letters of guess are correct and in the right place as the hidden word
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	//treat 0 and 1 letter guesses as isograms
	if(Guess.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; //setup our map
	for (auto Letter : Guess) //for all the letters in Guess
	{
		Letter = tolower(Letter); //handle mixed case

		if (LetterSeen[Letter]) //if the letter has been seen and is in the TMap
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true; //add it to the TMap as seen
		}		
	}
	
	return true; //for example in cases where \0 is entered
}

bool FBullCowGame::IsLowerCase(FString Guess) const
{
	//treat 0 letter guesses as isograms
	if (Guess.length() < 1) { return true; }

	for (auto Letter : Guess) //for all the letters in Guess
	{
		if (!isspace(Letter)) //if it is NOT a blank space
		{
			//if the letter is NOT lowercase
			if (!islower(Letter)) { return false; }	
		}
	}

	return true;
}
