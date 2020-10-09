#include <bits/stdc++.h>
using namespace std;

void permut(string &s, int l, int r)
{
    if (l == r - 1)
    {
        if (s.find("AB") == string::npos)
            cout << s << " ";
        return;
    }
    for (int i = l; i < r; i++)
    {
        swap(s[i], s[l]);
        permut(s, l + 1, r);
        swap(s[i], s[l]);
    }
}

int main()
{
    string s = "ABC";
    permut(s, 0, s.length());
    return 0;
}