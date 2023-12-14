#include <stdio.h>
#include <stdlib.h>

struct CarNode {
    char model[50];
    float price;
    char manufacturer[50];
    float engine_capacity;
    struct CarNode *prev;
    struct CarNode *next;
};

struct CarNode *head = NULL;

void displayCars() {
    struct CarNode *current = head;
    while (current != NULL) {
        printf("Model: %s, Price: %.2f, Manufacturer: %s, Engine Capacity: %.2f\n",
               current->model, current->price, current->manufacturer, current->engine_capacity);
        current = current->next;
    }
}

void insertCar() {
    struct CarNode *newCar = (struct CarNode *)malloc(sizeof(struct CarNode));

    printf("Enter model: ");
    scanf("%s", newCar->model);

    printf("Enter price: ");
    scanf("%f", &newCar->price);

    printf("Enter manufacturer: ");
    scanf("%s", newCar->manufacturer);

    printf("Enter engine capacity: ");
    scanf("%f", &newCar->engine_capacity);

    newCar->prev = NULL;
    newCar->next = NULL;

    if (head == NULL) {
        head = newCar;
    } else {
        struct CarNode *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCar;
        newCar->prev = current;
    }
}

// Add other functions (deleteCar, updateCar, queryByPriceRange, queryByModel, etc.) as needed

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Display Cars\n");
        printf("2. Insert Car\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCars();
                break;
            case 2:
                insertCar();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
