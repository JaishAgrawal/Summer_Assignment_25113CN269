#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int secretNumber, guess, attempts = 0;
    const int maxAttempts = 5;

    srand((unsigned int)time(NULL));
    secretNumber = rand() % 100 + 1; // random number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n\n", maxAttempts);

    while (attempts < maxAttempts) {
        printf("Enter your guess (%d remaining): ", maxAttempts - attempts);
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // clear invalid input from stdin
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            continue;
        }

        attempts++;

        if (guess < secretNumber) {
            printf("Too low! Try a higher number.\n\n");
        } else if (guess > secretNumber) {
            printf("Too high! Try a lower number.\n\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempt%s.\n", attempts, attempts == 1 ? "" : "s");
            return 0;
        }
    }

    printf("Sorry, you've used all your attempts. The correct number was %d.\n", secretNumber);
    return 0;
}
