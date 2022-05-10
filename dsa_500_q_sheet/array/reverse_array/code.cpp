#include <iostream>
using namespace std;

void reverseArr(int arr[], int size)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

string reverseString(string str)
{
    int i = 0;
    int j = str.size() - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    return str;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    int size = 6;

    reverseArr(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << reverseString("Geeks");
}