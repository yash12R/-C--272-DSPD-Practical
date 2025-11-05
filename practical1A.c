#include <stdio.h>

int main() {
    int n, i;
    int sum_even = 0, sum_odd = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)  // position is even (since array index starts at 0)
            sum_even += arr[i];
        else                    // position is odd
            sum_odd += arr[i];
    }

    printf("\nSum of numbers at odd positions: %d", sum_odd);
    printf("\nSum of numbers at even positions: %d\n", sum_even);

    return 0;
}
