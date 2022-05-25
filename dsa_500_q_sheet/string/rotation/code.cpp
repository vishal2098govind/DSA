#include <iostream>
using namespace std;

void testNpos()
{
    string s = "geeksForGeeks";
    string s2 = "For";
    string s3 = "on";
    cout << s.find(s2) << endl;
    cout << s.find(s3) << " " << (s.find(s3) == string ::npos) << endl;
}

int main()
{
    testNpos();
}