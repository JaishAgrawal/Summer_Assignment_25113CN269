#include <stdio.h>

int main(void)
{
    int n1, n2;

    printf("Enter the number of elements in the first sorted array: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter the number of elements in the second sorted array: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int arr1[n1];
    int arr2[n2];
    int merged[n1 + n2];

    printf("Enter %d sorted elements for the first array:\n", n1);
    for (int i = 0; i < n1; ++i) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter %d sorted elements for the second array:\n", n2);
    for (int i = 0; i < n2; ++i) {
        scanf("%d", &arr2[i]);
    }

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    printf("Merged sorted array:\n");
    for (int index = 0; index < k; ++index) {
        printf("%d ", merged[index]);
    }
    printf("\n");

    return 0;
}
