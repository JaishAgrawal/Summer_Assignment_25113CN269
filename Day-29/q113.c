
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int choice;
	double a, b, result;

	while (1) {
		printf("\n--- Menu-driven Calculator ---\n");
		printf("1. Addition\n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("5. Modulo (integers)\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) {
			printf("Invalid input. Exiting.\n");
			break;
		}

		if (choice == 6) {
			printf("Exiting.\n");
			break;
		}

		if (choice >=1 && choice <=5) {
			printf("Enter first number: ");
			if (scanf("%lf", &a) != 1) { printf("Invalid input.\n"); break; }
			printf("Enter second number: ");
			if (scanf("%lf", &b) != 1) { printf("Invalid input.\n"); break; }
		}

		switch (choice) {
			case 1:
				result = a + b;
				printf("Result: %.10g\n", result);
				break;
			case 2:
				result = a - b;
				printf("Result: %.10g\n", result);
				break;
			case 3:
				result = a * b;
				printf("Result: %.10g\n", result);
				break;
			case 4:
				if (b == 0) {
					printf("Error: Division by zero.\n");
				} else {
					result = a / b;
					printf("Result: %.10g\n", result);
				}
				break;
			case 5: {
				long ia = (long)a;
				long ib = (long)b;
				if (ib == 0) {
					printf("Error: Modulo by zero.\n");
				} else {
					long r = ia % ib;
					printf("Result: %ld\n", r);
				}
				break;
			}
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}
