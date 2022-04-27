#include <bits/stdc++.h>
using namespace std;

int peak(int arr[], int start, int end)
{
    int mid = (start + end) / 2;

    if (arr[mid] > arr[mid - 1])
    {
        return peak(arr, start, mid);
    }
    if (arr[mid] < arr[mid + 1])
    {
        return peak(arr, mid + 1, end);
    }
    return start;
}

int main()
{
    int arr[] = {3, 5, 3, 2, 0};
    // cout << arr.size() << endl;
    cout << peak(arr, 0, 4);
}