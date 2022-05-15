#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    long long mini = a[m - 1] - a[0];
    for (int i = 1; i + m - 1 < n; i++)
    {
        mini = min(mini, a[i + m - 1] - a[i]);
    }
    return mini;
}

int main()
{
    long long n;
    long long x;
    cin >> n;
    vector<long long> a;
    for (long long i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    long long m;
    cin >> m;
    cout << findMinDiff(a, n, m);
}