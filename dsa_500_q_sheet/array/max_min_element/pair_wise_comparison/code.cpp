#include <iostream>
using namespace std;

pair<int, int> getMaxMin(int a[], int n)
{
    pair<int, int> pair;
    if (n == 1)
    {
        pair.first = pair.second = a[0];
        return pair;
    }
    bool isEvenSize = n % 2 == 0;

    pair.first = min(a[0], isEvenSize ? a[1] : a[0]);
    pair.second = max(a[0], isEvenSize ? a[1] : a[0]);
    for (int i = isEvenSize ? 2 : 1; i + 1 < n; i++)
    {
        pair.first = min(min(pair.first, a[i]), a[i + 1]);
        pair.second = max(max(pair.second, a[i]), a[i + 1]);
    }
    return pair;
}

int main()
{
    int arr[] = {
        1000,
        11,
        // 445,
        // 1,
        // 330,
        // 3000,
    };

    int size = 2;

    pair<int, int> maxMinPair = getMaxMin(arr, size);

    cout << "Min: " << maxMinPair.first << ", Max: " << maxMinPair.second;
}