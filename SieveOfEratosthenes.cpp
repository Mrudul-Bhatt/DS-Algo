//determining prime numbers for a range of numbers ex: 1 to n

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    int count = 1, p, x = 0;
    for (int i = 0; i <= 48; i++)
    {
        a.push_back(i + 2);
    }

    while (count)
    {
        count = 1;
        p = a[x];
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] >= p * p && a[i] % p == 0)
            {
                a.erase(a.begin() + i);
                count++;
            }
        }
        x++;
        count--;
    }

    for (int j = 0; j < a.size(); j++)
    {
        cout << a[j] << ' ';
    }
    return 0;
}