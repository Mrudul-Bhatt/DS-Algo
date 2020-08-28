#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[4] = {15, 20, 5, 15}, b[5] = {15, 15, 15, 20, 10};
    unordered_set<int> s;
    for (int i = 0; i < 4; i++)
        s.insert(a[i]);
    for (int i = 0; i < 5; i++)
        s.insert(b[i]);
    cout << s.size();

    return 0;
}