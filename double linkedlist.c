#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node*next;
    struct Node*prev;
};

struct Node*head = NULL;

void insertElement(int value) {
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node*temp = head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}

void deleteNode(int pos) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node*temp = head;
    if(pos==1) {
        head = temp->next;
        if(head!=NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    for(int i=1; i<pos && temp!=NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    if(temp->prev!=NULL) {
        temp->prev->next = temp->next;
    }
    if(temp->next!=NULL) {
        temp->next->prev=temp->prev;
    }
    free(temp);
}

void display() {
    struct Node*temp = head;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while(temp !=NULL) {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;
    while(1) {
        printf("\n----Doubly Linked List Menu----\n");
        printf("1. Insert Element\n");
        printf("2. Delete Node (by position)\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d",&value);
            insertElement(value);
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d",&pos);
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
