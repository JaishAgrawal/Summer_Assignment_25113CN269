#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int choice;
    double balance = 1000.00;
    double amount;

    printf("Welcome to the ATM Simulation\n");
    printf("----------------------------\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            continue;
        }

        switch (choice) {
            case 1:
                printf("Your current balance is: $%.2f\n", balance);
                break;
            case 2:
                printf("Enter deposit amount: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount. Deposit must be greater than 0.\n");
                } else {
                    balance += amount;
                    printf("Deposit successful. New balance: $%.2f\n", balance);
                }
                break;
            case 3:
                printf("Enter withdrawal amount: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount. Withdrawal must be greater than 0.\n");
                } else if (amount > balance) {
                    printf("Insufficient funds. Your balance is $%.2f.\n", balance);
                } else {
                    balance -= amount;
                    printf("Withdrawal successful. New balance: $%.2f\n", balance);
                }
                break;
            case 4:
                printf("Thank you for using the ATM simulation. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select 1-4.\n");
        }
    }
}
