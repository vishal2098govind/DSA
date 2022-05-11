#include <iostream>
using namespace std;

void kadane(int a[], int n)
{
    int acc_sum = 0;
    int maxSum = a[0];
    int startingIndex = 0;
    int endingIndex = 0;
    for (int i = 0; i < n; i++)
    {
        acc_sum += a[i];
        if (acc_sum > maxSum)
        {
            endingIndex = i;
        }
        maxSum = max(maxSum, acc_sum);
        if (acc_sum < 0)
        {
            acc_sum = 0;
            startingIndex = i + 1;
        }
    }
    cout << "Max sum: " << maxSum << endl;
    cout << "Range: " << (startingIndex >= n ? 0 : startingIndex) << ", " << endingIndex << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    kadane(a, n);
}