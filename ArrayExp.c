#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function Prototypes
void insert(int arr[], int *n);
void deleteElement(int arr[], int *n);
void display(int arr[], int n);
void search(int arr[], int n);
void update(int arr[], int n);

int main() {
    int arr[MAX];
    int  n= 0, choice;

    printf("Enter initial number of elements (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || n < 0) {
        printf("Invalid size!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n=== ARRAY OPERATIONS MENU ===\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Search Element\n");
        printf("5. Update Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(arr, &n); break;
            case 2: deleteElement(arr, &n); break;
            case 3: display(arr, n); break;
            case 4: search(arr, n); break;
            case 5: update(arr, n); break;
            case 6: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Insert element at a specific position
void insert(int arr[], int *n) {
    if (*n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    int pos, val;
    printf("Enter position to insert (0 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    (*n)++;

    printf("Element inserted successfully.\n");
}

// Delete element at a specific position
void deleteElement(int arr[], int *n) {
    if (*n == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    int pos;
    printf("Enter position to delete (0 to %d): ", *n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully.\n");
}

// Display array elements
void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Search for an element in the array
void search(int arr[], int n) {
    int val, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);

    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Element found at position %d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Element not found.\n");
    }
}

// Update element at a specific position
void update(int arr[], int n) {
    int pos, val;
    printf("Enter position to update (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &val);

    arr[pos] = val;

    printf("Element updated successfully.\n");
}
