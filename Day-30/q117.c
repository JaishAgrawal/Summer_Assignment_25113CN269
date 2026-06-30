#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int roll_number;
    char name[MAX_NAME_LENGTH];
    float gpa;
    char email[MAX_NAME_LENGTH];
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }
    
    printf("\nEnter Roll Number: ");
    scanf("%d", &students[student_count].roll_number);
    
    printf("Enter Name: ");
    scanf("%s", students[student_count].name);
    
    printf("Enter GPA: ");
    scanf("%f", &students[student_count].gpa);
    
    printf("Enter Email: ");
    scanf("%s", students[student_count].email);
    
    student_count++;
    printf("Student added successfully!\n");
}

void display_all_students() {
    if (student_count == 0) {
        printf("\nNo students in the system!\n");
        return;
    }
    
    printf("\n========== Student Records ==========\n");
    printf("%-12s %-20s %-8s %-25s\n", "Roll Number", "Name", "GPA", "Email");
    printf("=====================================\n");
    
    for (int i = 0; i < student_count; i++) {
        printf("%-12d %-20s %-8.2f %-25s\n", 
               students[i].roll_number, 
               students[i].name, 
               students[i].gpa, 
               students[i].email);
    }
}

void search_student() {
    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll) {
            printf("\nStudent Found:\n");
            printf("Roll Number: %d\n", students[i].roll_number);
            printf("Name: %s\n", students[i].name);
            printf("GPA: %.2f\n", students[i].gpa);
            printf("Email: %s\n", students[i].email);
            return;
        }
    }
    printf("Student not found!\n");
}

void delete_student() {
    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void menu() {
    printf("\n======= Student Record System =======\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
    printf("=====================================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    
    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_all_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
