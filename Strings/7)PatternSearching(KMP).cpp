#include <bits/stdc++.h>
using namespace std;

int fillLps(string s, int lps[])
{
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < s.length())
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                len = lps[len - 1];
        }
    }
}

void KMP(string s1, string s2, int lps[])
{
    int N = s1.length(), M = s2.length();
    int i = 0, j = 0;
    while (i < N)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            cout << i - j << " ";
            j = lps[j - 1];
        }
        else if (i < N && s1[i] != s2[j])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{

    string s1 = "ababcababaad", s2 = "ababa";
    int lps[s2.length()];
    fillLps(s2, lps);
    KMP(s1, s2, lps);
    return 0;
}