#include <bits/stdc++.h>
using namespace std;

int main()
{

    int sum = 17, a[5] = {3, 2, 8, 15, -8};
    unordered_set<int> s;
    for (int i = 0; i < 5; i++)
    {
        if (s.find(sum - a[i]) != s.end())
        {
            cout << "Found";
            break;
        }
        s.insert(a[i]);
    }

    return 0;
}