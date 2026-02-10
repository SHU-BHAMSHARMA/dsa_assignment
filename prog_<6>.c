#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swapElements(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Logic to maintain the Max Heap property
void maxHeapProperty(int arr[], int size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swapElements(&arr[i], &arr[largest]);
        maxHeapProperty(arr, size, largest);
    }
}

// Logic to maintain the Min Heap property
void minHeapProperty(int arr[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] < arr[smallest])
        smallest = l;

    if (r < size && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swapElements(&arr[i], &arr[smallest]);
        minHeapProperty(arr, size, smallest);
    }
}

// Build Max Heap from an unsorted array
void buildMaxHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapProperty(arr, size, i);
    }
}

// Build Min Heap from an unsorted array
void buildMinHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapProperty(arr, size, i);
    }
}

void displayHeap(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        temp[i] = arr[i];
    }

    buildMaxHeap(arr, n);
    printf("Max Heap: ");
    displayHeap(arr, n);

    buildMinHeap(temp, n);
    printf("Min Heap: ");
    displayHeap(temp, n);

    free(arr);
    free(temp);
    return 0;
}
