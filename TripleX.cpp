#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty) {
    std::cout << "_________________________________________________________________________________________________________\n";
    std::cout << "\\__    ___/______   ____ _____    ________ _________   ____    /   |   \\ __ __  _____/  |_  ___________" << std::endl;
    std::cout << "  |    |  \\_  __ \\_/ __ \\__  \\  /  ___/  |  \\_  __ \\_/ __ \\  /    ~    \\  |  \\/    \\   __\\/ __ \\_  __ \\" << std::endl;
    std::cout << "  |    |   |  | \\/\\  ___/ / __ \\_\\___ \\|  |  /|  | \\/\\  ___/  \\    Y    /  |  /   |  \\  | \\  ___/|  | \\/" << std::endl;
    std::cout << "  |____|   |__|    \\___  >____  /____  >____/ |__|    \\___  >  \\___|_  /|____/|___|  /__|  \\___  >__|   " << std::endl;
    std::cout << "                       \\/     \\/     \\/                   \\/         \\/            \\/          \\/       " << std::endl;
    std::cout << "----------------------------------------------------------------------------------------\n";
    std::cout << "Welcome to the game! ";
    std::cout << "You're now the hero trying to get a katana by unlocking the treasure code\n";
    std::cout << "You're breaking treasure level " << Difficulty << std::endl;
    std::cout << "Enter the correct code to continue..";
}

bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "The codes add-up to: " << CodeSum << "\n";
    std::cout << "The codes CodeProduct to: " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC << "\n";

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the code is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "You win!\n";
        std::cout << "****Moving on to next level...\n";
        return true;
    }
    else {
        std::cout << "You lose!\n";
        std::cout << "****Reconquering the treasure...\n";
        return false;
    }

}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaximumLevel = 7;

    while (LevelDifficulty <= MaximumLevel) //Loop game until all levels complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clear any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "CONGRATULATION! YOU HAVE UNLOCKED THE SUPER SAMURAI KATANA!\n";
    std::cout << " __-----_________________{]___________________________________________________\n";
    std::cout << "{&&&&&&&#%%&#%&%&%&%&%#%&|]__________________________________________________/\n";
    std::cout << "                         {]\n";
    return 0;
}