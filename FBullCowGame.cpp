#pragma once
#include "FBullCowGame.h"
#include <map>

//To make syntax Unreal Friendly
#define TMap std ::map 
using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame()
{
	reset();

}
int32 FBullCowGame::Getmaxtries()const

{
	TMap <int32, int32> WordLengthToMaxtries{ {3, 4}, {4,6},{5,8},{6,10} };
	return WordLengthToMaxtries[MyHiddenWord.length()];
}

void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	
	MycurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;

}

int32 FBullCowGame::GetCurrentTry() const
{
	return MycurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}


bool  FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EWordStatus FBullCowGame::CheckValidityofGuess(FString Guess) const
{
	
		if (!ISIsogram(Guess)) //if the word isn't an isogram
	{
		return EWordStatus::Not_Isogram; 

	}
	else if (!IsLowerCase(Guess)) //if the guess isn't all lower case
		{
		return EWordStatus::Not_lowercase; 

	}
	else if (Guess.length() != GetHiddenWordLength()) //if guess length is wrong
	{
		return EWordStatus::Wrong_Length;
	}
	else //otherwise 
		return EWordStatus::OK;
}
// receives a valid guess, increments turn number and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MycurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();
	bool bIsGameWon = IsGameWon();
	//loop through all letters in the hidden word
	for (int32  MHWCAHR = 0; MHWCAHR < WordLength; MHWCAHR++)
	{
		//comapre letters against the guess word
		for (int32 GCHAR = 0; GCHAR < WordLength; GCHAR++)
		{	//if they match
			if (Guess [GCHAR] == MyHiddenWord [MHWCAHR])
			{
				//if they are in the same place
				if (MHWCAHR == GCHAR)
				{	//increment bulls
					BullCowCount.Bulls++;
				}
				else
					//increment cows
					BullCowCount.Cows++;
			
			}
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
		}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::ISIsogram(FString Word)const
{
	//treat 0 and 1 letters words as isograms
	if (Word.length() <= 1)
	{
		return true;
	}
	TMap<char, bool>LetterSeen; //set up map
	//loop through all letters of the word
	for (auto Letter : Word)
	{
	Letter = tolower(Letter); //handle mixed case
		//if the letter is in the map
		if (LetterSeen[Letter]) //we do not have an isogram
		{
			return false;
		}
		else //otherwise
		{
			LetterSeen[Letter] = true;
		}
		//add the letter to the map as seen

	}
	return true; //for example in cases where 0 is entered
}

bool FBullCowGame::IsLowerCase(FString Word) const
{

	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
		else {
			return true;
		}
	}

}



	



