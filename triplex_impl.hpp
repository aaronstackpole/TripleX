#pragma once

#include <memory>

namespace TripleX
{
    // Game play difficulty tuning values
    auto constexpr MIN_DIFFICULTY = 2;
    auto constexpr MAX_DIFFICULTY = 9;

    // Contains game state values to provide dynamic challenge
    class Difficulty
    {
        int mDifficulty = 2;
    public:
        void SetDifficulty(int difficulty);
        int const & GetDifficulty();

        void IncrementDifficulty();
        void DecrementDifficulty();
    };
    using DifficultyPtr = std::shared_ptr<Difficulty>;

    // Clues and Guesses basic number interface
    class INumbers
    {
    protected:
        virtual void UpdateSum() = 0;
        virtual void UpdateProduct() = 0;
    public:
        virtual void SetNumbers(int numberA, int numberB, int numberC) = 0;
    };

    // To store codes generated by the game
    class Clues : public INumbers
    {
        int mClueA = 2;
        int mClueB = 3;
        int mClueC = 4;

        int mClueSum = mClueA + mClueB + mClueC;
        int mClueProduct = mClueA * mClueB * mClueC;

        void UpdateSum() override;
        void UpdateProduct() override;
    public:
        void SetNumbers(int numberA, int numberB, int numberC) override;

        int const & GetClueA();
        int const & GetClueB();
        int const & GetClueC();
        
        int const & GetClueSum();
        int const & GetClueProduct();
    };
    using CluesPtr = std::shared_ptr<Clues>;

    // To store codes input by the user
    class Guesses : public INumbers
    {
        int mGuessA = 0;
        int mGuessB = 0;
        int mGuessC = 0;

        int mGuessSum = mGuessA + mGuessB + mGuessC; // = 0
        int mGuessProduct = mGuessA * mGuessB * mGuessC; // = 0

        void UpdateSum() override;
        void UpdateProduct() override;
    public:
        void SetNumbers(int numberA, int numberB, int numberC) override;

        int const & GetGuessA();
        int const & GetGuessB();
        int const & GetGuessC();
        
        int const & GetGuessSum();
        int const & GetGuessProduct();
    };
    using GuessesPtr = std::shared_ptr<Guesses>;

    // Execute the main game logic once and return success
    bool PlayLevel(DifficultyPtr & pDifficulty, CluesPtr & pClues, GuessesPtr & pGuesses);

    // Print welcome messages to the terminal
    void PrintIntroduction(DifficultyPtr & pDifficulty);
    // Print code clues and input prompt
    void PrintCluesAndPrompt(CluesPtr & pClues);

    // Output some debug messages about the captured input and calculations
    void PrintGuessDebug(GuessesPtr & pGuesses);
    // Output some debug messages about the generated codes
    void PrintCluesDebug(CluesPtr & pClues);
}
