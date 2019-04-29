#include "triplex_impl.hpp"

using namespace TripleX;

int wmain(int argc, wchar_t argv[])
{
    // Instantiate data classes
    DifficultyPtr pDifficulty = std::make_shared<Difficulty>();
    CluesPtr pClues = std::make_shared<Clues>();
    GuessesPtr pGuesses = std::make_shared<Guesses>();
    
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
