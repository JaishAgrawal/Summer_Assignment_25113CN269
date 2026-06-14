//wap to linear search an element in an array.
#include <stdio.h>
int main() {
    int size, element, found = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size]; // Declare an array of the specified size
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // Read each element into the array
    }
    printf("Enter the element to search: ");
    scanf("%d", &element); // Read the element to search for
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            found = 1; // Set found to 1 if the element is found
            break; // Exit the loop as we found the element
        }
    }
    if (found) {
        printf("Element %d is found in the array.\n", element);
    } else {
        printf("Element %d is not found in the array.\n", element);
    }
    return 0;
}