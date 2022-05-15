#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string isSubset(vector<int> &a1, vector<int> &a2, int n, int m)
{
    if (m > n)
        return "No";
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    int i = 0, j = 0;
    for (; i < n && j < m;)
    {
        if (a1[i] != a2[j])
        {
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }

    if (j == m)
        return "Yes";
    return "No";
}

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> a1;
    vector<int> a2;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        a1.push_back(in);
    }
    for (int i = 0; i < m; i++)
    {
        int in;
        cin >> in;
        a2.push_back(in);
    }

    cout << isSubset(a1, a2, n, m);
}