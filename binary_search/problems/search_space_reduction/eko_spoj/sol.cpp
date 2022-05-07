#include <iostream>
using namespace std;

int getMaxTreeHeight(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

bool isPossibleSawHeight(int arr[], int size, int sawHeight, int target)
{
    long long int lengthOfWoodCut = 0;

    for (int i = 0; i < size; i++)
    {
        int treeHeight = arr[i];

        int treeHeightCut = treeHeight - sawHeight;

        lengthOfWoodCut += treeHeightCut > 0 ? treeHeightCut : 0;
    }

    return lengthOfWoodCut >= target;
}

int getMaxSawHeight(int arr[], int size, int target)
{
    int minSawHeight = 0;
    int maxSawHeight = getMaxTreeHeight(arr, size);
    int ans = minSawHeight;

    while (minSawHeight < maxSawHeight)
    {
        int midSawHeight = (minSawHeight / 2) + (maxSawHeight / 2);

        if (isPossibleSawHeight(arr, size, midSawHeight, target))
        {
            minSawHeight = midSawHeight + 1;
            ans = midSawHeight > ans ? midSawHeight : ans;
        }
        else
        {
            maxSawHeight = midSawHeight - 1;
        }
    }
    return ans;
}

int main()
{
    int noOfTrees;
    cin >> noOfTrees;
    int targetWoodCount;
    cin >> targetWoodCount;

    int arr[noOfTrees];
    for (int i = 0; i < noOfTrees; i++)
    {
        cin >> arr[i];
    }

    int maxSawHeight = getMaxSawHeight(arr, noOfTrees, targetWoodCount);
    cout << maxSawHeight;
}