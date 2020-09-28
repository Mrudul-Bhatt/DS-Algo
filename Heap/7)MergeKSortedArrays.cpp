#include <bits/stdc++.h>
using namespace std;

struct Triplet
{
    int val, aPos, vPos;
    Triplet(int v, int ap, int vp)
    {
        val = v;
        aPos = ap;
        vPos = vp;
    }
};
struct MyCmp
{
    bool operator()(Triplet &t1, Triplet &t2)
    {
        return t1.val > t2.val;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr)
{
    vector<int> output;
    priority_queue<Triplet, vector<Triplet>, MyCmp> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        Triplet t(arr[i][0], i, 0);
        pq.push(t);
    }
    while (!pq.empty())
    {
        Triplet curr = pq.top();
        pq.pop();
        output.push_back(curr.val);
        int ap = curr.aPos;
        int vp = curr.vPos;
        if (vp + 1 < arr[ap].size())
        {
            Triplet t(arr[ap][vp + 1], ap, vp + 1);
            pq.push(t);
        }
    }
    return output;
}

int main()
{
    vector<vector<int>> arr{{2, 6, 12},
                            {1, 9},
                            {23, 34, 90, 2000}};

    vector<int> output = mergeKArrays(arr);

    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";

    return 0;
}
