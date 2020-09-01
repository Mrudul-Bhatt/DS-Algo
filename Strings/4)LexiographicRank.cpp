#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    return (n == 1 || n == 0) ? 1 : n * fact(n - 1);
}

int LexiographicRank(string s)
{
    int rank = 1, count[256] = {0}, n = s.length(), mul = fact(n);

    for (int i = 0; i < n; i++)
        count[s[i]]++;
    for (int i = 1; i < 256; i++)
        count[i] = count[i] + count[i - 1];
    for (int i = 0; i < n; i++)
    {
        mul = mul / n - i;
        rank = rank + count[s[i] - 1] * mul;
        for (int j = s[i]; j < 256; j++)
            count[j]--;
    }

    return rank;
}

int main()
{
    string s = "geeksforgeeks";

    int val = LexiographicRank(s);
    cout << val;

    return 0;
}