#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string ans = "";
    while (n != (n < 0 ? -1 : 0))
    {
        int lastBit = n & 1;
        string lastBitString = to_string(lastBit);
        n = n >> 1;
        ans = lastBitString + ans;
    }

    while (ans.length() != 32)
    {
        ans = (n < 0 ? '1' : '0') + ans;
    }
    cout << ans;
}