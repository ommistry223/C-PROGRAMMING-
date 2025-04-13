#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    
    // Target was not found
    return -1;
}

int main() {
    // Array must be sorted for binary search
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 23;
    
    printf("Searching for %d in array: ", target);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int result = binarySearch(arr, 0, n-1, target);
    
    if (result == -1) {
        printf("Element not found in the array\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    
    return 0;
}