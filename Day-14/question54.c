//wap to frequency of an element in an array.
#include <stdio.h>
int main() {
    int size, element, frequency = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size]; // Declare an array of the specified size
    printf("Enter %d elements:\n", size);   
for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // Read each element into the array
    }
    printf("Enter the element to find its frequency: ");
    scanf("%d", &element); // Read the element to find its frequency
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            frequency++; // Increment frequency if the element matches
        }
    }
    printf("Frequency of element %d in the array: %d\n", element, frequency);
    return 0;
}