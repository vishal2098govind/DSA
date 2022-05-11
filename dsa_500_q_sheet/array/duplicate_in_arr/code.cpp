#include <iostream>
using namespace std;

int findDuplicateBinarySearch(int nums[], int n)
{
    int maxN = nums[0];
    for (int i = 0; i < n; i++)
    {
        maxN = max(maxN, nums[i]);
    }

    int start = 1;
    int end = maxN;
    int mid = start + (end - start) / 2;
    // Binary search on [1 to maxN]
    while (start < end)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= mid)
            {
                count++;
            }
        }

        if (count <= mid)
        {
            // => duplicate number is greater than mid
            start = mid + 1;
        }
        else
        {
            // => duplicate number is less than or equal to mid
            end = mid;
        }
        mid = start + (end - start) / 2;
    }

    return start;
}

int main()
{
    int arr[] = {1, 3, 4, 2, 2};
    int n = 5;
    int duplicates = findDuplicateBinarySearch(arr, n);
    cout << duplicates;
}