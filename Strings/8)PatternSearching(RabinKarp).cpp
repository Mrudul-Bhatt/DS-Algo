#include <bits/stdc++.h>
#define d 256
using namespace std;

void RabinKarpSearch(string pat, string txt, int q)
{
    int m = pat.length();
    int n = txt.length();
    int p = 0, t = 0;
    int h = 1, j;
    //imp
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
                if (txt[i + j] != pat[j])
                    break;

            if (j == m)
                cout << i << " ";
        }
        if (i <= n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}

int main()
{
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    int q = 101; // A prime number
    RabinKarpSearch(pat, txt, q);
    return 0;
}