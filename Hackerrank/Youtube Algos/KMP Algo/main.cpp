#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> KMPprefixArray(string s)
{
  vector<int> a(s.length());

  int i = 0, j = 1;

  a[0] = 0;

  for (int p = 1; p < a.size(); p++)
  {
    if (s[i] == s[j])
    {
      a[p] = i + 1;
      i++;
      j++;
    }
    else
    {
      if (i > 0)
      {
        while (s[i] != s[j])
        {
          if (a[i - 1] == 0)
          {
            i = a[i - 1];
            break;
          }
          i = a[i - 1];
        }

        if (s[i] == s[j])
        {
          a[p] = i + 1;
          i++;
          j++;
        }
        else
        {
          a[p] = 0;
          j++;
        }
      }
      else
      {
        a[p] = 0;
        j++;
      }
    }
  }
  return a;
}
int KMP(string text, string pattern, vector<int> prefixArr)
{
  int t = 0, p = 0, strtIndex = 0, f = 1;
  while (t < text.length() && p < pattern.length())
  {
    if (pattern[p] == text[t])
    {
      if (f == 1)
      {
        strtIndex = t;
        f = 0;
      }
      p++;
      t++;
    }
    else
    {
      f = 1;
      if (p > 0)
        p = prefixArr[p - 1];
      else
        p = prefixArr[0];
      t++;
      // cout << endl
      //  << p << " " << pattern[p] << " " << prefixArr[p];
    }
  }
  return strtIndex;
}
int main()
{
  string text = "acbacxabcdabxabcdacbacdabcy";
  string pattern = "acbacdabcy";

  for (int i = 0; i < text.length(); i++)
  {
    cout << text[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < pattern.length(); i++)
  {
    cout << pattern[i] << " ";
  }
  cout << endl;
  vector<int> prefixArr = KMPprefixArray(pattern);
  for (int i : prefixArr)
    cout << i << " ";
  int start = KMP(text, pattern, prefixArr);
  cout << endl
       << start;
}