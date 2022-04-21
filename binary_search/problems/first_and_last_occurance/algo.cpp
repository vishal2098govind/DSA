#include <bits/stdc++.h>
using namespace std;

int firstOccurance(int arr[], int key, int start, int end, int f)
{
    int mid = (start + end) / 2;

    if (start > end)
    {
        return f;
    }

    if (key == arr[mid])
    {
        if (mid > f)
        {
            return f;
        }
        else
        {
            return firstOccurance(arr, key, start, mid - 1, mid);
        }
    }

    if (key < arr[mid])
    {
        // search for key in left
        return firstOccurance(arr, key, start, mid - 1, f);
    }
    else
    {
        // search for key in right
        return firstOccurance(arr, key, mid + 1, end, f);
    }
}

int lastOccurance(int arr[], int key, int start, int end, int l)
{
    int mid = (start + end) / 2;

    if (start > end)
    {
        return l;
    }

    if (key == arr[mid])
    {
        if (mid < l)
        {
            return l;
        }
        else
        {
            return lastOccurance(arr, key, mid + 1, end, mid);
        }
    }

    if (key < arr[mid])
    {
        // search for key in left
        return lastOccurance(arr, key, start, mid - 1, l);
    }
    else
    {
        // search for key in right
        return lastOccurance(arr, key, mid + 1, end, l);
    }
}

// Using vectors

int firstOccuranceVector(vector<int> &arr, int key, int start, int end, int f)
{
    int mid = (start + end) / 2;

    if (start > end)
    {
        return f;
    }

    if (key == arr[mid])
    {
        if (mid > f)
        {
            return f;
        }
        else
        {
            return firstOccuranceVector(arr, key, start, mid - 1, mid);
        }
    }

    if (key < arr[mid])
    {
        // search for key in left
        return firstOccuranceVector(arr, key, start, mid - 1, f);
    }
    else
    {
        // search for key in right
        return firstOccuranceVector(arr, key, mid + 1, end, f);
    }
}

int lastOccuranceVector(vector<int> &arr, int key, int start, int end, int l)
{
    int mid = (start + end) / 2;

    if (start > end)
    {
        return l;
    }

    if (key == arr[mid])
    {
        if (mid < l)
        {
            return l;
        }
        else
        {
            return lastOccuranceVector(arr, key, mid + 1, end, mid);
        }
    }

    if (key < arr[mid])
    {
        // search for key in left
        return lastOccuranceVector(arr, key, start, mid - 1, l);
    }
    else
    {
        // search for key in right
        return lastOccuranceVector(arr, key, mid + 1, end, l);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter key";
    cin >> key;
    int first = firstOccurance(arr, key, 0, n - 1, n);
    int last = lastOccurance(arr, key, 0, n - 1, -1);
    pair<int, int> firstAndLast = pair(first >= n ? -1 : first, last);
    cout << firstAndLast.first << ", " << firstAndLast.second;
}