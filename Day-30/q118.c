#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 50

typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int available; // 1 = available, 0 = borrowed
} Book;

Book library[MAX_BOOKS];
int count = 0;

void add_book() {
    if (count >= MAX_BOOKS) {
        printf("Library full. Cannot add more books.\n");
        return;
    }
    Book b;
    b.id = (count == 0) ? 1 : library[count-1].id + 1;
    printf("Enter title: ");
    getchar(); // consume newline
    fgets(b.title, TITLE_LEN, stdin);
    b.title[strcspn(b.title, "\n")] = '\0';
    printf("Enter author: ");
    fgets(b.author, AUTHOR_LEN, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';
    b.available = 1;
    library[count++] = b;
    printf("Book added with ID %d\n", b.id);
}

void list_books() {
    if (count == 0) {
        printf("No books in library.\n");
        return;
    }
    printf("ID\tTitle\tAuthor\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%s\n", library[i].id, library[i].title, library[i].author,
               library[i].available ? "Available" : "Borrowed");
    }
}

int find_index_by_id(int id) {
    for (int i = 0; i < count; i++) if (library[i].id == id) return i;
    return -1;
}

void search_book() {
    char key[TITLE_LEN];
    printf("Enter title or author to search: ");
    getchar();
    fgets(key, TITLE_LEN, stdin);
    key[strcspn(key, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasestr(library[i].title, key) || strcasestr(library[i].author, key)) {
            if (!found) printf("Found:\nID\tTitle\tAuthor\tStatus\n");
            printf("%d\t%s\t%s\t%s\n", library[i].id, library[i].title, library[i].author,
                   library[i].available ? "Available" : "Borrowed");
            found = 1;
        }
    }
    if (!found) printf("No matching books found.\n");
}

void borrow_book() {
    int id;
    printf("Enter book ID to borrow: ");
    if (scanf("%d", &id) != 1) { printf("Invalid input.\n"); return; }
    int idx = find_index_by_id(id);
    if (idx == -1) { printf("Book not found.\n"); return; }
    if (!library[idx].available) { printf("Book already borrowed.\n"); return; }
    library[idx].available = 0;
    printf("You borrowed '%s'.\n", library[idx].title);
}

void return_book() {
    int id;
    printf("Enter book ID to return: ");
    if (scanf("%d", &id) != 1) { printf("Invalid input.\n"); return; }
    int idx = find_index_by_id(id);
    if (idx == -1) { printf("Book not found.\n"); return; }
    if (library[idx].available) { printf("Book was not borrowed.\n"); return; }
    library[idx].available = 1;
    printf("You returned '%s'.\n", library[idx].title);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Mini Library System ---\n");
        printf("1. Add book\n2. List books\n3. Search\n4. Borrow book\n5. Return book\n6. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) { printf("Invalid input. Exiting.\n"); break; }
        switch (choice) {
            case 1: add_book(); break;
            case 2: list_books(); break;
            case 3: search_book(); break;
            case 4: borrow_book(); break;
            case 5: return_book(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
