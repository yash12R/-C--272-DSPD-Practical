#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float avg;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n], temp;

    // Input details
    for (int i = 0; i < n; i++) {
        printf("\nEnter name, roll number, and average marks of student %d: ", i + 1);
        scanf("%s %d %f", s[i].name, &s[i].roll, &s[i].avg);
    }

    // Bubble sort (descending order by avg)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].avg < s[j + 1].avg) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Display sorted list
    printf("\nStudents sorted by average marks (Descending):\n");
    printf("Name\tRoll\tAverage\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll, s[i].avg);
    }

    return 0;
}
