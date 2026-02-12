#include "hangman.h"
#include <iostream>

/// Play a round of hangman
void playGame()
{
    const int initialLives = 3;
    const int maxWordLength = 64;

    std::string secretWord = getNextWord();
    int livesRemaining = initialLives;
    bool knownPositions[maxWordLength];
    for (int i = 0; i < maxWordLength; i++) {
        knownPositions[i] = false;
    }

    while (!isGameOver(secretWord, knownPositions, livesRemaining)) {
        displayLives(livesRemaining);

        displayPositions(secretWord, knownPositions);

        std::string letter = getNextLetter();

        if (!isLetterGood(letter, secretWord)) {
            std::cout << "Ouch!" << std::endl;
            livesRemaining--;
        }
        else {
            std::cout << "Good!" << std::endl;
            for (unsigned int i = 0; i < secretWord.size(); i++) {
                if (secretWord[i] == letter[0]) {
                    knownPositions[i] = true;
                }
            }
        }
    }

    displayFinalMessage(secretWord, knownPositions);
}

/// @return the next secret word for the game
std::string getNextWord()
{
    return "tomato";
}

/// @return the next letter choice by the player
std::string getNextLetter()
{
    std::cout << "Type the next letter and press [enter]: ";

    std::string letter;
    bool choiceMade = false;

    while (!choiceMade) {
        std::cin >> letter;
        if (letter.size() != 1) {
            std::cout << std::endl << "Wrong choice. Please type one letter and press [enter]: ";
        }
        else {
            choiceMade = true;
        }
    }

    return letter;
}

/// @return whether the letter is good or bad
bool isLetterGood(std::string letter, std::string secretWord)
{
    bool found = false;

    for (unsigned int i = 0; i < secretWord.size() && !found; i++) {
        if (letter[0] == secretWord[i]) {
            found = true;
        }
    }

    return found;
}

/// Show the known/unknown positions
void displayPositions(std::string secretWord, bool knownPositions[])
{
    for (unsigned int i = 0; i < secretWord.size(); i++) {
        if (knownPositions[i]) {
            std::cout << secretWord[i];
        }
        else {
            std::cout << "_";
        }
        if (i == secretWord.size() - 1) {
            std::cout << std::endl;
        }
    }
}

/// Show remaining lives
void displayLives(int remainingLives)
{
    std::cout << "Lives remaining: " << remainingLives << std::endl;
}

bool isGameOver(std::string secretWord, bool knownPositions[], bool remainingLives)
{
    bool allPositionsKnown = true;
    for (unsigned int i = 0; i < secretWord.size() && allPositionsKnown; i++) {
        if (!knownPositions[i]) {
            allPositionsKnown = false;
        }
    }

    return allPositionsKnown || (remainingLives <= 0);
}

bool isGameWon(std::string secretWord, bool knownPositions[])
{
    bool gameWon = true;

    for (unsigned int i = 0; i < secretWord.size() && gameWon; i++) {
        if (!knownPositions[i]) {
            gameWon = false;
        }
    }

    return gameWon;
}

/// Inform the player whether the game was won or not
void displayFinalMessage(std::string secretWord, bool knownPositions[])
{
    if (isGameWon(secretWord, knownPositions)) {
        std::cout << "You win! The secret word was, indeed, '" << secretWord << "'." << std::endl;
    }
    else {
        std::cout << "You loose! You will never know the secret word, muhahaha!" << std::endl;
    }
}
