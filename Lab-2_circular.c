#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FoodNode {
    char foodName[50];
    int calories;
    struct FoodNode* next;
};

struct CalorieCounterLinkedList {
    struct FoodNode* head;
};

struct FoodNode* createNode(char name[], int cal) {
    struct FoodNode* newNode = (struct FoodNode*)malloc(sizeof(struct FoodNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->foodName, name);
    newNode->calories = cal;
    newNode->next = NULL;

    return newNode;
}

void insert(struct CalorieCounterLinkedList* list) {
    char name[50];
    int cal;

    printf("Enter food name: ");
    scanf("%s", name);
    printf("Enter calories: ");
    scanf("%d", &cal);

    struct FoodNode* newNode = createNode(name, cal);

    // If the list is empty, make the node point to itself
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;
    } else {
        // Insert the new node at the beginning of the circular list
        newNode->next = list->head->next;
        list->head->next = newNode;
        list->head = newNode; // Update the head to the new node
    }

    printf("Food item '%s' with %d calories added.\n", name, cal);
}

void deleteFoodItem(struct CalorieCounterLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    char name[50];
    printf("Enter the name of the food item to delete: ");
    scanf("%s", name);

    struct FoodNode* current = list->head;
    struct FoodNode* prev = NULL;

    do {
        prev = current;
        current = current->next;

        // Check if the current node is the one to delete
        if (strcmp(current->foodName, name) == 0) {
            prev->next = current->next;

            // If the deleted node is the head, update the head
            if (list->head == current) {
                list->head = prev;
            }

            printf("Food item '%s' deleted.\n", name);
            free(current);
            return;
        }
    } while (current != list->head);

    printf("Food item '%s' not found.\n", name);
}

void display(struct CalorieCounterLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct FoodNode* current = list->head->next; // Start from the first node
    printf("Food items and their calorie counts:\n");

    do {
        printf("%s: %d calories\n", current->foodName, current->calories);
        current = current->next;
    } while (current != list->head->next); // Stop when we reach the starting node

}

void destroyList(struct CalorieCounterLinkedList* list) {
    if (list->head == NULL) {
        return;
    }

    struct FoodNode* current = list->head->next; // Start from the first node
    struct FoodNode* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != list->head->next); // Stop when we reach the starting node

    free(list->head); // Free the head node
}

int main() {
    struct CalorieCounterLinkedList calorieList;
    calorieList.head = NULL;

    int choice;

    do {
        printf("\nCalorie Counter Menu:\n");
        printf("1. Add Food Item\n");
        printf("2. Delete Food Item\n");
        printf("3. Display Calorie Counter\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(&calorieList);
                break;
            case 2:
                deleteFoodItem(&calorieList);
                break;
            case 3:
                display(&calorieList);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Freeing memory
    destroyList(&calorieList);

    return 0;
}
