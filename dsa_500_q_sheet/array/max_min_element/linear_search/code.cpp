#include <iostream>
using namespace std;

pair<int, int> getMaxMin(int arr[], int size)
{
    pair<int, int> pair;
    if (size == 1)
    {
        pair.second = pair.first = arr[0];
        return pair;
    }
    pair.second = arr[0];
    pair.first = arr[0];
    for (int i = 0; i < size; i++)
    {
        pair.second = max(pair.second, arr[i]);
        pair.first = min(pair.first, arr[i]);
    }
    return pair;
}

int main()
{
    int arr[] = {
        1000,
        11,
        445,
        1,
        330,
        3000,
    };

    int size = 6;

    pair<int, int> maxMinPair = getMaxMin(arr, size);

    cout << "Min: " << maxMinPair.first << ", Max: " << maxMinPair.second;
}