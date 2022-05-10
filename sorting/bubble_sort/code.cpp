#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = 5;

    bubbleSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}