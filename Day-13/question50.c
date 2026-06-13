//wap to find sum and average of array.
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
    int sum = 0; // Initialize sum to 0
    for (int i = 0; i < size; i++) {
        sum += arr[i]; // Add each element to the sum
    }
    double average = (double)sum / size; // Calculate average
    printf("The sum of the array is: %d\n", sum);
    printf("The average of the array is: %.2f\n", average);
    return 0;
}