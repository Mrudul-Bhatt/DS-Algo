#include <bits/stdc++.h>
using namespace std;

int LeftmostRepeating(string s1)
{
    int count[256], res = s1.length() + 1;
    fill_n(count, 256, -1);
    for (int i = s1.length() - 1; i >= 0; i--)
        if (count[s1[i]] == -1)
            count[s1[i]] = i;
        else
            res = count[s1[i]];

    return res == s1.length() + 1 ? -1 : res;
}

int main()
{
    string s1 = "geeksforgeeks";

    int val = LeftmostRepeating(s1);
    val == -1 ? cout << -1 : cout << s1[val];

    return 0;
}