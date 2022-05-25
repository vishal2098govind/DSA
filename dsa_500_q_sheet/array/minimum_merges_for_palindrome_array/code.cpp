#include <iostream>

using namespace std;

int minMergesForPalindrom(int arr[], int n)
{
    int merges = 0;
    for (int i = 0, j = n - 1; i + 1 < n && j - 1 >= 0 && i < j;)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        if (arr[i] < arr[j])
        {
            arr[i + 1] = arr[i] + arr[i + 1];
            i++;
            merges++;
        }
        if (arr[j] < arr[i])
        {
            arr[j - 1] = arr[j] + arr[j - 1];
            j--;
            merges++;
        }
    }
    return merges;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << minMergesForPalindrom(arr, n);
}