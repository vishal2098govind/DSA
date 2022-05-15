#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool find3Numbers(int A[], int n, int X)
{
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        int remainingTripletSum = X - A[i];
        for (int j = i + 1; j < n; j++)
        {
            int remainingSum = remainingTripletSum - A[j];
            bool found = binary_search(A + j + 1, A + n, remainingSum);
            if (found)
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int x;
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        arr[i] = in;
    }

    cout << find3Numbers(arr, n, x);
}