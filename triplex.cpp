#include <iostream>

#include "triplex_impl.hpp"

int wmain(int argc, wchar_t argv[])
{
    // Instantiate data classes
    std::shared_ptr<Difficulty> pDifficulty = std::make_shared<Difficulty>();
    std::shared_ptr<Clues> pClues = std::make_shared<Clues>();
    std::shared_ptr<Guesses> pGuesses = std::make_shared<Guesses>();
    
    while (true)
    {
        bool bLevelSuccess = PlayLevel(pDifficulty, pClues, pGuesses);

        // Clear error and buffer
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (bLevelSuccess)
        {
            pDifficulty->IncrementDifficulty();
        }
        else
        {
            pDifficulty->DecrementDifficulty();
        }
    }

    return 0;
}
