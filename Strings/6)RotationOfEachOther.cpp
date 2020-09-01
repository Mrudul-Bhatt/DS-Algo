#include <bits/stdc++.h>
using namespace std;

bool areRotations(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    s1 = s1 + s1;

    return (s1.find(s2) != string::npos);
}

int main()
{
    string s1 = "geeksforgeeks", s2 = "skee";

    bool val = areRotations(s1, s2);
    cout << val;

    return 0;
}