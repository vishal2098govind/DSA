#include <iostream>

using namespace std;

void shift(int arr[], int n, int fp, int i)
{
    for (; i - 1 >= fp; i--)
    {
        arr[i] = arr[i - 1];
    }
}

void rearrange(int arr[], int n)
{
    int fp = 0; // first-positive index or left-most-positive index
    for (int i = 0; i < n; i++)
    {
        if (arr[fp] < 0)
        {
            fp++;
            continue;
        }
        else
        {
            if (arr[i] < 0)
            {
                if (fp > 0 && arr[fp - 1] < 0)
                {
                    int temp = arr[i];
                    fp++;
                    shift(arr, n, fp, i);
                    arr[fp] = temp;
                    fp++;
                }
                else
                {
                    int temp = arr[i];
                    shift(arr, n, fp, i);
                    arr[fp] = temp;
                    fp++;
                }
            }
        }
    }

    if (arr[0] < 0 && arr[1] < 0)
    {
        int fn = 1; // first-negative index or left-most-negative index
        for (int i = 1; i < n; i++)
        {
            if (arr[fn] > 0)
            {
                fn++;
                continue;
            }
            else
            {
                if (arr[i] > 0)
                {
                    if (fn > 1 && arr[fn - 1] > 0)
                    {
                        int temp = arr[i];
                        fn++;
                        shift(arr, n, fn, i);
                        arr[fn] = temp;
                        fn++;
                    }
                    else
                    {
                        int temp = arr[i];
                        shift(arr, n, fn, i);
                        arr[fn] = temp;
                        fn++;
                    }
                }
            }
        }
    }
}

int main()
{
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    // int arr[] = {1, 2, 3, -4, -1, 4};
    // int n = 6;
    int n = 11;
    rearrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}