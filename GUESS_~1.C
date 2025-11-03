#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0, maxAttempts;
    int difficulty;
    
    // Initialize random number generator
    srand(time(0));
    number = rand() % 100 + 1; // Random number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    
    // Choose difficulty level
    printf("Select difficulty level:\n");
    printf("1. Easy (10 attempts)\n");
    printf("2. Medium (7 attempts)\n");
    printf("3. Hard (5 attempts)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &difficulty);

    // Set maximum attempts based on difficulty
    switch(difficulty) {
        case 1: maxAttempts = 10; break;
        case 2: maxAttempts = 7; break;
        case 3: maxAttempts = 5; break;
        default: 
            printf("Invalid choice. Defaulting to Easy level.\n");
            maxAttempts = 10;
    }

    printf("You have %d attempts to guess the number.\n", maxAttempts);

    // Loop until user guesses or runs out of attempts
    while(attempts < maxAttempts) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Attempts left: %d\n", maxAttempts - attempts);
        } else if (guess < number) {
            printf("Too low! Attempts left: %d\n", maxAttempts - attempts);
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        }
    }

    if (guess != number) {
        printf("Sorry, you've used all your attempts. The number was %d.\n", number);
    }

    return 0;
}
