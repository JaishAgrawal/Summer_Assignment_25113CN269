//wap to sort array in descending order.
#include <stdio.h>

int main() {
    int arr[100];
    int n, i, j, temp;

    // Ask user for the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements from the user
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Logic for sorting the array in descending order (Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Change '<' to '>' if you want ascending order
            if (arr[j] < arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("\nArray sorted in descending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
