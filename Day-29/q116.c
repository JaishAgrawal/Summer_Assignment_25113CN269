//Write a program to Create inventory management system.
#include<stdio.h>
#include<string.h>

#define MAX 100

struct Item {
    int id;
    char name[50];
    int qty;
    float price;
};

int count = 0;
struct Item items[MAX];

void addItem() {
    if (count >= MAX) {
        printf("Inventory full!\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &items[count].id);
    printf("Enter name: ");
    scanf("%s", items[count].name);
    printf("Enter quantity: ");
    scanf("%d", &items[count].qty);
    printf("Enter price: ");
    scanf("%f", &items[count].price);
    count++;
    printf("Item added!\n");
}

void displayInventory() {
    if (count == 0) {
        printf("Inventory empty!\n");
        return;
    }
    printf("\nID\tName\tQty\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", items[i].id, items[i].name, items[i].qty, items[i].price);
    }
}

void searchItem() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("ID\tName\tQty\tPrice\n%d\t%s\t%d\t%.2f\n", items[i].id, items[i].name, items[i].qty, items[i].price);
            return;
        }
    }
    printf("Item not found!\n");
}

void updateQuantity() {
    int id, newQty;
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter new quantity: ");
    scanf("%d", &newQty);
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            items[i].qty = newQty;
            printf("Quantity updated!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void deleteItem() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            for (int j = i; j < count - 1; j++)
                items[j] = items[j + 1];
            count--;
            printf("Item deleted!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Item\n2. Display Inventory\n3. Search Item\n4. Update Quantity\n5. Delete Item\n6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addItem(); break;
            case 2: displayInventory(); break;
            case 3: searchItem(); break;
            case 4: updateQuantity(); break;
            case 5: deleteItem(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
