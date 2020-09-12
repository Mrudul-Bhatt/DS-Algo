#include <bits/stdc++.h>
using namespace std;

void printFirstN(int n)
{
    queue<string> q;
    q.push("5");
    q.push("6");
    for (int i = 0; i < n; i++)
    {
        string s = q.front();
        cout << s << " ";
        q.pop();
        q.push(s + "5");
        q.push(s + "6");
    }
}

int main()
{
    //print first n numbers which have digits 5 or 6
    int n = 10;
    printFirstN(n);

    return 0;
}