#include <iostream>
using namespace std;

#define MAX 100

// Function Prototypes
void insert(int arr[], int &n);
void deleteElement(int arr[], int &n);
void display(const int arr[], int n);
void search(const int arr[], int n);
void update(int arr[], int n);


int main() {
    int arr[MAX];
    int n = 0, choice;

    cout << "Enter initial number of elements (max " << MAX << "): ";
    cin >> n;

    if (n > MAX || n < 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }

    do {
        cout << "\n=== ARRAY OPERATIONS MENU ===\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display Array\n";
        cout << "4. Search Element\n";
        cout << "5. Update Element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert(arr, n); break;
            case 2: deleteElement(arr, n); break;
            case 3: display(arr, n); break;
            case 4: search(arr, n); break;
            case 5: update(arr, n); break;
            case 6: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Insert element at a specific position
void insert(int arr[], int &n) {
    if (n >= MAX) {
        cout << "Array is full. Cannot insert.\n";
        return;
    }

    int pos, val;
    cout << "Enter position to insert (0 to " << n << "): ";
    cin >> pos;

    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }

    cout << "Enter value to insert: ";
    cin >> val;

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    n++;

    cout << "Element inserted successfully.\n";
}

// Delete element at a specific position
void deleteElement(int arr[], int &n) {
    if (n == 0) {
        cout << "Array is empty. Cannot delete.\n";
        return;
    }

    int pos;
    cout << "Enter position to delete (0 to " << n - 1 << "): ";
    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Element deleted successfully.\n";
}

// Display array elements
void display(const int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Search for an element in the array
void search(const int arr[], int n) {
    int val;
    bool found = false;

    cout << "Enter value to search: ";
    cin >> val;

    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Element found at position " << i << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Element not found.\n";
    }
}

// Update element at a specific position
void update(int arr[], int n) {
    int pos, val;

    cout << "Enter position to update (0 to " << n - 1 << "): ";
    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }

    cout << "Enter new value: ";
    cin >> val;

    arr[pos] = val;

    cout << "Element updated successfully.\n";
}
