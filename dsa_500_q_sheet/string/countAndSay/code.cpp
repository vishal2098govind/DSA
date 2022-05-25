#include <iostream>

using namespace std;

string say(string s)
{
    string ans = "";
    int count = 1;
    int i = 0;
    for (; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
        else
        {
            ans.push_back(49 + (count - 1));
            ans.push_back(s[i]);
            count = 1;
        }
    }
    ans.push_back(49 + (count - 1));
    ans.push_back(s[i]);
    return ans;
}

string countAndSay(int n)
{
    if (n == 1)
    {
        return "1";
    }
    return say(countAndSay(n - 1));
}

int main()
{
    int n;
    cin >> n;
    cout << countAndSay(n);
}