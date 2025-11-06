
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Function declarations
void push(int);
void pop();
void display();
void checkPalindrome();
int isFull();
int isEmpty();

int main() {
    int choice, value;

    while (1) {
        printf("\n\n----- STACK OPERATIONS -----\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow/Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            checkPalindrome();
            break;

        case 4:
            if (isFull())
                printf("Stack Overflow!\n");
            else if (isEmpty())
                printf("Stack Underflow!\n");
            else
                printf("Stack is neither full nor empty.\n");
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// Push function
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// Pop function
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}

// Display function
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

// Palindrome check using stack
void checkPalindrome() {
    char str[100];
    char rev[100];
    int i, j;

    printf("Enter a string to check palindrome: ");
    scanf("%s", str);

    top = -1; // reset stack for character use
    int len = strlen(str);

    // Push all characters
    for (i = 0; i < len; i++) {
        stack[++top] = str[i];
    }

    // Pop to reverse
    for (i = 0; i < len; i++) {
        rev[i] = stack[top--];
    }
    rev[i] = '\0';

    if (strcmp(str, rev) == 0)
        printf("%s is a Palindrome.\n", str);
    else
        printf("%s is NOT a Palindrome.\n", str);
}
