#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

void insertElement(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if(head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        struct node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void deleteNode(int pos) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;

    if(pos == 1) {
        head = temp->next;
        if(head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    for(int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void display() {
    struct node* temp = head;

    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;
    while(1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Node (by position)\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertElement(value);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteNode(pos);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
