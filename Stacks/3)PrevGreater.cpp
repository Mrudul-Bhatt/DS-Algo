#include <bits/stdc++.h>
using namespace std;

void prevGreater(int a[], int n)
{

    stack<int> s;
    s.push(a[0]);
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && s.top() <= a[i])
        {
            s.pop();
        }
        int prevG = s.empty() ? -1 : s.top();
        cout << prevG << " ";
        s.push(a[i]);
    }
    return;
}

int main()
{

    int a[5] = {20, 30, 10, 5, 15};
    prevGreater(a, 5);
    return 0;
}