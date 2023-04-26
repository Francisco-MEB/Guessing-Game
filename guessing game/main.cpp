#include "Header.h"
#include <random>
#include <chrono>
#include <iostream>

int main()
{
    bool play{true};
    while (play)
    {
        int randomNumber{Random::getRandomNumber()};
        runGame(randomNumber);
        promptToPlayAgain(play);
    }
    
    std::cout << "Thank you for playing!\n";
    
    return 0;
}
