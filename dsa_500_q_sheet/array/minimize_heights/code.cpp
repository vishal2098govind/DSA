#include <iostream>
#include <algorithm>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{

    sort(arr, arr + n);
    int max_ele = arr[n - 1] - k;
    int min_ele = arr[0] + k;
    int res = max_ele - min_ele;

    for (int i = 1; i < n; i++)
    {
        max_ele = max(arr[n - 1] - k, arr[i - 1] + k);
        min_ele = min(arr[0] + k, arr[i] - k);
        if (min_ele < 0)
            continue;
        res = min(res, max_ele - min_ele);
    }
    return res;
}

int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = getMinDiff(a, n, k);
    cout << ans;
}