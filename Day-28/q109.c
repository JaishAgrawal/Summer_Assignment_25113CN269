#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
    int total;
    int available;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) ;
}

void read_string(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book new_book;
    printf("Enter book ID: ");
    if (scanf("%d", &new_book.id) != 1) {
        clear_input_buffer();
        printf("Invalid input.\n");
        return;
    }
    clear_input_buffer();

    read_string("Enter title: ", new_book.title, sizeof(new_book.title));
    read_string("Enter author: ", new_book.author, sizeof(new_book.author));
    printf("Enter total number of copies: ");
    if (scanf("%d", &new_book.total) != 1 || new_book.total < 1) {
        clear_input_buffer();
        printf("Invalid number of copies.\n");
        return;
    }
    clear_input_buffer();

    new_book.available = new_book.total;
    library[book_count++] = new_book;
    printf("Book added successfully.\n");
}

void display_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nLibrary Books:\n");
    for (int i = 0; i < book_count; i++) {
        Book *b = &library[i];
        printf("ID: %d\nTitle: %s\nAuthor: %s\nTotal copies: %d\nAvailable: %d\n\n",
               b->id, b->title, b->author, b->total, b->available);
    }
}

int find_book_index_by_id(int id) {
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            return i;
        }
    }
    return -1;
}

void search_book() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    int id;
    printf("Enter book ID to search: ");
    if (scanf("%d", &id) != 1) {
        clear_input_buffer();
        printf("Invalid input.\n");
        return;
    }
    clear_input_buffer();

    int index = find_book_index_by_id(id);
    if (index < 0) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    Book *b = &library[index];
    printf("ID: %d\nTitle: %s\nAuthor: %s\nTotal copies: %d\nAvailable: %d\n",
           b->id, b->title, b->author, b->total, b->available);
}

void issue_book() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    int id;
    printf("Enter book ID to issue: ");
    if (scanf("%d", &id) != 1) {
        clear_input_buffer();
        printf("Invalid input.\n");
        return;
    }
    clear_input_buffer();

    int index = find_book_index_by_id(id);
    if (index < 0) {
        printf("Book with ID %d not found.\n", id);
        return;
    }
    if (library[index].available <= 0) {
        printf("No copies available to issue.\n");
        return;
    }
    library[index].available--;
    printf("Book issued successfully. Available copies: %d\n", library[index].available);
}

void return_book() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    int id;
    printf("Enter book ID to return: ");
    if (scanf("%d", &id) != 1) {
        clear_input_buffer();
        printf("Invalid input.\n");
        return;
    }
    clear_input_buffer();

    int index = find_book_index_by_id(id);
    if (index < 0) {
        printf("Book with ID %d not found.\n", id);
        return;
    }
    if (library[index].available >= library[index].total) {
        printf("All copies are already returned.\n");
        return;
    }
    library[index].available++;
    printf("Book returned successfully. Available copies: %d\n", library[index].available);
}

int main(void) {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Invalid choice. Please enter a number.\n");
            continue;
        }
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                issue_book();
                break;
            case 5:
                return_book();
                break;
            case 6:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
