#include <bits/stdc++.h>
using namespace std;

void nextSmaller(int a[], int n, int ns[])
{
    vector<int> v;
    stack<int> s;
    v.push_back(n);
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        s.empty() ? v.push_back(n) : v.push_back(s.top());
        s.push(i);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        ns[i] = v[i];
    return;
}

void prevSmaller(int a[], int n, int ps[])
{

    stack<int> s;
    vector<int> v;
    s.push(0);
    v.push_back(-1);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        s.empty() ? v.push_back(-1) : v.push_back(s.top());
        s.push(i);
    }
    for (int i = 0; i < v.size(); i++)
        ps[i] = v[i];
    return;
}

int longestRectangleArea(int a[], int ps[], int ns[], int n)
{
    int res = 0, curr;
    for (int i = 0; i < n; i++)
    {
        curr = a[i];
        curr += (i - ps[i] - 1) * a[i];
        curr += (ns[i] - i - 1) * a[i];
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int n = 7, res;
    int a[n] = {6, 2, 5, 4, 1, 5, 6}, ps[n], ns[n];
    prevSmaller(a, n, ps);
    nextSmaller(a, n, ns);
    res = longestRectangleArea(a, ps, ns, n);
    cout << res;
    return 0;
}