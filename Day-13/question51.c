
//wap to find largest and smallest element in an array.
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
    int smallest = arr[0]; // Initialize smallest to the first element  
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; // Update largest if current element is greater
        }
        if (arr[i] < smallest) {
            smallest = arr[i]; // Update smallest if current element is smaller
        }
    }
    printf("The largest element in the array is: %d\n", largest);
    printf("The smallest element in the array is: %d\n", smallest);
    return 0;
}