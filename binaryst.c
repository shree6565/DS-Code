#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* findMax(struct Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct Node* search(struct Node* root, int key) {
    while (root != NULL) {
        if (key == root->key)
            return root;
        else if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\nBST Operations:\n");
        printf("1. Insert\n");
        printf("2. Minimum\n");
        printf("3. Maximum\n");
        printf("4. Search\n");
        printf("5. Delete\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            if (root != NULL)
                printf("Minimum key: %d\n", findMin(root)->key);
            else
                printf("BST is empty.\n");
            break;
        case 3:
            if (root != NULL)
                printf("Maximum key: %d\n", findMax(root)->key);
            else
                printf("BST is empty.\n");
            break;
        case 4:
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (search(root, key) != NULL)
                printf("Key %d found.\n", key);
            else
                printf("Key %d not found.\n", key);
            break;
        case 5:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 6:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
