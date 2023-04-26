#ifndef HEADER_H
#define HEADER_H

#include <random>
#include <chrono>

namespace Random // getting random number
{
    inline std::mt19937 init()
    {
        std::random_device rd;
        
        std::seed_seq ss{static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
        
        return std::mt19937{ss};
    }

    inline std::mt19937 mt{init()};

    inline int getRandomNumber()
    {
        std::uniform_int_distribution range{1, 100};
        return range(mt);
    }
}

int getUserGuess();
void troubleshootAndFix(int userGuess);
void runGame(int randomNumber);
void checkAnswer(bool won, int randomNumber);
void promptToPlayAgain(bool& play);

#endif
