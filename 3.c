#include <stdio.h>
#include <stdlib.h>
#define MAX 5   // Maximum size of the queue

char queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the queue
void insert() {
    char item;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter character to insert: ");
    scanf(" %c", &item);

    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = item;
    printf("Inserted '%c' into the queue.\n", item);
}

// Function to delete an element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! Nothing to delete.\n");
        return;
    }

    printf("Deleted '%c' from the queue.\n", queue[front]);
    front++;

    if (front > rear)
        front = rear = -1; // Reset queue when it becomes empty
}

// Function to display queue elements
void display() {
    if (front == -1) {
        printf("\nQueue is Empty.\n");
        return;
    }

    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%c ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n===== QUEUE OPERATIONS MENU =====\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
