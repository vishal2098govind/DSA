#include <iostream>
using namespace std;

int findMinIndex(int arr[], int size, int startingIndex)
{
    int mini = startingIndex;
    for (int i = startingIndex; i < size; i++)
    {
        if (arr[i] < arr[mini])
        {
            mini = i;
        }
    }

    return mini;
}

void shift(int arr[], int indexToShift, int destinationIndex)
{
    int elementToShift = arr[indexToShift];
    for (int i = indexToShift; i > destinationIndex; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[destinationIndex] = elementToShift;
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min_index = findMinIndex(arr, size, i);
        // swap(arr[i], arr[min_index]); // this will make selection sort non-stable sorting algorithm
        shift(arr, min_index, i); // shifting instead of swapping will make selection sort a stable sorting algorithm
    }
}

int main()
{
    int arr[] = {10, 20, 20, 30, 10};
    int size = 5;

    selectionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}