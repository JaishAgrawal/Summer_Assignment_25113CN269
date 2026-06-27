#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
    float marks;
} Student;

static Student students[MAX_STUDENTS];
static int student_count = 0;

void add_student(void) {
    if (student_count >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }

    Student s;
    printf("Enter student ID: ");
    scanf("%d", &s.id);
    getchar();
    printf("Enter student name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    printf("Enter student age: ");
    scanf("%d", &s.age);
    printf("Enter student marks: ");
    scanf("%f", &s.marks);

    students[student_count++] = s;
    printf("Student added successfully.\n");
}

void display_students(void) {
    if (student_count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\n%-5s %-20s %-5s %-7s\n", "ID", "Name", "Age", "Marks");
    printf("----------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%-5d %-20s %-5d %-7.2f\n", students[i].id, students[i].name, students[i].age, students[i].marks);
    }
}

int find_student_index(int id) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void search_student(void) {
    if (student_count == 0) {
        printf("No students available.\n");
        return;
    }

    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    int index = find_student_index(id);
    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
    } else {
        Student s = students[index];
        printf("Student found:\n");
        printf("ID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("Marks: %.2f\n", s.marks);
    }
}

void update_student(void) {
    if (student_count == 0) {
        printf("No students available.\n");
        return;
    }

    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    int index = find_student_index(id);
    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    printf("Enter new name: ");
    getchar();
    fgets(students[index].name, sizeof(students[index].name), stdin);
    students[index].name[strcspn(students[index].name, "\n")] = '\0';
    printf("Enter new age: ");
    scanf("%d", &students[index].age);
    printf("Enter new marks: ");
    scanf("%f", &students[index].marks);
    printf("Student record updated.\n");
}

void delete_student(void) {
    if (student_count == 0) {
        printf("No students available.\n");
        return;
    }

    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    int index = find_student_index(id);
    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }
    student_count--;
    printf("Student deleted successfully.\n");
}

int main(void) {
    int choice;
    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                update_student();
                break;
            case 5:
                delete_student();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
