#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float hraPercent;
    float daPercent;
    float allowances;
    float deductions;
    float netSalary;
};

void calculateSalary(struct Employee *emp) {
    float hra = (emp->basicSalary * emp->hraPercent) / 100.0f;
    float da = (emp->basicSalary * emp->daPercent) / 100.0f;
    emp->netSalary = emp->basicSalary + hra + da + emp->allowances - emp->deductions;
}

int main(void) {
    int n, i;

    printf("Salary Management System\n");
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee employees[100];

    for (i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%49s", employees[i].name);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);
        printf("HRA (percent): ");
        scanf("%f", &employees[i].hraPercent);
        printf("DA (percent): ");
        scanf("%f", &employees[i].daPercent);
        printf("Allowances: ");
        scanf("%f", &employees[i].allowances);
        printf("Deductions: ");
        scanf("%f", &employees[i].deductions);

        calculateSalary(&employees[i]);
    }

    printf("\nSalary Report\n");
    printf("-----------------------------------\n");
    printf("ID\tName\t\tNet Salary\n");
    printf("-----------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\n", employees[i].id, employees[i].name, employees[i].netSalary);
    }

    return 0;
}
