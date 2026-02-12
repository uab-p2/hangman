#pragma once
#include <string>

/// Play a round of hangman
void playGame();

/// @return the next secret word for the game
std::string getNextWord();

/// @return the next letter choice by the player
std::string getNextLetter();

/// @return whether the letter is good or bad
bool isLetterGood(std::string letter, std::string secretWord);

/// Show the known/unknown positions
void displayPositions(std::string secretWord, bool knownPositions[]);

/// Show remaining lives
void displayLives(int remainingLives);

/// @return whether the end of the game has been reached
bool isGameOver(std::string secretWord, bool knownPositions[], bool remainingLives);

/// @return whether the game was won or not
bool isGameWon(std::string secretWord, bool knownPositions[]);

/// Inform the player whether the game was won or not
void displayFinalMessage(std::string secretWord, bool knownPositions[]);
