#include <iostream>
using namespace std;

void cyclicRotate(int a[], int size)
{
    int lastElement = a[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        a[i + 1] = a[i];
    }
    a[0] = lastElement;
}

int main()
{
    int sizeA;
    cin >> sizeA;
    int a[sizeA];
    int n;
    cin >> n;
    for (int i = 0; i < sizeA; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cyclicRotate(a, sizeA);
    }

    for (int i = 0; i < sizeA; i++)
    {
        cout << a[i] << " ";
    }
}