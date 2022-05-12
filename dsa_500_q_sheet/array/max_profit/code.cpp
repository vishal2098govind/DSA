#include <iostream>
using namespace std;

int maxProfit(int prices[], int N)
{
    int maxi = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (prices[j] > prices[i])
            {
                maxi = max(maxi, prices[j] - prices[i]);
            }
        }
    }
    return maxi;
}

int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    int N = 6;
    int ans = maxProfit(arr, N);
    cout << ans;
}