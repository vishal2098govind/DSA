#include <iostream>
#include <algorithm>
using namespace std;

void mergeUsingExtraSpace(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = 0;
    int temp[n + m];
    for (; k < n + m && i < n && j < m; k++)
    {
        if (arr1[i] < arr2[j])
        {
            temp[k] = arr1[i];
            i++;
        }
        else
        {
            temp[k] = arr2[j];
            j++;
        }
    }

    for (; i < n && k < n + m; i++, k++)
    {
        temp[k] = arr1[i];
    }
    for (; j < m && k < n + m; j++, k++)
    {
        temp[k] = arr2[j];
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {

            arr1[i] = temp[i];
        }
        else
        {

            arr2[i - n] = temp[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
}

void mergeWithoutUsingExtraSpace(int arr1[], int arr2[], int n, int m)
{
    int i = 0;
    int j = 0;
    int k = n - 1;
    for (; i <= k && j < m;)
    {
        if (arr2[j] < arr1[i])
        {
            swap(arr2[j], arr1[k]);
            k--;
            j++;
        }
        else
        {
            i++;
        }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            cout << arr1[i] << " ";
        }
        else
        {
            cout << arr2[i - n] << " ";
        }
    }
}

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    int arr1[n];
    int arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    // mergeUsingExtraSpace(arr1, arr2, n, m);
    mergeWithoutUsingExtraSpace(arr1, arr2, n, m);
}