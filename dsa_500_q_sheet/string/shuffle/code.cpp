#include <iostream>
#include <algorithm>
using namespace std;

bool isShuffledUsingSlidingWindow(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    if (s2.size() < s1.size())
    {
        return 0;
    }
    for (int i = 0, j = s1.size(); i < s2.size(); i++)
    {
        string str = "";

        for (int k = i, count = 0; count < j; k++, count++)
        {
            if (k >= s2.size())
                return 0;
            str.push_back(s2[k]);
        }
        sort(str.begin(), str.end());
        if (str == s1)
            return 1;
    }
    return 0;
}

int main()
{
    string s1 = "onetwofour";
    string s2 = "hellofourtwooneword";
    cout << isShuffledUsingSlidingWindow(s1, s2);
}