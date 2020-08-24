#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start, end;
};
bool compareInterval(Interval i1, Interval i2)
{
    return i1.start < i2.start;
}

int main()
{
    int a[5] = {10, 20, 5, 7, 13}, n = 5;
    //vector<int> v = {10,20,5,7,13};
    sort(a, a + n);
    //sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}, {7, 11}};
    sort(arr, arr + n, compareInterval);

    for (int i = 0; i < n; i++)
        cout << arr[i].start << ',' << arr[i].end << '|';

    return 0;
}
