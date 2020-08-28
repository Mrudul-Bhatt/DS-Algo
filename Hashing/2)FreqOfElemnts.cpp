#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[7] = {15, 12, 13, 12, 13, 13, 18};
    int n = 7;
    unordered_map<int, int> s;
    for (int i = 0; i < n; i++)
        s[a[i]]++;

    for (auto x : s)
        cout << x.first << ' ' << x.second << '|';

    return 0;
}