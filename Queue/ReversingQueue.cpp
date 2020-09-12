#include <bits/stdc++.h>
using namespace std;

void reverseQ(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
void reverseR(queue<int> &q)
{
    if (q.empty())
        return;
    int x = q.front();
    q.pop();
    reverseR(q);
    q.push(x);
}

int main()
{

    queue<int> q;
    q.push(12);
    q.push(5);
    q.push(15);
    q.push(20);
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    q.push(12);
    q.push(5);
    q.push(15);
    q.push(20);

    reverseQ(q); //iterative
    reverseR(q); //recursive
    //since recursion works as a stack which calls
    //the last ended function so we are using stack
    //in recursive aproach

    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }

    return 0;
}