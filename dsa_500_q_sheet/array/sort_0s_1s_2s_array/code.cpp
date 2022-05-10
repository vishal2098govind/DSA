#include <iostream>
using namespace std;

void sortArray(int a[], int n)
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zeros++;
        }

        if (a[i] == 1)
        {
            ones++;
        }

        if (a[i] == 2)
        {
            twos++;
        }
    }
    int i = 0;
    while (zeros)
    {
        a[i] = 0;
        i++;

        zeros--;
    }
    while (ones)
    {
        a[i] = 1;
        i++;
        ones--;
    }
    while (twos)
    {
        a[i] = 2;
        i++;
        twos--;
    }
}

int main()
{
    int N = 5;
    int arr[] = {0, 2, 1, 2, 0};
    sortArray(arr, N);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}