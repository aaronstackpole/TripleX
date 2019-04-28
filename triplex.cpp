#include <iostream>

void PrintIntroduction(int & nLevelDifficulty)
{
    std::wcout << L"You're a secret agent breaking into a level " << nLevelDifficulty << " secure server room..." << std::endl;
    std::wcout << L"You need to enter the correct codes to continue..." << std::endl;
    std::wcout << std::endl;
}

void PrintCluesAndPrompt(const int & CodeProduct, const int & CodeSum)
{
    std::wcout << L"\tThere are 3 numbers in the code" << std::endl;
    std::wcout << L"\tThe product of the numbers is " << CodeProduct << std::endl;
    std::wcout << L"\tThe sum of the numbers is " << CodeSum << std::endl;
    std::wcout << std::endl;
    std::wcout << L"Enter your three guesses (separated by spaces, i.e. 1 2 3): ";
}

void PrintGuessDebug(int & GuessA, int & GuessB, int & GuessC, int & GuessProduct, int & GuessSum)
{
    std::wcout << L"DEBUG: You entered: " << GuessA << " " << GuessB << " " << GuessC << std::endl;
    std::wcout << L"DEBUG: Your guess product is: " << GuessProduct << std::endl;
    std::wcout << L"DEBUG: Your guess sum is: " << GuessSum << std::endl;
}

bool PlayGame(int & nLevelDifficulty)
{
    PrintIntroduction(nLevelDifficulty);

    // Declare three read-only values for the "secret code"
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    // Calculate the sum and product for the "secret code" clues
    const int CodeProduct = CodeA * CodeB * CodeC;
    const int CodeSum = CodeA + CodeB + CodeC;

    // Print welcome messages to the terminal
    PrintCluesAndPrompt(CodeProduct, CodeSum);

    // Declare variables and capture user input
    int GuessA, GuessB, GuessC;
    std::wcin >> GuessA >> GuessB >> GuessC;

    // Perform result calculations
    int GuessProduct = GuessA * GuessB * GuessC;
    int GuessSum = GuessA + GuessB + GuessC;

    // Output some debug messages about the captured input and calculations
    PrintGuessDebug(GuessA, GuessB, GuessC, GuessProduct, GuessSum);

    // Test if guess calculations are the same as code calculations
    if (GuessProduct == CodeProduct && GuessSum == CodeSum)
    {
        std::wcout << L"You guessed correctly!" << std::endl;
        return true;
    }
    else
    {
        std::wcout << L"These are the wrong numbers! :(" << std::endl;
        return false;
    }    
}

int wmain(int argc, wchar_t argv[])
{
    int nLevelDifficulty = 1;
    
    while (true)
    {
        bool bLevelComplete = PlayGame(nLevelDifficulty);

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (bLevelComplete)
        {
            nLevelDifficulty++;
        }
    }

    return 0;
}
