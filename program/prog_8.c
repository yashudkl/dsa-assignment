#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables to count comparisons and swaps
long long comparisons = 0;
long long swaps = 0;

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to print array
void printArray(int arr[], int n) {
    int i;
    int count = 0;
    
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        count++;
        if (count % 20 == 0) {  // Print 20 numbers per line for better readability
            printf("\n");
        }
    }
    if (count % 20 != 0) {
        printf("\n");
    }
}

// Function to generate random numbers
void generateRandomNumbers(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;  // Random number between 1 and 1000
    }
}

int main() {
    int n, choice;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Get the number of elements from user
    printf("Enter the number of random integers (N): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid input! N must be a positive integer.\n");
        return 1;
    }
    
    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    int *original = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL || original == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Generate random numbers
    generateRandomNumbers(arr, n);
    
    // Copy array to preserve original for display
    int i;
    for (i = 0; i < n; i++) {
        original[i] = arr[i];
    }
    
    // Display menu for sorting algorithm
    printf("\n========================================\n");
    printf("Choose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("========================================\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    // Print numbers before sorting
    printf("\n========================================\n");
    printf("Numbers BEFORE sorting:\n");
    printf("========================================\n");
    printArray(original, n);
    
    // Reset counters
    comparisons = 0;
    swaps = 0;
    
    // Sort based on user's choice
    printf("\n========================================\n");
    switch (choice) {
        case 1:
            printf("Sorting using Bubble Sort...\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("Sorting using Selection Sort...\n");
            selectionSort(arr, n);
            break;
        case 3:
            printf("Sorting using Insertion Sort...\n");
            insertionSort(arr, n);
            break;
        case 4:
            printf("Sorting using Merge Sort...\n");
            mergeSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice!\n");
            free(arr);
            free(original);
            return 1;
    }
    
    // Print numbers after sorting
    printf("========================================\n");
    printf("Numbers AFTER sorting:\n");
    printf("========================================\n");
    printArray(arr, n);
    
    // Display statistics
    printf("\n========================================\n");
    printf("Sorting Statistics:\n");
    printf("========================================\n");
    printf("Total Comparisons: %lld\n", comparisons);
    
    if (choice == 4) {
        printf("Total Swaps: N/A (Merge Sort uses array copying)\n");
    } else {
        printf("Total Swaps: %lld\n", swaps);
    }
    printf("========================================\n");
    
    // Free allocated memory
    free(arr);
    free(original);
    
    return 0;
}