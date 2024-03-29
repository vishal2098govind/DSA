#include <iostream>
#include <unordered_map>
using namespace std;

void printDups(string str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++; // increase the count of characters by 1
    }

    for (auto it : count)
    {                      // iterating through the unordered map
        if (it.second > 1) // if the count of characters is greater then 1 then duplicate found
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}