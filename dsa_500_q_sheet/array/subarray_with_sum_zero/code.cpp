#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_map<int, int> sumIndexMap;
    int sumArr[n];
    bool found = false;
    int startingIndex = 0;
    int endingIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            sumArr[i] = arr[i] + sumArr[i - 1];
            if (sumArr[i] != 0 && sumIndexMap.find(sumArr[i]) == sumIndexMap.end())
            {
                sumIndexMap[sumArr[i]] = i;
            }
            else
            {
                found = true;
                startingIndex = sumIndexMap[sumArr[i]] + sumArr[i] == 0 ? 0 : 1;
                endingIndex = i;
                break;
            }
        }
        else
        {
            sumArr[i] = arr[i];
            sumIndexMap[sumArr[i]] = i;
        }
    }

    cout << startingIndex << ", " << endingIndex << endl;

    return found;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int, int> sumMap;

    sumMap[9] = 1;
    cout << (sumMap.find(9) == sumMap.end());
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool exists = subArrayExists(arr, n);
    cout << exists;
}