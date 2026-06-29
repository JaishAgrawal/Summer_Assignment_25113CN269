//Write a program to Create menu-driven array operations system.
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void search(int arr[], int n, int x) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Element %d found at index %d\n", x, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in array\n", x);
    }
}

int insert(int arr[], int n, int pos, int x) {
    if (n >= MAX) {
        printf("Array is full!\n");
        return n;
    }
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return n;
    }
    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = x;
    printf("Element %d inserted at position %d\n", x, pos);
    return n + 1;
}

int deleteElement(int arr[], int n, int pos) {
    if (n == 0) {
        printf("Array is empty!\n");
        return n;
    }
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return n;
    }
    printf("Element %d deleted from position %d\n", arr[pos], pos);
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

void sortArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in ascending order\n");
}

void reverse(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Reversed array: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX];
    int n = 0;
    int choice, element, position;

    printf("========== MENU-DRIVEN ARRAY OPERATIONS SYSTEM ==========\n");

    while (1) {
        printf("\n1. Input Array\n");
        printf("2. Display Array\n");
        printf("3. Search Element\n");
        printf("4. Insert Element\n");
        printf("5. Delete Element\n");
        printf("6. Sort Array\n");
        printf("7. Reverse Array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements (max %d): ", MAX);
                scanf("%d", &n);
                if (n > MAX || n < 0) {
                    printf("Invalid size!\n");
                    n = 0;
                    break;
                }
                printf("Enter %d elements:\n", n);
                for (int i = 0; i < n; i++) {
                    printf("Element %d: ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                display(arr, n);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                search(arr, n, element);
                break;

            case 4:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &position);
                n = insert(arr, n, position, element);
                break;

            case 5:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &position);
                n = deleteElement(arr, n, position);
                break;

            case 6:
                sortArray(arr, n);
                break;

            case 7:
                reverse(arr, n);
                break;

            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
