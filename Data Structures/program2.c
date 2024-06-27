#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function to use the first element as the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // pivot
    int left = low + 1;
    int right = high;

    while (1) {
        // Move the left pointer to the right as long as the elements are less than pivot
        while (left <= right && arr[left] <= pivot) {
            left++;
        }
        // Move the right pointer to the left as long as the elements are greater than pivot
        while (left <= right && arr[right] > pivot) {
            right--;
        }
        // If the left pointer crosses the right pointer, break the loop
        if (left > right) {
            break;
        }
        // Swap the elements at the left and right pointers
        swap(&arr[left], &arr[right]);
    }
    // Swap the pivot element with the element at the right pointer
    swap(&arr[low], &arr[right]);
    return right;
}

// The main QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);
        // Recursively sort the subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test the above functions
int main() {
    int arr[] = {5, 3, 1, 6, 0, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}


