#include <iostream>
#include <algorithm>

using namespace std;

int countOccrences(int arr[], int i, int N, int key)
{
    // arr must be sorted

    // Log(n) (Uses binary search)
    // Gives first occurance of key or
    // Gives greatest number which is smaller than key
    int *lowerBound = lower_bound(arr + i, arr + N, key);

    // Log(n) (Uses binary search)
    // Gives smallest number which is greater than key
    int *upperBound = upper_bound(arr + i, arr + N, key);
    cout << "Lower bound" << lowerBound - arr << endl;
    cout << "Upper bound" << upperBound - arr << endl;
    cout << "Number of occurrances of " << key << " is " << upperBound - lowerBound << endl;
    return upperBound - lowerBound;
}

int countPairs(int arr[], int N, int sum)
{
    sort(arr, arr + N);
    int pairs = 0;
    for (int i = 0; i < N; i++)
    {
        pairs += countOccrences(arr, i + 1, N, sum - arr[i]);
    }
    return pairs;
}

int main()
{
    int arr[] = {1, 1, 1, 1};
    int N = 4;
    int pairs = countPairs(arr, 4, 2);
    cout << "Pairs: " << pairs << endl;
}