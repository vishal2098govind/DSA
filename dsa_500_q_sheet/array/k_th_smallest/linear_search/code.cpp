#include <iostream>

using namespace std;

int getMin(int arr[], int size, int current_min)
{
    int mini = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] <= current_min)
        {
            continue;
        }

        mini = min(arr[i], mini);
    }
    return mini;
}

int getKthSmallest(int arr[], int size, int k)
{
    int mini = INT_MIN;

    for (int small = 1; small <= k; small++)
    {
        mini = getMin(arr, size, mini);
    }

    return mini;
}

int main()
{
    int arr[] = {7, 10, 4, 20, 15};

    int size = 5;

    int k = 4;

    cout << k << "th smallest is: " << getKthSmallest(arr, size, k);
}