#include <bits/stdc++.h>
using namespace std;

int LeftmostNonRepeating(string s1)
{
    int count[256], res = s1.length() + 1;
    fill_n(count, 256, -1);
    for (int i = 0; i < s1.length(); i++)
        if (count[s1[i]] == -1)
            count[s1[i]] = i;
        else
            count[s1[i]] = -2;

    for (int i = 0; i < 256; i++)
        if (count[i] > 0)
            res = min(res, count[i]);

    return res == s1.length() + 1 ? -1 : res;
}

int main()
{
    string s1 = "geeksforgeeks";

    int val = LeftmostNonRepeating(s1);
    val == -1 ? cout << -1 : cout << s1[val];

    return 0;
}