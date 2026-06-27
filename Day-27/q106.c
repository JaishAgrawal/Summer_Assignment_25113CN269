#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }

    Employee e;
    printf("Enter employee ID: ");
    scanf("%d", &e.id);
    printf("Enter employee name: ");
    scanf("%49s", e.name);
    printf("Enter employee salary: ");
    scanf("%f", &e.salary);

    employees[*count] = e;
    (*count)++;
    printf("Employee added successfully.\n");
}

void displayEmployees(const Employee employees[], int count) {
    if (count == 0) {
        printf("No employees found.\n");
        return;
    }

    printf("\nEmployee Details:\n");
    printf("ID\tName\t\tSalary\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

int findEmployee(const Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void updateEmployee(Employee employees[], int count) {
    int id;
    printf("Enter employee ID to update: ");
    scanf("%d", &id);

    int index = findEmployee(employees, count, id);
    if (index == -1) {
        printf("Employee not found.\n");
        return;
    }

    printf("Enter new salary: ");
    scanf("%f", &employees[index].salary);
    printf("Salary updated successfully.\n");
}

void deleteEmployee(Employee employees[], int *count) {
    int id;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);

    int index = findEmployee(employees, *count, id);
    if (index == -1) {
        printf("Employee not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        employees[i] = employees[i + 1];
    }
    (*count)--;
    printf("Employee deleted successfully.\n");
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Update Employee Salary\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                updateEmployee(employees, count);
                break;
            case 4:
                deleteEmployee(employees, &count);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}


