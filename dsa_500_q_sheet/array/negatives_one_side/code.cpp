#include <iostream>
using namespace std;

void getNegativesToOneSide(int arr[], int size)
{

    for (int i = 0, j = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (arr[j] > 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        else
        {
            if (arr[j] < 0)
            {
                j = i;
            }
        }
    }
}

int main()
{
    int size = 9;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    getNegativesToOneSide(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}