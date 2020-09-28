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
    int arr[] = {1, 12, 5, 111, 200};
    int n = 5;
    int sum = 10, count = 0;
    priority_queue<int, vector<int>, greater<int>> p; //minHeap
    for (int i = 0; i < n; i++)
        p.push(arr[i]);
    while (!p.empty())
    {
        if (p.top() <= sum)
        {
            sum = sum - p.top();
            p.pop();
            count++;
        }
        else
            break;
    }
    cout << count;
    return 0;
}
