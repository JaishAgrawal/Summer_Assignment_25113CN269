//wap to and display array.
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
    printf("The elements of the array are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Print each element of the array
    }
    printf("\n");
    return 0;
}