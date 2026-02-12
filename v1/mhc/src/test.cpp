#include "test.h"
#include <iostream>
#include <ostream>

#include "hangman.h"

void testLetterGood();

void testIsGameOver();

void runTests()
{
    testLetterGood();
}

void testLetterGood()
{
    bool testPassed = true;

    const int testWordCount = 4;
    std::string words[] = {"tomato", "carrot", "pepper", "corn"};
    for (int i = 0; i < testWordCount; i++) {
        for (unsigned int j = 0; j < words[i].size(); j++) {
            if (isLetterGood(std::string("") + words[i][j], words[i]) == false) {
                std::cout << "Problem with word " << words[i] << ", character " << words[i][j] << std::endl;
                testPassed = false;
            }
        }

        if (isLetterGood("x", words[i]) == true) {
            std::cout << "Problem with word " << words[i] << ", character x" << std::endl;
            testPassed = false;
        }
    }

    if (!testPassed) {
        std::cout << "testLetterGood failed" << std::endl;
    }
}

void testIsGameOver()
{
    bool testFailed = false;
    std::string word = "abc";
    bool knownPositions[3];
    int lives = 3;

    knownPositions[0] = false;
    knownPositions[1] = false;
    knownPositions[2] = false;
    lives = 3;
    if (isGameOver(word, knownPositions, lives)) {
        testFailed = true;
    }

    knownPositions[0] = false;
    knownPositions[1] = true;
    knownPositions[2] = false;
    lives = 3;
    if (isGameOver(word, knownPositions, lives)) {
        testFailed = true;
    }

    knownPositions[0] = false;
    knownPositions[1] = true;
    knownPositions[2] = true;
    lives = 3;
    if (isGameOver(word, knownPositions, lives)) {
        testFailed = true;
    }

    knownPositions[0] = false;
    knownPositions[1] = true;
    knownPositions[2] = true;
    lives = 1;
    if (isGameOver(word, knownPositions, lives)) {
        testFailed = true;
    }

    knownPositions[0] = false;
    knownPositions[1] = true;
    knownPositions[2] = true;
    lives = 100000;
    if (isGameOver(word, knownPositions, lives)) {
        testFailed = true;
    }

    knownPositions[0] = true;
    knownPositions[1] = true;
    knownPositions[2] = true;
    lives = 3;
    if (isGameOver(word, knownPositions, lives) == false) {
        testFailed = true;
    }

    knownPositions[0] = true;
    knownPositions[1] = false;
    knownPositions[2] = true;
    lives = 0;
    if (isGameOver(word, knownPositions, lives) == false) {
        testFailed = true;
    }

    knownPositions[0] = true;
    knownPositions[1] = false;
    knownPositions[2] = true;
    lives = -1;
    if (isGameOver(word, knownPositions, lives) == false) {
        testFailed = true;
    }

    if (testFailed) {
        std::cout << "testIsGameOver failed" << std::endl;
    }
}
