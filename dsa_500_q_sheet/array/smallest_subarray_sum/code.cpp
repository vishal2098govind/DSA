#include <iostream>

using namespace std;

int smallestSubWithSum(int arr[], int n, int x)
{
    int mini = INT_MAX;
    int sum = 0;
    int start = 0, end = 0;
    while (end < n)
    {
        while (sum <= x && end < n)
        {
            sum += arr[end++];
        }
        while (sum > x && start < n)
        {
            mini = min(mini, end - start);
            sum -= arr[start++];
        }
    }

    return mini;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << smallestSubWithSum(arr, n, m);
}