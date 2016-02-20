#include <cstdio>
#include <climits>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int* arr, int size) {
    int index;
    for (index = 0; index < size; ++index) {
        printf("%d ", arr[index]);
    }
    printf("\n");
}

void bubbleSort(int* arr, int size) {
    int i, j;
    bool swapped;

    for (i = 0; i < size - 1; ++i) {
        swapped = false;
        
        for (j = 0; j < size - i - 1; ++j) {

            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
            // printArray(arr, size);
        }

        if (!swapped) 
            break;
    }
}

void insertionSort(int* arr, int size) {
    int i, j;

    for (i = 1; i < size; i++) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                swap(&arr[j], &arr[i]);
            }
            // printArray(arr, size);
        }
    }
}

void selectionSort(int* arr, int size) {
    int i, j, minIndex;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (i != minIndex)
            swap(&arr[i], &arr[minIndex]);
        
        // printArray(arr, size);
    }
}

// Iterative Binary Search
int binarySearch(int* arr, int lIndex, int uIndex, int key) {
    
    while (uIndex >= lIndex) {
        int mIndex = lIndex + (uIndex - lIndex) / 2;
        if (arr[mIndex] == key)
            return mIndex;

        if (arr[mIndex] > key)
            uIndex = mIndex - 1;
        else
            lIndex = mIndex + 1;
    }
    
    return -1;    
}

// Recursive Binary Search
// int binarySearch(int* arr, int lIndex, int uIndex, int key) {
//     if (lIndex > uIndex)
//         return -1;

//     int mIndex = lIndex + (uIndex - lIndex) / 2;
//     if (arr[mIndex] == key)
//         return mIndex;
//     else if (arr[mIndex] > key)
//         return binarySearch(arr, lIndex, mIndex - 1, key);
//     else
//         return binarySearch(arr, mIndex + 1, uIndex, key);
// }

void merge(int* arr, int lIndex, int mIndex, int uIndex) {

    int i, j, k;
    int n1 = mIndex - lIndex + 1;
    int n2 = uIndex - mIndex;

    int L[n1+1], R[n2+1];

    // Copy elements
    for (i = 0; i < n1; i++)
        L[i] = arr[lIndex + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mIndex + j + 1];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    // printArray(L, n1);
    // printArray(R, n2);

    j = k = 0;
    for (i = lIndex; i <= uIndex; i++) {
        if (L[j] <= R[k]) {
            arr[i] = L[j];
            j++;
        } else {
            arr[i] = R[k];
            k++;
        }
    }
}

void mergeSort(int* arr, int lIndex, int uIndex) {
    if (lIndex < uIndex) {
        int mIndex = lIndex + (uIndex - lIndex) / 2;
        mergeSort(arr, lIndex, mIndex);
        mergeSort(arr, mIndex + 1, uIndex);
        merge(arr, lIndex, mIndex, uIndex);
    }
}

int main() {
    
    int arr[] = {4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);

    // bubbleSort(arr, size);
    // insertionSort(arr, size);
    // selectionSort(arr, size);
    mergeSort(arr, 0, size - 1);

    // int foundIndex = binarySearch(arr, 0, size - 1, 3);
    // printf("%d\n", foundIndex);

    printf("Sorted array is: \n");
    printArray(arr, size);

    return 0;
}