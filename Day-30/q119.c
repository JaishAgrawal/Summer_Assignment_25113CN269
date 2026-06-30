
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMP 100

typedef struct {
	int id;
	char name[50];
	char dept[30];
	float salary;
	int valid;
} Employee;

Employee emps[MAX_EMP];

void init() {
	for (int i = 0; i < MAX_EMP; i++) emps[i].valid = 0;
}

void add_employee() {
	int i;
	for (i = 0; i < MAX_EMP && emps[i].valid; i++);
	if (i == MAX_EMP) { printf("Database full.\n"); return; }
	printf("Enter id: "); scanf("%d", &emps[i].id);
	printf("Enter name: "); scanf(" "); fgets(emps[i].name, sizeof emps[i].name, stdin);
	if (emps[i].name[strlen(emps[i].name)-1]=='\n') emps[i].name[strlen(emps[i].name)-1]=0;
	printf("Enter dept: "); fgets(emps[i].dept, sizeof emps[i].dept, stdin);
	if (emps[i].dept[strlen(emps[i].dept)-1]=='\n') emps[i].dept[strlen(emps[i].dept)-1]=0;
	printf("Enter salary: "); scanf("%f", &emps[i].salary);
	emps[i].valid = 1;
	printf("Employee added.\n");
}

void list_employees() {
	int found = 0;
	printf("ID\tName\tDepartment\tSalary\n");
	for (int i = 0; i < MAX_EMP; i++) if (emps[i].valid) {
		printf("%d\t%s\t%s\t%.2f\n", emps[i].id, emps[i].name, emps[i].dept, emps[i].salary);
		found = 1;
	}
	if (!found) printf("No employees.\n");
}

int find_index_by_id(int id) {
	for (int i = 0; i < MAX_EMP; i++) if (emps[i].valid && emps[i].id == id) return i;
	return -1;
}

void search_employee() {
	int id; printf("Enter id to search: "); scanf("%d", &id);
	int idx = find_index_by_id(id);
	if (idx==-1) { printf("Not found.\n"); return; }
	printf("Found: %d %s %s %.2f\n", emps[idx].id, emps[idx].name, emps[idx].dept, emps[idx].salary);
}

void delete_employee() {
	int id; printf("Enter id to delete: "); scanf("%d", &id);
	int idx = find_index_by_id(id);
	if (idx==-1) { printf("Not found.\n"); return; }
	emps[idx].valid = 0;
	printf("Deleted.\n");
}

void update_employee() {
	int id; printf("Enter id to update: "); scanf("%d", &id);
	int idx = find_index_by_id(id);
	if (idx==-1) { printf("Not found.\n"); return; }
	printf("Enter new name: "); scanf(" "); fgets(emps[idx].name, sizeof emps[idx].name, stdin);
	if (emps[idx].name[strlen(emps[idx].name)-1]=='\n') emps[idx].name[strlen(emps[idx].name)-1]=0;
	printf("Enter new dept: "); fgets(emps[idx].dept, sizeof emps[idx].dept, stdin);
	if (emps[idx].dept[strlen(emps[idx].dept)-1]=='\n') emps[idx].dept[strlen(emps[idx].dept)-1]=0;
	printf("Enter new salary: "); scanf("%f", &emps[idx].salary);
	printf("Updated.\n");
}

int main() {
	init();
	int choice;
	while (1) {
		printf("\nMini Employee Management\n1.Add\n2.List\n3.Search\n4.Update\n5.Delete\n6.Exit\nChoose: ");
		if (scanf("%d", &choice)!=1) break;
		switch (choice) {
			case 1: add_employee(); break;
			case 2: list_employees(); break;
			case 3: search_employee(); break;
			case 4: update_employee(); break;
			case 5: delete_employee(); break;
			case 6: exit(0);
			default: printf("Invalid.\n");
		}
	}
	return 0;
}
