#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int performUnionWithoutUsingSet(int a[], int sizeA, int b[], int sizeB, int c[])
{
    int i = 0;
    int j = 0;
    sort(a, a + sizeA);
    sort(b, b + sizeB);
    vector<int> unionC;
    for (; i < sizeA && j < sizeB;)
    {
        if (a[i] == b[j])
        {
            // c[k] = a[i];
            unionC.push_back(a[i]);
            i++;
            j++;
        }
        else
        {
            if (a[i] < b[j])
            {

                // c[k] = a[i];
                unionC.push_back(a[i]);
                i++;
            }
            else
            {
                // c[k] = b[j];
                unionC.push_back(b[j]);
                j++;
            }
        }
    }
    for (; i < sizeA; i++)
    {
        // c[k] = a[i];
        unionC.push_back(a[i]);
    }
    for (; j < sizeB; j++)
    {
        // c[k] = b[j];
        unionC.push_back(b[j]);
    }

    int count = 0;
    for (int i = 0; i < unionC.size(); i++)
    {
        if (i > 0)
        {
            if (unionC[i] != unionC[i - 1])
            {
                count++;
            }
        }
        else
        {
            count++;
        }
    }

    return count;
}

set<int> performUnionUsingSet(int a[], int sizeA, int b[], int sizeB)
{
    set<int> s;
    for (int i = 0; i < sizeA; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < sizeB; i++)
    {
        s.insert(b[i]);
    }
    return s;
}

int intersection(int a[], int sizeA, int b[], int sizeB, int c[])
{
    sort(a, a + sizeA);
    sort(b, b + sizeB);
    int k = 0;
    for (int i = 0, j = 0; k < sizeA + sizeB && i < sizeA && j < sizeB;)
    {
        if (a[i] == b[j])
        {
            c[k] = a[i];
            i++;
            j++;
            k++;
        }
        else
        {
            if (sizeA > sizeB)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
    return k;
}

int main()
{
    // int a[] = {1, 2, 3, 4, 5};
    // int b[] = {1, 3, 6};
    int sizeA;
    int sizeB;
    cin >> sizeA;
    cin >> sizeB;
    int b[sizeB];
    int a[sizeA];
    for (int i = 0; i < sizeA; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < sizeB; i++)
    {
        cin >> b[i];
    }

    int intersectionC[sizeA + sizeB];
    int unionC[sizeA + sizeB];

    int sizeOfC = performUnionWithoutUsingSet(a, sizeA, b, sizeB, unionC);
    // set<int> unionC = performUnionUsingSet(a, sizeA, b, sizeB);
    int sizeOfIntersectionC = intersection(a, sizeA, b, sizeB, intersectionC);

    cout << "Union" << endl;
    cout << "Size of union " << sizeOfC << endl;
    cout << "Intersection" << endl;
    for (int i = 0; i < sizeOfIntersectionC; i++)
    {
        cout << intersectionC[i] << " ";
    }
}