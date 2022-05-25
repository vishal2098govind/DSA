#include <iostream>

using namespace std;

string longestPalindrome(string s)
{

    int maxLen = 1;
    string maxLenPal = "";
    maxLenPal.push_back(s[0]);
    for (int i = 0; i < s.size() - 1; i++)
    {
        int left = i == 0 ? i : i - 1;
        int right = i == s.size() - 1 ? i : i + 1;
        while (left >= 0 && s[left] == s[i])
        {
            left--;
        }
        while (right < s.size() && s[right] == s[i])
        {
            right++;
        }

        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        int palindromLength = (right - left) - 1;

        if (palindromLength > maxLen)
        {
            maxLenPal = "";
            maxLen = palindromLength;
            for (int c = left + 1; c < right; c++)
            {
                maxLenPal.push_back(s[c]);
            }
            cout << "Palindrome " << maxLenPal << endl;
        }
        else
        {
            string palindrome = "";

            for (int c = left + 1; c < right; c++)
            {
                palindrome.push_back(s[c]);
            }
            cout << "Palindrome " << palindrome << endl;
        }
    }
    return maxLenPal;
}

int main()
{
    cout << longestPalindrome("aabbaaaa");
}