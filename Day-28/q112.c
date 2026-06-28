#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 20
#define EMAIL_LEN 50
#define DATA_FILE "contacts.dat"

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} Contact;

Contact contacts[MAX_CONTACTS];
int contact_count = 0;

void load_contacts(void) {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        return;
    }
    fread(&contact_count, sizeof(int), 1, file);
    fread(contacts, sizeof(Contact), contact_count, file);
    fclose(file);
}

void save_contacts(void) {
    FILE *file = fopen(DATA_FILE, "wb");
    if (!file) {
        printf("Unable to save contacts.\n");
        return;
    }
    fwrite(&contact_count, sizeof(int), 1, file);
    fwrite(contacts, sizeof(Contact), contact_count, file);
    fclose(file);
}

void add_contact(void) {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }
    Contact c;
    printf("Enter name: ");
    fgets(c.name, NAME_LEN, stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(c.phone, PHONE_LEN, stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("Enter email: ");
    fgets(c.email, EMAIL_LEN, stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    contacts[contact_count++] = c;
    save_contacts();
    printf("Contact added successfully.\n");
}

void display_contacts(void) {
    if (contact_count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\nContact List:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d. Name: %s\n", i + 1, contacts[i].name);
        printf("   Phone: %s\n", contacts[i].phone);
        printf("   Email: %s\n", contacts[i].email);
    }
}

void search_contact(void) {
    char query[NAME_LEN];
    printf("Enter name to search: ");
    fgets(query, NAME_LEN, stdin);
    query[strcspn(query, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcasestr(contacts[i].name, query) != NULL) {
            printf("\nFound contact %d:\n", i + 1);
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void delete_contact(void) {
    if (contact_count == 0) {
        printf("No contacts to delete.\n");
        return;
    }
    display_contacts();
    printf("Enter contact number to delete: ");
    int index;
    if (scanf("%d", &index) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');
    if (index < 1 || index > contact_count) {
        printf("Invalid contact number.\n");
        return;
    }
    index--;
    for (int i = index; i < contact_count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contact_count--;
    save_contacts();
    printf("Contact deleted successfully.\n");
}

int main(void) {
    load_contacts();
    int choice;
    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}
