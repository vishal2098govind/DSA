#include <iostream>
#include <vector>
using namespace std;

int performMerge(int arr[], int aux[], int n, int s, int mid, int e)
{
    // int aux[n] = {};
    int invCount = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     aux[i] = arr[i];
    // }
    int i = s, k = s, j = mid;
    for (; i < mid && j <= e;)
    {
        if (arr[j] < arr[i])
        {
            // => all elements from arr+i to arr+mid are greater than arr[j] thus they all will be counted in invCount
            // thus add number of elements from i to mid which is mid-i
            invCount += mid - i; // KEY STEP
            aux[k] = arr[j];
            j++;
            k++;
        }
        else
        {
            aux[k] = arr[i];
            i++;
            k++;
        }
    }

    for (; j <= e; j++, k++)
    {
        aux[k] = arr[j];
    }
    for (; i < mid; i++, k++)
    {
        aux[k] = arr[i];
    }

    // for (int i = 0; i <= e; i++)
    // {
    //     arr[i] = aux[i];
    // }
    // for (int i = 0; i <= e; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // cout << endl;

    return invCount;
}

int sortFrom(int arr[], int aux[], int n, int s, int e)
{
    int invCount = 0;
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        invCount += sortFrom(arr, aux, n, s, mid);
        invCount += sortFrom(arr, aux, n, mid + 1, e);
        invCount += performMerge(arr, aux, n, s, mid + 1, e);
        return invCount;
    }
    else
    {
        return 0;
    }
}

int usingMergeProcedure(int arr[], int n)
{
    int aux[n];
    return sortFrom(arr, aux, n, 0, n - 1);
}

int countInversions(int arr[], int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[i])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};

    int n = 5;

    // int inversions = countInversions(arr, n);
    int inversions = usingMergeProcedure(arr, n);
    cout << inversions;
}

// 42
// 468 335 1 170 225 479 359 463 465 206 146 282 328 462 492 496 443 328 437 392 105 403 154 293 383 422 217 219 396 448 227 272 39 370 413 168 300 36 395 204 312 323