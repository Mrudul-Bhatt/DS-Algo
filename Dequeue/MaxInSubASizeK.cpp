#include <bits/stdc++.h>
using namespace std;

void printMaxInKSubArrays(int arr[], int k, int n)
{
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()];
}

int main()
{
    int arr[5] = {20, 40, 30, 10, 60};
    int k = 3, n = 5;
    printMaxInKSubArrays(arr, k, n);
    //for min just reverse signs in 1st and 3rd while loop
    return 0;
}