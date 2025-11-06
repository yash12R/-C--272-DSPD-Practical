#include <stdio.h>

#define SIZE 7  // Hash table size

int hash(int key) {
    return key % SIZE;  // Hash function h(k) = k mod 7
}

void insert(int table[], int key) {
    int index = hash(key);
    int originalIndex = index;
    int i = 0;

    // Linear probing to find empty slot
    while (table[index] != -1) {
        index = (originalIndex + ++i) % SIZE;
        if (index == originalIndex) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }

    table[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void display(int table[]) {
    printf("\nFinal Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] != -1)
            printf("Slot %d -> %d\n", i, table[i]);
        else
            printf("Slot %d -> EMPTY\n", i);
    }
}

int main() {
    int table[SIZE];
    int n, key;

    // Initialize all slots to -1 (empty)
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(table, key);
    }

    display(table);

    return 0;
}
