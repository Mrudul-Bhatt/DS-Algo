#include <bits/stdc++.h>
using namespace std;

bool sortbysecond(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    int s[] = {3, 2, 1, 10};
    int f[] = {8, 4, 3, 11};
    vector<pair<int, int>> v;
    for (int i = 0; i < 4; i++)
        v.push_back(make_pair(s[i], f[i]));
    sort(v.begin(), v.end(), sortbysecond);
    cout << 0 << " ";
    int j = 0;
    for (int i = 1; i < 4; i++)
    {
        if (v[i].first >= v[j].second)
        {
            cout << i << " ";
            j = i;
        }
    }

    return 0;
}