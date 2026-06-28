#include <stdio.h>
#include <string.h>

#define MAX_SHOWS 5

typedef struct {
    char name[50];
    int totalSeats;
    int booked;
} Show;

void displayShows(Show shows[]) {
    printf("\nAvailable Shows:\n");
    printf("%-4s %-25s %-10s %-10s\n", "ID", "Show Name", "Total", "Booked");
    for (int i = 0; i < MAX_SHOWS; i++) {
        printf("%-4d %-25s %-10d %-10d\n", i + 1, shows[i].name, shows[i].totalSeats, shows[i].booked);
    }
}

void bookTicket(Show shows[]) {
    int choice, count;
    displayShows(shows);
    printf("\nEnter show ID to book: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > MAX_SHOWS) {
        printf("Invalid show ID.\n");
        return;
    }
    printf("Enter number of tickets to book: ");
    scanf("%d", &count);
    if (count <= 0) {
        printf("Enter a positive number of tickets.\n");
        return;
    }
    Show *selected = &shows[choice - 1];
    int available = selected->totalSeats - selected->booked;
    if (count > available) {
        printf("Only %d tickets are available for '%s'.\n", available, selected->name);
    } else {
        selected->booked += count;
        printf("Successfully booked %d ticket(s) for '%s'.\n", count, selected->name);
    }
}

void cancelTicket(Show shows[]) {
    int choice, count;
    displayShows(shows);
    printf("\nEnter show ID to cancel booking: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > MAX_SHOWS) {
        printf("Invalid show ID.\n");
        return;
    }
    printf("Enter number of tickets to cancel: ");
    scanf("%d", &count);
    if (count <= 0) {
        printf("Enter a positive number of tickets.\n");
        return;
    }
    Show *selected = &shows[choice - 1];
    if (count > selected->booked) {
        printf("You only have %d booked ticket(s) for '%s'.\n", selected->booked, selected->name);
    } else {
        selected->booked -= count;
        printf("Successfully cancelled %d ticket(s) for '%s'.\n", count, selected->name);
    }
}

int main(void) {
    Show shows[MAX_SHOWS] = {
        {"Morning Movie", 50, 0},
        {"Matinee Show", 40, 0},
        {"Evening Drama", 60, 0},
        {"Night Concert", 80, 0},
        {"Late Night Comedy", 30, 0}
    };

    int choice;
    do {
        printf("\nTicket Booking System\n");
        printf("1. Display shows\n");
        printf("2. Book tickets\n");
        printf("3. Cancel tickets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayShows(shows);
                break;
            case 2:
                bookTicket(shows);
                break;
            case 3:
                cancelTicket(shows);
                break;
            case 4:
                printf("Exiting booking system.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
