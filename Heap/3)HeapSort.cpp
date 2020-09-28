#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    //time: O(h) ,since complete binary tree so
    //h=logn , therefore time: O(logn)
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
    //time : O(nlogn) ~ O(n)
    int x = (n - 2) / 2;
    for (int i = x; i >= 0; i--)
        maxHeapify(arr, n, i);
}
void HeapSort(int arr[], int &n)
{
    //time: O(nlogn)
    buildHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
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
    HeapSort(arr, n);
    printArray(arr, n);

    return 0;
}
