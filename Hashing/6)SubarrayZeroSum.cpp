#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[6] = {1, 4, 13, -3, -10, 5};
    unordered_set<int> s;
    int presum = 0;
    for (int i = 0; i < 6; i++)
    {
        presum += a[i];
        if (s.find(presum) != s.end() || presum == 0)
        {
            cout << "Found";
            break;
        }
        s.insert(presum);
    }

    return 0;
}