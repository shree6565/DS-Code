#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = 0;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    while (hashTable[index] != 0) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void search(int key) {
    int index = hash(key);
    int start = index;
    while (hashTable[index] != 0) {
        if (hashTable[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
    printf("Key %d not found!\n", key);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == 0)
            printf("[%d] : NULL\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key;
    initialize();
    while (1) {
        printf("\n===== HASHING MENU =====\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
