### <p align="center"> INTRODUCTION </p>

This program generates a list of N random integers and performs sorting using one of four user-selected algorithms: Bubble Sort, Selection Sort, Insertion Sort, or Merge Sort. Beyond sorting, it provides empirical data by counting the exact number of comparisons and data movements (swaps) performed during execution.

---

### <p align="center"> DATA STRUCTURE USED </p>

The program primarily uses a Dynamic Array to store the integers.
- *int arr: A pointer used to allocate a block of memory based on user-defined size $N$.
- Global Counters: Two long variables are used to track performance metrics across recursive calls.

---

### <p align="center"> FUNCTIONS USED </p>

- bubbleSort / selectionSort / insertionSort

These functions implement the standard O(N^2) sorting logics. They are modified to increment the comparisons and swaps counters every time elements are compared or moved.

- mergeSort(int arr[], int l, int r)

A divide-and-conquer algorithm with O(N \log N) complexity. It recursively splits the array and uses the merge=() function to combine them in sorted order while tracking metrics.

- printArray(int arr[], int n)

Iterates through the array and prints the randomly generated or sorted integers to the console for verification.

---

### <p align="center"> WORKING ALGORITHM </p>

- Initialization: The user provides $N$. The program seeds the random number generator and populates the array with values between 1 and 1000.

- Selection: The user selects a sorting strategy from the menu.Execution: The chosen function runs, updating global counters for every comparison and swap operation.

- Reporting: The program prints the final sorted array along with the total counts for comparisons and swaps.

---

<p align="center"> SAMPLE OUTPUT </p>
Input: $N = 10, Choice = Bubble Sort

Before Sorting: 452 12 890 34 1 ...

After Sorting: 1 12 34 452 890 ...

Total Comparisons: 45Total Swaps: 22
