#include <bits/stdc++.h>
using namespace std;

bool sortbysecond(pair<int, int> &a, pair<int, int> &b)
{
    double vw1 = (double)a.first / a.second;
    double vw2 = (double)b.first / b.second;
    return vw1 > vw2;
}

int main()
{
    int value[] = {600, 500, 400};
    int weight[] = {50, 20, 30};
    int sackwt = 70, currwt = 0;
    double finalval = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < 3; i++)
        v.push_back(make_pair(value[i], weight[i]));
    sort(v.begin(), v.end(), sortbysecond);
    for (int i = 0; i < 3; i++)
    {
        if (currwt + v[i].second <= sackwt)
        {
            currwt = currwt + v[i].second;
            finalval = finalval + v[i].first;
        }
        else
        {
            int remain = sackwt - currwt;
            finalval = finalval + v[i].first * ((double)remain / v[i].second);
            break;
        }
    }
    cout << finalval;

    return 0;
}