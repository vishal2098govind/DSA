#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key, int start, int end)
{
    int mid = (start + end) / 2;
    cout << end << endl;

    if (start > end)
    {
        return -1;
    }

    if (key == arr[mid])
    {
        return mid;
    }

    if (key < arr[mid])
    {
        // search for key in left
        return binarySearch(arr, key, start, mid - 1);
    }
    else
    {
        // search for key in right
        return binarySearch(arr, key, mid + 1, end);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    cout << sizeof(arr) << endl
         << sizeof(arr[0]) << endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n << endl;

    cout << binarySearch(arr, 4, 0, n - 1);
}