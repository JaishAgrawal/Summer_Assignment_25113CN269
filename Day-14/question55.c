//wap to find second largest element in an array.
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
    int largest = arr[0]; // Initialize largest to the first element
    int secondLargest = -1; // Initialize second largest to -1 (or a suitable value)
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest; // Update second largest
            largest = arr[i]; // Update largest
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i]; // Update second largest if it's not equal to largest
        }
    }
    
    if (secondLargest == -1) {
        printf("There is no second largest element in the array.\n");
    } else {
        printf("The second largest element in the array is: %d\n", secondLargest);
    }
    
    return 0;
}