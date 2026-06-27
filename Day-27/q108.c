#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100];
    char school[100];
    char className[20];
    int roll;
    float marks[5];
    const char *subjects[5] = {"Mathematics", "Science", "English", "Social Studies", "Hindi"};
    float total = 0.0f;
    float percent;
    char grade;

    printf("Enter student name: ");
    fgets(name, sizeof(name), stdin);
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }

    printf("Enter school name: ");
    fgets(school, sizeof(school), stdin);
    if (school[strlen(school) - 1] == '\n') {
        school[strlen(school) - 1] = '\0';
    }

    printf("Enter class: ");
    fgets(className, sizeof(className), stdin);
    if (className[strlen(className) - 1] == '\n') {
        className[strlen(className) - 1] = '\0';
    }

    printf("Enter roll number: ");
    scanf("%d", &roll);

    for (int i = 0; i < 5; ++i) {
        printf("Enter marks for %s (out of 100): ", subjects[i]);
        scanf("%f", &marks[i]);
        if (marks[i] < 0) {
            marks[i] = 0;
        } else if (marks[i] > 100) {
            marks[i] = 100;
        }
        total += marks[i];
    }

    percent = total / 5.0f;
    if (percent >= 90) {
        grade = 'A';
    } else if (percent >= 75) {
        grade = 'B';
    } else if (percent >= 60) {
        grade = 'C';
    } else if (percent >= 40) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    printf("\n-------------------- MARKSHEET --------------------\n");
    printf("Student Name : %s\n", name);
    printf("School       : %s\n", school);
    printf("Class        : %s\n", className);
    printf("Roll Number  : %d\n", roll);
    printf("--------------------------------------------------\n");
    for (int i = 0; i < 5; ++i) {
        printf("%-15s : %6.2f\n", subjects[i], marks[i]);
    }
    printf("--------------------------------------------------\n");
    printf("Total Marks  : %6.2f / 500.00\n", total);
    printf("Percentage   : %6.2f%%\n", percent);
    printf("Grade        : %c\n", grade);
    printf("--------------------------------------------------\n");

    return 0;
}
