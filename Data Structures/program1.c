#include <stdio.h>
#include <stdlib.h>

// A function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// A modified binary search function that returns
// the first occurrence of x in given array arr[l..r]
int binarySearchFirstOccurrence(int arr[], int l, int r, int x) {
    if (r < l)
        return -1;

    int mid = l + (r - l) / 2;

    if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
        return mid;
    else if (x > arr[mid])
        return binarySearchFirstOccurrence(arr, mid + 1, r, x);
    else
        return binarySearchFirstOccurrence(arr, l, mid - 1, x);
}

// Driver code
int main() {
    int arr[] = { 4, 7, 3, 2, 1, 7, 9, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    // Find the first occurrence of x
    int firstOccurrenceIndex = binarySearchFirstOccurrence(arr, 0, n - 1, x);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the first occurrence of x
    if (firstOccurrenceIndex != -1)
        printf("First occurrence of %d is at index %d\n", x, firstOccurrenceIndex);
    else
        printf("%d is not present in the array\n", x);

    return 0;
}


