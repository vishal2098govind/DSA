#include <iostream>
using namespace std;

long long trappingWater(int arr[], int n)
{
    int lMaxI[n] = {0};
    int rMaxI[n] = {0};
    int lMax = 0;
    int rMax = arr[n - 1];

    for (int i = 0; i < n; i++)
    {
        lMaxI[i] = lMax;
        lMax = max(lMax, arr[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        rMaxI[i] = rMax;
        rMax = max(rMax, arr[i]);
    }
    cout << "L max array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << lMaxI[i] << " ";
    }
    cout << endl;
    cout << "R max array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rMaxI[i] << " ";
    }
    cout << endl;
    long long ans = 0;
    int trappedI[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min(lMaxI[i], rMaxI[i]))
        {
            trappedI[i] = 0;
        }
        else
        {
            trappedI[i] = min(lMaxI[i], rMaxI[i]) - arr[i];
        }
    }

    cout << "Trapped array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << trappedI[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        ans += trappedI[i];
    }

    return ans;
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
    long long ans = trappingWater(arr, n);
    cout << ans;
}