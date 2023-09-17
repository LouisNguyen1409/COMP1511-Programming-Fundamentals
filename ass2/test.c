#include <stdio.h>

// Function that takes an array of given length as an argument
void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n; // Length of the array
    printf("Enter the length of the array: ");
    scanf("%d", &n); // Scan in the length

    int arr[n]; // Declare an array of given length

    // Scan in array elements
    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Call the function and pass the array and its length
    printArray(arr, n);

    return 0;
}