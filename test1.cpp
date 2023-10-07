#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); // seed the random number generator with the current time
    int secretNumber = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess;
    int tries = 0;

    std::cout << "I'm thinking of a number between 1 and 100. Can you guess it?\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        tries++;

        if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number in " << tries << " tries.\n";
        }
    } while (guess != secretNumber);

    return 0;
}
