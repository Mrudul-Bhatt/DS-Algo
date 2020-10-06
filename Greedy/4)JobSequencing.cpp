#include <bits/stdc++.h>
using namespace std;

bool sortbysecond(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

int main()
{
    int dead[] = {5, 4, 1, 5, 1};
    int profit[] = {80, 50, 20, 10, 5};
    int n = 5;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back(make_pair(dead[i], profit[i]));
    sort(v.begin(), v.end(), sortbysecond);
    int res[n];
    bool slot[n];
    fill_n(slot, n, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, v[i].first) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                res[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (slot[i] == true)
            cout << res[i] << " ";

    return 0;
}