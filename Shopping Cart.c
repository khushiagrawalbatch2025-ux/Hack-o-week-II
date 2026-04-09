#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int id;
    char name[50];
    float price;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at head
void insertHead() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Item ID: ");
    scanf("%d", &newNode->id);
    getchar();

    printf("Enter Item Name: ");
    fgets(newNode->name, 50, stdin);
    newNode->name[strcspn(newNode->name, "\n")] = 0;

    printf("Enter Price: ");
    scanf("%f", &newNode->price);

    newNode->next = head;
    head = newNode;

    printf("Item added at head.\n");
}

// Insert at tail
void insertTail() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Item ID: ");
    scanf("%d", &newNode->id);
    getchar();

    printf("Enter Item Name: ");
    fgets(newNode->name, 50, stdin);
    newNode->name[strcspn(newNode->name, "\n")] = 0;

    printf("Enter Price: ");
    scanf("%f", &newNode->price);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Item added at tail.\n");
}

// Remove item by ID
void removeItem() {
    int id;
    printf("Enter Item ID to remove: ");
    scanf("%d", &id);

    struct Node *temp = head, *prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Item removed successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Item not found.\n");
}

// Display cart
void displayCart() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("Cart is empty.\n");
        return;
    }

    printf("\nShopping Cart:\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Price: %.2f\n",
               temp->id, temp->name, temp->price);
        temp = temp->next;
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n--- Shopping Cart Menu ---\n");
        printf("1. Add Item at Head\n");
        printf("2. Add Item at Tail\n");
        printf("3. Remove Item by ID\n");
        printf("4. Display Cart\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertHead(); break;
            case 2: insertTail(); break;
            case 3: removeItem(); break;
            case 4: displayCart(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
