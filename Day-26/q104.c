#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    const int totalQuestions = 5;
    const char questions[][200] = {
        "What is the capital of France?",
        "Which planet is known as the Red Planet?",
        "How many continents are there on Earth?",
        "What is the chemical symbol for water?",
        "Which programming language is this program written in?"
    };
    const char options[][4][50] = {
        {"A. Berlin", "B. Paris", "C. Madrid", "D. Rome"},
        {"A. Mercury", "B. Venus", "C. Mars", "D. Jupiter"},
        {"A. 5", "B. 6", "C. 7", "D. 8"},
        {"A. O2", "B. H2O", "C. CO2", "D. NaCl"},
        {"A. Python", "B. Java", "C. C", "D. JavaScript"}
    };
    const char answers[] = {'B', 'C', 'C', 'B', 'C'};
    char userAnswer;
    int score = 0;

    printf("Welcome to the Quiz Application!\n");
    printf("Answer the following questions by entering A, B, C, or D.\n\n");

    for (int i = 0; i < totalQuestions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i]);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", options[i][j]);
        }
        printf("Your answer: ");

        if (scanf(" %c", &userAnswer) != 1) {
            printf("Invalid input. Please enter A, B, C, or D.\n\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            i--;
            continue;
        }

        userAnswer = (char)toupper(userAnswer);
        if (userAnswer == answers[i]) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c.\n\n", answers[i]);
        }
    }

    printf("Quiz complete! You scored %d out of %d.\n", score, totalQuestions);

    if (score == totalQuestions) {
        printf("Excellent work!\n");
    } else if (score >= totalQuestions / 2) {
        printf("Good job!\n");
    } else {
        printf("Keep practicing.\n");
    }

    return 0;
}
