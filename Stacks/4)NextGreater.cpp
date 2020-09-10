#include <bits/stdc++.h>
using namespace std;

void nextGreater(int a[], int n)
{
    vector<int> v;
    stack<int> s;
    v.push_back(-1);
    s.push(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= a[i])
        {
            s.pop();
        }
        s.empty() ? v.push_back(-1) : v.push_back(s.top());
        s.push(a[i]);
    }
    reverse(v.begin(), v.end());
    for (auto it : v)
        cout << it << " ";
    return;
}

int main()
{

    int a[5] = {20, 30, 10, 5, 15};
    nextGreater(a, 5);
    return 0;
}