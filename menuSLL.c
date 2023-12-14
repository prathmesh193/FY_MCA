#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* create();
void display(struct Node* head);
struct Node* insert(struct Node* head, int value);
struct Node* deleteNode(struct Node* head, int value);
struct Node* search(struct Node* head, int value);
struct Node* reverse(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        // Display menu
        printf("\nLinked List Operations\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Search\n");
        printf("6. Reverse\n");
        printf("0. Exit\n");

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = create();
                printf("Linked list created successfully.\n");
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insert(head, value);
                printf("%d inserted successfully.\n", value);
                break;

            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                printf("%d deleted successfully.\n", value);
                break;

            case 5:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                struct Node* searchResult = search(head, value);
                if (searchResult != NULL)
                    printf("%d found in the list.\n", value);
                else
                    printf("%d not found in the list.\n", value);
                break;

            case 6:
                head = reverse(head);
                printf("Linked list reversed successfully.\n");
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to create a linked list
struct Node* create() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;
    int value;

    // Get values from the user until -1 is entered
    while (1) {
        printf("Enter a value (-1 to stop): ");
        scanf("%d", &value);

        if (value == -1)
            break;

        // Create a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        // If it's the first node, set it as the head
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            // Otherwise, link the new node to the previous one
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a value into the linked list
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to delete a node with a given value from the linked list
struct Node* deleteNode(struct Node* head, int value) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%d not found in the list.\n", value);
        return head;
    }

    if (previous == NULL) {
        // If the node to be deleted is the head
        head = head->next;
    } else {
        // If the node to be deleted is not the head
        previous->next = current->next;
    }

    free(current);
    return head;
}

// Function to search for a value in the linked list
struct Node* search(struct Node* head, int value) {
    while (head != NULL) {
        if (head->data == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to reverse the linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}