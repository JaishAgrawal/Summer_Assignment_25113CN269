//wap to count even and odd elements in an array.
#include <stdio.h>
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size]; // Declare an array of the specified size
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // Read each element into the array   }
    int evenCount = 0; // Initialize even count to 0
    int oddCount = 0; // Initialize odd count to 0
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++; // Increment even count if the element is even
        } else {
            oddCount++; // Increment odd count if the element is odd
        }
    }
    printf("Number of even elements in the array: %d\n", evenCount);
    printf("Number of odd elements in the array: %d\n", oddCount);
    return 0;
}