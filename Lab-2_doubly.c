#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FoodNode {
    char foodName[50];
    int calories;
    struct FoodNode* next;
    struct FoodNode* prev;
};

struct CalorieCounterLinkedList {
    struct FoodNode* head;
    struct FoodNode* tail;
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
    newNode->prev = NULL;

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

    if (list->head == NULL) {
        // If the list is empty, the new node is both the head and the tail
        list->head = newNode;
        list->tail = newNode;
    } else {
        // Insert the new node at the end of the doubly linked list
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
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

    while (current != NULL) {
        // Check if the current node is the one to delete
        if (strcmp(current->foodName, name) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                // If the deleted node is the head, update the head
                list->head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                // If the deleted node is the tail, update the tail
                list->tail = current->prev;
            }

            printf("Food item '%s' deleted.\n", name);
            free(current);
            return;
        }

        current = current->next;
    }

    printf("Food item '%s' not found.\n", name);
}

void display(struct CalorieCounterLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct FoodNode* current = list->head;
    printf("Food items and their calorie counts:\n");

    while (current != NULL) {
        printf("%s: %d calories\n", current->foodName, current->calories);
        current = current->next;
    }
}

void destroyList(struct CalorieCounterLinkedList* list) {
    struct FoodNode* current = list->head;
    struct FoodNode* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    // Reset head and tail pointers to NULL
    list->head = NULL;
    list->tail = NULL;
}

int main() {
    struct CalorieCounterLinkedList calorieList;
    calorieList.head = NULL;
    calorieList.tail = NULL;

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
