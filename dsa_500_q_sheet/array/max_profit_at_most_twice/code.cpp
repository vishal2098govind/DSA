#include <iostream>
#include <vector>

using namespace std;

int maxProfitAtMostTwice(vector<int> &prices)
{
    vector<int> profits(prices.size(), 0);
    int max_price = prices.back();
    for (int i = prices.size() - 2; i >= 0; i--)
    {
        max_price = max(max_price, prices[i]);
        profits[i] = max(profits[i + 1], max_price - prices[i]);
    }

    int min_price = prices.front();
    for (int i = 1; i < prices.size(); i++)
    {
        min_price = min(min_price, prices[i]);
        profits[i] = max(profits[i - 1], profits[i] + (prices[i] - min_price));
    }
    return profits.back();
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        arr.push_back(in);
    }

    int ans = maxProfitAtMostTwice(arr);
    cout << ans;
}