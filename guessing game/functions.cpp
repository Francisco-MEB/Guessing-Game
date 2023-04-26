#include "Header.h"
#include <random>
#include <chrono>
#include <limits>
#include <iostream>

void troubleshootAndFix(int userGuess)
{
    if (std::cin.fail())
    {
        std::cout << "ERROR: input is not an integer\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if (userGuess < 1 || userGuess > 100)
    {
        std::cout << "ERROR: input must be an integer between 1 and 100\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int getUserGuess(int count)
{
    int userGuess{1}; // initialized with value 1 so initial guess doesn't get interrupted by troubleshoot function
    do
    {
        troubleshootAndFix(userGuess);
        std::cout << "Guess #" << count << ": ";
        std::cin >> userGuess;
    } while (std::cin.fail() || userGuess < 1 || userGuess > 100);
    
    return userGuess;
}

void checkAnswer(bool won, int randomNumber)
{
    if (won)
    {
        std::cout << "Correct! You win!\n";
    }
    else if (!won)
    {
        std::cout << "Sorry, you lose. The correct number was " << randomNumber << '\n';
    }
}
void runGame(int randomNumber)
{
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    
    bool won = false;
    for (int guessCount = 1; guessCount <= 7; ++guessCount)
    {
        int userGuess = getUserGuess(guessCount);
        if (userGuess == randomNumber)
        {
            won = true;
            break;
        }
        else if (userGuess < randomNumber)
        {
            std::cout << "Your guess is too low.\n";
        }
        else if (userGuess > randomNumber)
        {
            std::cout << "Your guess is too high.\n";
        }
    }
    
    checkAnswer(won, randomNumber);
}

void promptToPlayAgain(bool& play)
{
    char replay{};
    do
    {
        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> replay;
    } while (std::cin.fail() || (replay != 'y' && replay != 'n'));
    
    switch (replay)
    {
        case 'y':
            break;
        case 'n':
        default:
            play = false;
            break;
    }
}
