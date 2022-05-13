#include <iostream>
using namespace std;

int maxProfit(int prices[], int N)
{
    int minBuySoFar = prices[0];
    int profitIfSoldToday = prices[0] - minBuySoFar;
    int maxProfitSoFar = profitIfSoldToday;
    int buyingPrice = prices[0];
    int buyingDay = 0;
    int sellingDay = 0;
    int sellingPrice = prices[0];

    for (int i = 0; i < N; i++)
    {
        // we are replacing minBuySoFar with prices[i] if prices[i]<minBuySoFar,
        // because if we buy with prices[i], whatever be the price in future, it will give more profit than the previous min so far
        if (prices[i] < minBuySoFar)
        {
            // then it is guarenteed that
            // we will get more profit than whatever we would get by buying at minBuySoFar
            // for e.g. if minBuySoFar = 7 and prices[i] = 1
            // then, whatever be the prices[j>i],
            // it is guarenteed that, (prices[j>i] - 1) is always greater than (prices[j>i] - 7)
            // thus, we are sure to replace buying price with 1
            minBuySoFar = prices[i];
            buyingDay = i;
            buyingPrice = prices[i];
        }

        // update profit if by selling at prices[i] gives more profit than maxProfit so far
        // i.e. sell for prices[i] if it gives more profit than maxProfitSoFar
        int profitIfSoldToday = prices[i] - minBuySoFar;

        if (profitIfSoldToday > maxProfitSoFar)
        {
            sellingDay = i;
            sellingPrice = prices[i];
            maxProfitSoFar = profitIfSoldToday;
        }
    }
    cout << "Buy on " << buyingDay << "th day at " << buyingPrice << ", and Sell on " << sellingDay << "th day at " << sellingPrice << endl;
    return maxProfitSoFar;
}

int maxProfitBruteForce(int prices[], int N)
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