#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LEN 50
#define SUBJECTS 5

typedef struct {
    int roll;
    char name[MAX_NAME_LEN];
    int marks[SUBJECTS];
    float average;
} Student;

void initializeStudents(Student students[], int size) {
    for (int i = 0; i < size; i++) {
        students[i].roll = 0;
        students[i].name[0] = '\0';
        students[i].average = 0.0f;
        for (int j = 0; j < SUBJECTS; j++) {
            students[i].marks[j] = 0;
        }
    }
}

int findEmptySlot(Student students[], int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].roll == 0) {
            return i;
        }
    }
    return -1;
}

void calculateAverage(Student *student) {
    int total = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        total += student->marks[i];
    }
    student->average = (float) total / SUBJECTS;
}

void addStudent(Student students[], int size) {
    int index = findEmptySlot(students, size);
    if (index == -1) {
        printf("No more slots available.\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &students[index].roll);
    getchar();

    printf("Enter student name: ");
    fgets(students[index].name, MAX_NAME_LEN, stdin);
    students[index].name[strcspn(students[index].name, "\n")] = '\0';

    for (int i = 0; i < SUBJECTS; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &students[index].marks[i]);
    }
    calculateAverage(&students[index]);
    printf("Student added successfully.\n");
}

void displayStudent(const Student *student) {
    printf("Roll: %d\n", student->roll);
    printf("Name: %s\n", student->name);
    printf("Marks: ");
    for (int i = 0; i < SUBJECTS; i++) {
        printf("%d ", student->marks[i]);
    }
    printf("\nAverage: %.2f\n", student->average);
    printf("---------------------------\n");
}

void displayAllStudents(const Student students[], int size) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].roll != 0) {
            displayStudent(&students[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No student records to display.\n");
    }
}

void searchStudent(const Student students[], int size) {
    char query[MAX_NAME_LEN];
    printf("Enter name or roll number to search: ");
    getchar();
    fgets(query, MAX_NAME_LEN, stdin);
    query[strcspn(query, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].roll != 0) {
            if (students[i].roll == atoi(query) || strcasecmp(students[i].name, query) == 0) {
                displayStudent(&students[i]);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

void updateMarks(Student students[], int size) {
    int roll;
    printf("Enter roll number of student to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < size; i++) {
        if (students[i].roll == roll) {
            printf("Updating marks for %s\n", students[i].name);
            for (int j = 0; j < SUBJECTS; j++) {
                printf("Enter new marks for subject %d: ", j + 1);
                scanf("%d", &students[i].marks[j]);
            }
            calculateAverage(&students[i]);
            printf("Marks updated successfully.\n");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

void sortStudentsByAverage(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (students[i].roll != 0 && students[j].roll != 0 && students[i].average < students[j].average) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by average in descending order.\n");
}

int main(void) {
    Student students[MAX_STUDENTS];
    initializeStudents(students, MAX_STUDENTS);

    int choice;
    do {
        printf("\nMini Student Management Project\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search student\n");
        printf("4. Update student marks\n");
        printf("5. Sort students by average\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, MAX_STUDENTS);
                break;
            case 2:
                displayAllStudents(students, MAX_STUDENTS);
                break;
            case 3:
                searchStudent(students, MAX_STUDENTS);
                break;
            case 4:
                updateMarks(students, MAX_STUDENTS);
                break;
            case 5:
                sortStudentsByAverage(students, MAX_STUDENTS);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
