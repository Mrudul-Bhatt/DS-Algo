#include <bits/stdc++.h>
using namespace std;

// void swap(int a,int b){
//     int temp;
//     temp=a;
//     a=b;
//     b=temp;
// }

int lomuto(int a[], int l, int h)
{
    int pivot = a[h];
    int j = l - 1;
    for (int i = l; i < h; i++)
    {
        if (a[i] < pivot)
        {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[j + 1], a[h]);
    return j + 1;
}
int main()
{
    int a[7] = {10, 80, 30, 90, 40, 50, 70}, n = 7;
    int val = lomuto(a, 0, 6);
    cout << val << ' ';
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}
