#include <iostream>
#include <vector>

using namespace std;

void multiply(vector<int> &res, int x)
{

    int carry = 0;
    for (int i = 0; i < res.size(); i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry != 0)
    {
        res.push_back(carry % 10);
        carry = carry / 10;
    }
}

vector<int> factorial(int N)
{
    int x = 2;
    vector<int> ans = {1};
    while (x <= N)
    {
        multiply(ans, x);
        x++;
    }

    for (int i = 0, j = ans.size() - 1; i < j; i++, j--)
    {
        swap(ans[i], ans[j]);
    }

    return ans;
}

int main()
{
    int N;
    cin >> N;
    vector<int> ans = factorial(N);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}