#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    // Array representation of Max-Heap
    // 10
    // / \ 
	// 5 3
    // / \ 
	// 2 4
    int arr[] = {8, 6, 4, 10, 9};
    int n = 5;
    int k = 3;
    //Using maxHeap
    priority_queue<int> p; //maxHeap
    for (int i = 0; i < n; i++)
        p.push(arr[i]);
    for (int i = 0; i < k; i++)
    {
        cout << p.top() << " ";
        p.pop();
    }
    //time: O(n+klogn)

    //Using minHeap(efficient)
    priority_queue<int, vector<int>, greater<int>> q; //minHeap
    for (int i = 0; i < k; i++)
        q.push(arr[i]);
    for (int i = k; i < n; i++)
    {
        if (q.top() < arr[i])
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }

    //time: O(k+(n-k)logk)
    return 0;
}
