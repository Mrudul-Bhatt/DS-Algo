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
    int arr[] = {9, 8, 7, 18, 19, 17};
    int n = 6;
    int k = 2;
    printArray(arr, n);
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i <= k; i++)
        p.push(arr[i]);
    int index = 0;
    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = p.top();
        p.pop();
        p.push(arr[i]);
    }
    while (!p.empty())
    {
        arr[index++] = p.top();
        p.pop();
    }
    printArray(arr, n);

    return 0;
}
