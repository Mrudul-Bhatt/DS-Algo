#include <bits/stdc++.h>
using namespace std;

bool areSame(int a1[], int a2[])
{
    for (int i = 0; i < 256; i++)
        if (a1[i] != a2[i])
            return false;
    return true;
}

bool PermutOfPattern(string txt, string patt)
{
    int counttxt[256] = {0}, countpatt[256] = {0};
    for (int i = 0; i < patt.length(); i++)
    {
        counttxt[txt[i]]++;
        countpatt[patt[i]]++;
    }
    for (int i = patt.length(); i < txt.length(); i++)
    {
        if (areSame(counttxt, countpatt))
            return true;
        counttxt[txt[i]]++;
        counttxt[txt[i - patt.length()]]--;
    }

    return false;
}

int main()
{
    string txt = "geeksforgeeks", patt = "skee";

    bool val = PermutOfPattern(txt, patt);
    cout << val;

    return 0;
}