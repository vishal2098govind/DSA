#include <iostream>
#include <vector>

using namespace std;

int maxProd(int arr[], int n)
{
    int ansLtoR = arr[0];
    int prodLtoR = ansLtoR;

    for (int i = 1; i < n; i++)
    {
        prodLtoR = arr[i] * prodLtoR;
        ansLtoR = max(prodLtoR, ansLtoR);
        if (prodLtoR == 0)
        {
            prodLtoR = 1;
        }
    }
    int ansRtoL = arr[n - 1];
    int prodRtoL = ansRtoL;
    for (int i = n - 2; i >= 0; i--)
    {
        prodRtoL = arr[i] * prodRtoL;
        ansRtoL = max(prodRtoL, ansRtoL);
        if (prodRtoL == 0)
        {
            prodRtoL = 1;
        }
    }

    return max(ansLtoR, ansRtoL);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = maxProd(arr, n);
    cout << ans;
}