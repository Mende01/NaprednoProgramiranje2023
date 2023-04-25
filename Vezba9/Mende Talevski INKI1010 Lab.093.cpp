#include <iostream>
#include <cstdlib>
#include <ctime>
int main() 
{
    std::srand(std::time(nullptr));
    int secret_number = std::rand() % 100 + 1; 
    int guess, num_guesses = 0; 
 while (true) 
 {
        std::cout << "Pogodi go brojot ";
        std::cin >> guess;
        num_guesses++; 
        if (guess == secret_number) 
        {
            std::cout << "Go pokodivte brojot po " << num_guesses << "obidi!" << std::endl;
            break;
        } else if (guess < secret_number) 
        {
            std::cout << "Pogolemo!" << std::endl;
        } else {
            std::cout << "Pomalo!" << std::endl;
        }
    }

    return 0;
}