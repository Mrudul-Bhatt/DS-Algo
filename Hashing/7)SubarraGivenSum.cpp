#include <bits/stdc++.h>
using namespace std;

int main()
{

    int sum = 22, a[6] = {5, 8, 6, 13, 3, -1};
    unordered_set<int> s;
    int presum = 0;
    for (int i = 0; i < 6; i++)
    {
        presum += a[i];
        if (s.find(presum - sum) != s.end() || presum == sum)
        {
            cout << "Found";
            break;
        }
        s.insert(presum);
    }

    return 0;
}