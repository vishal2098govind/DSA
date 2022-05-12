#include <iostream>
#include <algorithm>
using namespace std;

int findMinIndexInRange(vector<int> &arr, int from, int x, int y)
{
    int mini = from;
    for (int i = from; i < arr.size(); i++)
    {
        if (arr[i] > x && arr[i] < y)
        {
            if (arr[i] < arr[mini])
                mini = i;
        }
    }
    return mini;
}

void nextPermutation(vector<int> &arr)
{
    bool swapped = false;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (i - 1 >= 0)
        {
            if (arr[i - 1] < arr[i])
            {
                int minIndexInRightSide = i + 1 >= n ? i : findMinIndexInRange(arr, i + 1, arr[i - 1], arr[i]);
                swap(arr[i - 1], arr[minIndexInRightSide] > arr[i - 1] ? arr[minIndexInRightSide] : arr[i]);
                sort(arr.begin() + i, arr.end());
                swapped = true;
                break;
            }
        }
    }
    if (!swapped)
    {
        // given permutation is the last permutation, thus return 1st permutation with given numbers
        sort(arr.begin(), arr.end());
    }
}

int main()
{
    vector<int> arr = {3, 2, 1};

    nextPermutation(arr);
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
}