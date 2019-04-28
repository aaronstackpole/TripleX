#include <iostream>
#include <cassert>

#include "triplex_impl.hpp"

void Difficulty::SetDifficulty(int difficulty)
{
    assert(difficulty >= MIN_DIFFICULTY && difficulty <= MAX_DIFFICULTY);

    mDifficulty = difficulty;
}

void Difficulty::IncrementDifficulty()
{
    mDifficulty++;

    if (mDifficulty >= MAX_DIFFICULTY) mDifficulty = MAX_DIFFICULTY;
}

void Difficulty::DecrementDifficulty()
{
    mDifficulty--;

    if (mDifficulty <= MIN_DIFFICULTY) mDifficulty = MIN_DIFFICULTY;
}

int const & Difficulty::GetDifficulty()
{
    return mDifficulty;
}

void Clues::UpdateSum()
{
    mClueSum = mClueA + mClueB + mClueC;
}

void Clues::UpdateProduct()
{
    mClueProduct = mClueA * mClueB * mClueC;
}

void Clues::SetNumbers(int numberA, int numberB, int numberC)
{
    mClueA = numberA;
    mClueB = numberB;
    mClueC = numberC;

    Clues::UpdateSum();
    Clues::UpdateProduct();
}

int const & Clues::GetClueA()
{
    return mClueA;
}

int const & Clues::GetClueB()
{
    return mClueB;
}

int const & Clues::GetClueC()
{
    return mClueC;
}

int const & Clues::GetClueSum()
{
    return mClueSum;
}

int const & Clues::GetClueProduct()
{
    return mClueProduct;
}

void Guesses::UpdateSum()
{
    mGuessSum = mGuessA + mGuessB + mGuessC;
}

void Guesses::UpdateProduct()
{
    mGuessProduct = mGuessA * mGuessB * mGuessC;
}
void Guesses::SetNumbers(int numberA, int numberB, int numberC)
{
    mGuessA = numberA;
    mGuessB = numberB;
    mGuessC = numberC;

    Guesses::UpdateSum();
    Guesses::UpdateProduct();
}

int const & Guesses::GetGuessA()
{
    return mGuessA;
}

int const & Guesses::GetGuessB()
{
    return mGuessB;
}

int const & Guesses::GetGuessC()
{
    return mGuessC;
}

int const & Guesses::GetGuessSum()
{
    return mGuessSum;
}

int const & Guesses::GetGuessProduct()
{
    return mGuessProduct;
}

void PrintIntroduction(std::shared_ptr<Difficulty> & pDifficulty)
{
    std::wcout << L"You're a secret agent breaking into a level " << pDifficulty->GetDifficulty() << " secure server room..." << std::endl;
    std::wcout << L"You need to enter the correct codes to continue..." << std::endl;
    std::wcout << std::endl;
}

void PrintCluesAndPrompt(std::shared_ptr<Clues> & pClues)
{
    std::wcout << L"\tThere are 3 numbers in the code" << std::endl;
    std::wcout << L"\tThe product of the numbers is " << pClues->GetClueProduct() << std::endl;
    std::wcout << L"\tThe sum of the numbers is " << pClues->GetClueSum() << std::endl;
    std::wcout << std::endl;
    std::wcout << L"Enter your guesses (separated by spaces, i.e. 1 2 3): ";
}

void PrintGuessDebug(std::shared_ptr<Guesses> & pGuesses)
{
    std::wcout << L"DEBUG: You entered: " << pGuesses->GetGuessA() << " " << pGuesses->GetGuessB() << " " << pGuesses->GetGuessC() << std::endl;
    std::wcout << L"DEBUG: Your guess product is: " << pGuesses->GetGuessProduct() << std::endl;
    std::wcout << L"DEBUG: Your guess sum is: " << pGuesses->GetGuessSum() << std::endl;
}

void PrintCluesDebug(std::shared_ptr<Clues> & pClues)
{
    std::wcout << L"DEBUG: Clue codes are: " << pClues->GetClueA() << " " << pClues->GetClueB() << " " << pClues->GetClueC() << std::endl;
}

bool PlayLevel(std::shared_ptr<Difficulty> & pDifficulty, std::shared_ptr<Clues> & pClues, std::shared_ptr<Guesses> & pGuesses)
{
    PrintIntroduction(pDifficulty);

    PrintCluesDebug(pClues);

    PrintCluesAndPrompt(pClues);

    // Declare variables and capture user input
    int GuessA, GuessB, GuessC;
    std::wcin >> GuessA >> GuessB >> GuessC;

    // If failbit is set, set all the inputs to 0 before passing to SetNumbers()
    if (!std::wcin)
    {
        GuessA = GuessB = GuessC = 0;
    }

    // Copy input to Guesses class
    pGuesses->SetNumbers(GuessA, GuessB, GuessC);

    PrintGuessDebug(pGuesses);

    // Test if guess calculations are the same as code calculations
    if (pGuesses->GetGuessProduct() == pClues->GetClueProduct() && pGuesses->GetGuessSum() == pClues->GetClueSum())
    {
        std::wcout << L"You guessed correctly!" << std::endl;
        std::wcout << std::endl;
        
        return true;
    }
    else
    {
        std::wcout << L"These are the wrong numbers! :(" << std::endl;
        std::wcout << std::endl;

        return false;
    }    
}
