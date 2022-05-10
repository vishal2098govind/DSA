#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int numberToSort = arr[i];
        int j = i - 1;
        // shift till we reach a number < numberToSort
        // while(arr[j]<numberToSort) shift
        for (; j >= 0; j--)
        {
            if (arr[j] > numberToSort)
            {
                arr[j + 1] = arr[j]; // shifting
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = numberToSort;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    insertionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}