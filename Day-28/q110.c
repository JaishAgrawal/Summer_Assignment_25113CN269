#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
    int accountNumber;
    char name[NAME_LEN];
    double balance;
    int active;
} Account;

static Account accounts[MAX_ACCOUNTS];
static int accountCount = 0;

int findAccountIndex(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].active && accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

void createAccount(void) {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum reached.\n");
        return;
    }

    Account acct;
    printf("Enter account number: ");
    scanf("%d", &acct.accountNumber);
    if (findAccountIndex(acct.accountNumber) != -1) {
        printf("Account with this number already exists.\n");
        return;
    }

    printf("Enter account holder name: ");
    getchar();
    fgets(acct.name, NAME_LEN, stdin);
    size_t len = strlen(acct.name);
    if (len > 0 && acct.name[len - 1] == '\n') {
        acct.name[len - 1] = '\0';
    }

    printf("Enter initial deposit amount: ");
    scanf("%lf", &acct.balance);
    if (acct.balance < 0) {
        printf("Initial deposit cannot be negative.\n");
        return;
    }

    acct.active = 1;
    accounts[accountCount++] = acct;
    printf("Account created successfully.\n");
}

void deposit(void) {
    int accNo;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    int idx = findAccountIndex(accNo);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Deposit amount must be positive.\n");
        return;
    }

    accounts[idx].balance += amount;
    printf("Deposit successful. New balance: %.2f\n", accounts[idx].balance);
}

void withdraw(void) {
    int accNo;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    int idx = findAccountIndex(accNo);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Withdrawal amount must be positive.\n");
        return;
    }
    if (amount > accounts[idx].balance) {
        printf("Insufficient funds. Current balance: %.2f\n", accounts[idx].balance);
        return;
    }

    accounts[idx].balance -= amount;
    printf("Withdrawal successful. New balance: %.2f\n", accounts[idx].balance);
}

void displayAccount(void) {
    int accNo;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    int idx = findAccountIndex(accNo);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Account Number: %d\n", accounts[idx].accountNumber);
    printf("Account Holder: %s\n", accounts[idx].name);
    printf("Balance: %.2f\n", accounts[idx].balance);
}

void listAccounts(void) {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\nList of active accounts:\n");
    printf("%-15s %-20s %-10s\n", "Account No", "Name", "Balance");
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].active) {
            printf("%-15d %-20s %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
        }
    }
}

void closeAccount(void) {
    int accNo;
    printf("Enter account number to close: ");
    scanf("%d", &accNo);
    int idx = findAccountIndex(accNo);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    accounts[idx].active = 0;
    printf("Account closed successfully.\n");
}

int main(void) {
    int choice;

    while (1) {
        printf("\nBank Account System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account\n");
        printf("5. List All Accounts\n");
        printf("6. Close Account\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayAccount();
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                closeAccount();
                break;
            case 7:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
