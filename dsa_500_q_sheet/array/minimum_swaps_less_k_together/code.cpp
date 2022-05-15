#include <iostream>

using namespace std;

int minSwap(int arr[], int n, int k)
{
    int start = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            cnt++;
        }
    }
    if (cnt == 0)
        return 0;

    int end = 0;
    int mini = INT_MAX;
    int ct = 0;
    for (; end < n; end++)
    {

        if (arr[end] > k)
        {
            ct++;
        }
        if (end - start + 1 == cnt)
        {
            mini = min(ct, mini);
            if (arr[start] > k)
                ct--;
            start++;
        }
    }
    return mini;
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

    int k;
    cin >> k;
    cout << minSwap(arr, n, k);
}