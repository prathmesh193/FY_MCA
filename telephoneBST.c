#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the BST
struct Node {
    char name[50];
    char phoneNumber[15];
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char name[], char phoneNumber[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phoneNumber, phoneNumber);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, char name[], char phoneNumber[]) {
    if (root == NULL) {
        return createNode(name, phoneNumber);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, phoneNumber);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, phoneNumber);
    }

    return root;
}

// Function to search for a name in the BST
struct Node* search(struct Node* root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

// Function to find the minimum value node in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}
// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, char name[]) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        root->left = deleteNode(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deleteNode(root->right, name);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        strcpy(root->name, temp->name);
        strcpy(root->phoneNumber, temp->phoneNumber);

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->name);
    }

    return root;
}

// Function to print the phone list using inorder traversal
void printPhoneList(struct Node* root) {
    if (root != NULL) {
        printPhoneList(root->left);
        printf("Name: %s, Phone Number: %s\n", root->name, root->phoneNumber);
        printPhoneList(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char name[50], phoneNumber[15];

    do {
        printf("\nPhone List Menu:\n");
        printf("1. Search for a name\n");
        printf("2. Insert a new name\n");
        printf("3. Delete an existing name\n");
        printf("4. Print the entire phone list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name to search: ");
                scanf("%s", name);
                struct Node* searchResult = search(root, name);
                if (searchResult != NULL) {
                    printf("Name: %s, Phone Number: %s\n", searchResult->name, searchResult->phoneNumber);
                } else {
                    printf("Name not found.\n");
                }
                break;
            case 2:
                printf("Enter the name to insert: ");
                scanf("%s", name);
                printf("Enter the phone number: ");
                scanf("%s", phoneNumber);
                root = insert(root, name, phoneNumber);
                printf("Name inserted successfully.\n");
                break;
            case 3:
                printf("Enter the name to delete: ");
                scanf("%s", name);
                root = deleteNode(root, name);
                printf("Name deleted successfully.\n");
                break;
            case 4:
                printf("Phone List:\n");
                printPhoneList(root);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
