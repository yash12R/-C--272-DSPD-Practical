#include <stdio.h>

// Function to perform Binary Search
int* binarySearch(int arr[], int size, int key) {
    if (arr == NULL || size == 0) {
        printf("Search list is empty or null.\n");
        return NULL;
    }

    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        printf("Examining value %d at index %d\n", arr[mid], mid);

        if (arr[mid] == key) {
            printf("Value found at index %d!\n", mid);
            return &arr[mid]; // returning pointer to found element
        }
        else if (key > arr[mid]) {
            printf("Target greater than midpoint, moving start to index %d\n", mid + 1);
            start = mid + 1;
        }
        else {
            printf("Target less than midpoint, moving end to index %d\n", mid - 1);
            end = mid - 1;
        }
    }

    printf("Value not found in list.\n");
    return NULL;
}

int main() {
    int arr[50], n, key;
    int *result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if (result != NULL)
        printf("\nResult: Element %d found.\n", *result);
    else
        printf("\nResult: Element not found.\n");

    return 0;
}
