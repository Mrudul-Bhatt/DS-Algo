#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int &n)
{
    int x = (n - 2) / 2;
    for (int i = x; i >= 0; i--)
        maxHeapify(arr, n, i);
}

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
    int arr[] = {10, 5, 3, 2, 4};
    int n = 5;
    //Extract Min or Max is similar to delete root node
    buildHeap(arr, n);
    printArray(arr, n);

    return 0;
}
