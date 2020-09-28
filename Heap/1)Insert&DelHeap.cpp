#include <bits/stdc++.h>
using namespace std;

void maxHeapifyForDelete(int arr[], int n, int i)
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
        maxHeapifyForDelete(arr, n, largest);
    }
}
void maxHeapifyForInsert(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (parent >= 0)
    {
        if (arr[parent] < arr[i])
        {
            swap(arr[parent], arr[i]);
            maxHeapifyForInsert(arr, n, parent);
        }
    }
}
//deletes root value
void deleteRoot(int arr[], int &n)
{
    int last_element = arr[n - 1];
    n = n - 1;
    arr[0] = last_element;
    maxHeapifyForDelete(arr, n, 0);
}
//inserts value
void insertNode(int arr[], int &n, int key)
{
    n++;
    arr[n - 1] = key;
    maxHeapifyForInsert(arr, n, n - 1);
}
//deletes from anywhere
void deleteRandom(int arr[], int &n, int i)
{
    arr[i] = INT8_MAX;
    maxHeapifyForInsert(arr, n, i);
    deleteRoot(arr, n);
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
    deleteRoot(arr, n);
    printArray(arr, n);
    int key = 10;
    insertNode(arr, n, key);
    printArray(arr, n);
    deleteRandom(arr, n, 3);
    printArray(arr, n);

    return 0;
}
