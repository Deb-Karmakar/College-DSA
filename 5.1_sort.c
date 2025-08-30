#include <stdio.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void cocktailShakerSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void displayArray(int arr[], int n);

int main() {
    int n, choice, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], copy[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        // Keep a copy of original array before sorting
        for (i = 0; i < n; i++) {
            copy[i] = arr[i];
        }

        printf("\n--- Sorting Menu ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Cocktail Shaker Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(copy, n);
                printf("Sorted array using Bubble Sort:\n");
                displayArray(copy, n);
                break;
            case 2:
                cocktailShakerSort(copy, n);
                printf("Sorted array using Cocktail Shaker Sort:\n");
                displayArray(copy, n);
                break;
            case 3:
                insertionSort(copy, n);
                printf("Sorted array using Insertion Sort:\n");
                displayArray(copy, n);
                break;
            case 4:
                selectionSort(copy, n);
                printf("Sorted array using Selection Sort:\n");
                displayArray(copy, n);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Cocktail Shaker Sort (Bidirectional Bubble Sort)
void cocktailShakerSort(int arr[], int n) {
    int swapped = 1, start = 0, end = n - 1, i, temp;

    while (swapped) {
        swapped = 0;

        // Forward pass
        for (i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        end--;

        // Backward pass
        for (i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        start++;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Display array
void displayArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
