#include <stdio.h>

int main(void)
{
    int age;

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        printf("Invalid input. Please enter a numeric age.\n");
        return 1;
    }

    if (age < 0) {
        printf("Age cannot be negative.\n");
    } else if (age >= 18) {
        printf("You are eligible to vote.\n");
    } else {
        printf("You are not eligible to vote.\n");
        printf("You need %d more year%s to become eligible.\n", 18 - age, (18 - age) == 1 ? "" : "s");
    }

    return 0;
}
