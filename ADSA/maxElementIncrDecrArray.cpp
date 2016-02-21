// Find the maximum element in an array which is first increasing and then decreasing
// http://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/

#include <cstdio>

int findIndex(int* arr, int lIndex, int rIndex) {
    
    // Only one elemnt in arr[lIndex, rIndex]
    if (lIndex == rIndex)
        return lIndex;

    // Two elements in arr[lIndex, rIndex] & left one is greater
    if ((rIndex == lIndex + 1) && arr[lIndex] >= arr[rIndex])
        return lIndex;

    // Two elements in arr[lIndex, rIndex] & left one is smaller
    if ((rIndex == lIndex + 1) && arr[lIndex] <= arr[rIndex])
        return rIndex;

    int midIndex = (lIndex + rIndex) / 2;

    if (arr[midIndex] > arr[midIndex - 1] && arr[midIndex] > arr[midIndex + 1])
        return midIndex;

    if (arr[midIndex] > arr[midIndex - 1] && arr[midIndex] < arr[midIndex + 1])
        return findIndex(arr, midIndex + 1, rIndex);

    if (arr[midIndex] < arr[midIndex - 1] && arr[midIndex] > arr[midIndex + 1])
        return findIndex(arr, lIndex, midIndex - 1);

}

int main() {
    int arr[] = {1, 3, 50, 10, 9, 7, 6};
    int index = findIndex(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    printf("%d\n", arr[index]);
    return 0;
}