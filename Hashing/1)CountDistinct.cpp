#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[7] = {15, 12, 13, 12, 13, 13, 18};
    int n = 7;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    cout << s.size();

    return 0;
}