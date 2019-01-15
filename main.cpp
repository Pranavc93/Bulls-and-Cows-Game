/*This is the console executable, that makes use of the BullCow class.
This acts as a view in the MVC pattern, and is responsible for all user interaction. For game logic see FBullCowGame class*/

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"
//To make syntax Unreal Friendly
using FText = std::string;
using int32 = int;
//Function Prototypes as Outside of a Class
void Printintro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCgame; //Instantiating the class BCGame is an Instance of the class FBullCowGame just like FText Guess

					 //Entry point to the Bulls and Cows Game
int main()
{
	bool bPlayAgain = false;
	do 
	{
		Printintro();
		PlayGame();
		PrintGameSummary();
		bPlayAgain = AskToPlayAgain();
		
	} 
	while (bPlayAgain);
	return 0; //Exit the Application
}

//Welcome Screen
void Printintro()
	{
	std::cout << "Welcome to the Bulls and Cows Game\n\n\n";
	std::cout << " .-=-.        .-=-.                                        .=     ,        =.\n";
	std::cout << " `)  )        (  (`                                   _  _   /'/    )\,/,/(_   \ \\n";
	std::cout << ".'/  /         \\ \\`.                              `/ / -. | (, \\)\//\)\/_  ) |\n";
	std::cout << "( (  _.-'`::`-._ ) )                                 //___\   `\\\/\\/\/\\///'  /\n";
	std::cout << "\\ `'`    .::.  `'` /                              ,-'~`-._ `'- - '_   `'''`  _ \`''~-,_ \n";
	std::cout << "  `-._\\`~`   `~`/_.-'                             \\       `-.  '_`.      .'_` \ ,-'~`/\n";
	std::cout << "_,=`  /         \\ `=,_                             `.__.-'`/   (-\        /-) |-.__,'\n";
	std::cout << "(  ,(^\\         /^),   )                             ||   |     \O)  /^\ (O/  |\n";
	std::cout << "`~~` \\0)\\      /(0/ `~~`                            `\\\\  |         /   `\\    /\n";
	std::cout << "      | /`     `\\|                                     \\\\  \       /      `\\ /\n";
	std::cout << "      |          |\                                      `\\\\ `-.  /' .---.--.\\\n";
	std::cout << "      |          |\                                        `\\\\ / `~(, '()      ('\n";
	std::cout << "     //         \\\\                                         / (O) \\   _, . - ., _)\n";
	std::cout << "     \\\\()     ()//                                         //  \\\\ `\'`      /\n";
	std::cout << "       `._-==-_.'                                             / |  ||   `''''~''`\n\n";
	std::cout << "          `'''\n\n";
	
	std::cout << "                                 Bulls & Cows\n\n\n\n";
	
	
	
	std :: cout << "Can you guess the " << BCgame.GetHiddenWordLength();
	std :: cout << " letters in the isogram?\n\n";
	return;
}

//The number of turns the player takes to guess the word
void PlayGame()
{
	BCgame.reset();
	int32 maxtries = BCgame.Getmaxtries();
	//loop asking for guesses while the game is not won
	//and tries are still remaining
	while (!BCgame.IsGameWon() && BCgame.GetCurrentTry() <= maxtries)
	{
		FText Guess = GetValidGuess(); 
		
		//submit a valid guess
		FBullCowCount BullCowCount = BCgame.SubmitValidGuess(Guess);
		
		//print the number of bulls and cows
		std::cout << "Bulls" << BullCowCount.Bulls;
		std::cout << " . Cows" << BullCowCount.Cows << "\n\n";
		

	}
}


//The player takes a Guess
FText GetValidGuess()
{
	EWordStatus Status = EWordStatus::Invalid_status;
	FText Guess = "";
	do {
		int32 CurrentTry = BCgame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCgame.Getmaxtries();
		std::cout << ". Enter Your Guess\n";
		std::cout << std::endl;
		std::getline(std::cin, Guess);
		std::cout << std::endl;
		Status = BCgame.CheckValidityofGuess(Guess);
		switch (Status)
		{
		case EWordStatus::Wrong_Length: std::cout << "Please Enter a " << BCgame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EWordStatus::Not_Isogram:std::cout << "Please Enter a word without repeatting letters.\n\n";
			break;
		case EWordStatus::Not_lowercase:std::cout << "Do not enter uppercase letters.\n\n";
			break;
		default:
			break;
		}
		
	} while (Status != EWordStatus::OK);
	return Guess;
}

	 bool AskToPlayAgain()
	 {
		 std :: cout << "\nDo You Want to Play Again with the same word? (y/n)\n";
		 FText response = "";
		 std ::getline(std ::cin , response);
		 std :: cout << "Is it Y?";
		 return(response[0] == 'y' || response[0] == 'Y');
		 std :: cout << std ::endl;
		  

	 }
	 void PrintGameSummary()
	 {
		 if (BCgame.IsGameWon())
		 {
			 std::cout << "You Win!\n";
		 }
		 else {
			 std::cout << "Better Luck Next Time!\n";
		 }
	 }
	  
	 
	 
	 

	
