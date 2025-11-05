#include <stdio.h>

// Function to perform binary search
int* binarySearch(int arr[], int n, int key) {
    if (arr == NULL || n == 0) {   // Check for null or empty list
        printf("Search list is empty or invalid.\n");
        return NULL;
    }

    int start = 0, end = n - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;

        printf("Checking middle index %d (value = %d)\n", mid, arr[mid]);

        if (arr[mid] == key) {
            printf("✅ Found %d at index %d\n", key, mid);
            return &arr[mid];  // return pointer to found element
        }
        else if (key > arr[mid]) {
            printf("Target %d > %d, moving start to index %d\n", key, arr[mid], mid + 1);
            start = mid + 1;  // adjust start
        }
        else {
            printf("Target %d < %d, moving end to index %d\n", key, arr[mid], mid - 1);
            end = mid - 1;    // adjust end
        }
    }

    printf(" %d not found in the list.\n", key);
    return NULL;
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &key);

    // Call search function
    int* result = binarySearch(arr, n, key);

    if (result == NULL)
        printf("Search returned NULL.\n");

    return 0;
}
