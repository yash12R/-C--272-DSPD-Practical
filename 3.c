#include <stdio.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

// Function declarations
void insert(char);
void delete();
void display();
int isFull();
int isEmpty();

int main() {
    int choice;
    char ch;

    while (1) {
        printf("\n\n----- QUEUE OPERATIONS -----\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Demonstrate Overflow and Underflow\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter character to insert: ");
            scanf(" %c", &ch);
            insert(ch);
            break;

        case 2:
            delete();
            break;

        case 3:
            if (isFull())
                printf("Queue Overflow!\n");
            else if (isEmpty())
                printf("Queue Underflow!\n");
            else
                printf("Queue is neither full nor empty.\n");
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Insert element into queue
void insert(char ch) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert '%c'.\n", ch);
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = ch;
    printf("'%c' inserted into queue.\n", ch);
}

// Delete element from queue
void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }
    printf("'%c' deleted from queue.\n", queue[front++]);
    if (front > rear)
        front = rear = -1; // Reset queue when empty
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    for (int i = front; i <= rear; i++)
        printf("%c ", queue[i]);
    printf("\n");
}
