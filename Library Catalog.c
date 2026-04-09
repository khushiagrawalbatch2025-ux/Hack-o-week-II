#include <stdio.h>
#include <string.h>

#define MAX 5

// Structure
struct Book {
    int id;
    char title[50];
    char author[50];
};

struct Book library[MAX];
int count = 0;

// Add Book
void addBook() {
    if (count == MAX) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);
    getchar();

    printf("Enter Title: ");
    fgets(library[count].title, 50, stdin);
    library[count].title[strcspn(library[count].title, "\n")] = 0;

    printf("Enter Author: ");
    fgets(library[count].author, 50, stdin);
    library[count].author[strcspn(library[count].author, "\n")] = 0;

    count++;
    printf("Book Added Successfully!\n");
}

// Display Books
void displayBooks() {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nBook List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Title: %s | Author: %s\n",
               library[i].id, library[i].title, library[i].author);
    }
}

// Search by Title
void searchBook() {
    char title[50];
    getchar();

    printf("Enter title to search: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Book Found!\n");
            printf("ID: %d | Title: %s | Author: %s\n",
                   library[i].id, library[i].title, library[i].author);
            return;
        }
    }

    printf("Book not found.\n");
}

// Remove Book
void removeBook() {
    int id, found = 0;

    printf("Enter Book ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            found = 1;

            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }

            count--;
            printf("Book removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Main
int main() {
    int choice;

    do {
        printf("\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Remove Book\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: removeBook(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
