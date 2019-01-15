/*The game logic (no view code or direct user interaction) The game is a simple guess the Word Game */


#pragma once
#include <string>
//To make syntax Unreal Friendly
using FString = std ::string;
using int32 = int;

struct FBullCowCount  {

	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	Invalid_status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_lowercase

	
};
class FBullCowGame

{
public:
	FBullCowGame(); //constructor
	void reset();// to reset the game 
	int32 Getmaxtries()const;
	int32 GetCurrentTry()const;
	int32 GetHiddenWordLength()const;
	bool IsGameWon()const;
	EWordStatus CheckValidityofGuess(FString)const; 
	//counting bulls and cows and increasing turn number
	FBullCowCount SubmitValidGuess(FString);
private:
	 int32 MycurrentTry;
	 FString  MyHiddenWord;
	 bool bGameIsWon;
	 bool ISIsogram(FString)const;
	 bool IsLowerCase(FString)const;

};

