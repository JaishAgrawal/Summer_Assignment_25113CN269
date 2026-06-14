//wap too find duplicate elements in an array.
#include <stdio.h>
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size]; // Declare an array of the specified size    
printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // Read each element into the array
    }
    printf("Duplicate elements in the array are:\n");
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) { 
                printf("%d\n", arr[i]); // Print the duplicate element
                break; // Exit the inner loop to avoid printing the same duplicate multiple times
            }
        }
    }
    return 0;
}