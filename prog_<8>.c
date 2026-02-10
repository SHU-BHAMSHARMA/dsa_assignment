#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long comparisons = 0;
long swaps = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
            swaps++; // Counting assignment as a swap metric
        }
        comparisons++; // Final failed while condition
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
        swaps++;
    }
    while (i < n1) { arr[k++] = L[i++]; swaps++; }
    while (j < n2) { arr[k++] = R[j++]; swaps++; }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, choice;
    printf("Enter number of elements (N): ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(0));
    for (int i = 0; i < n; i++) arr[i] = rand() % 1000 + 1;

    printf("\nBefore Sorting:\n");
    printArray(arr, n);

    printf("\nChoose Sort: 1.Bubble 2.Selection 3.Insertion 4.Merge\nChoice: ");
    scanf("%d", &choice);

    comparisons = 0; swaps = 0;
    if (choice == 1) bubbleSort(arr, n);
    else if (choice == 2) selectionSort(arr, n);
    else if (choice == 3) insertionSort(arr, n);
    else if (choice == 4) mergeSort(arr, 0, n - 1);

    printf("\nAfter Sorting:\n");
    printArray(arr, n);
    printf("\nTotal Comparisons: %ld\nTotal Swaps/Assignments: %ld\n", comparisons, swaps);

    free(arr);
    return 0;
}