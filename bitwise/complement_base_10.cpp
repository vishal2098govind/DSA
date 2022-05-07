#include <iostream>
using namespace std;

void printInBinary(int n)
{
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

int main()
{
    int n;
    cin >> n;
    int m = n;

    int mask = 0;
    while (n != 0)
    {
        n = n >> 1;
        mask = mask << 1;
        mask = mask | 1;
    }

    cout << "n         : ";
    printInBinary(m);
    cout << endl;
    cout << "Mask      : ";
    printInBinary(mask);
    cout << endl;
    cout << "Complement: ";
    int c = (~m) & mask;
    printInBinary(c);
    cout << endl;
}
