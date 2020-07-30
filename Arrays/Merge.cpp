/*
merge 2 sorted arrays
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i = 0, j = 0, k = 0, arr1[5] = {1, 3, 5, 6, 7}, arr2[7] = {2, 4, 8, 9, 10, 11, 12}, arr3[12];
    while (i < 5 && j < 7)
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];

    while (i < 5)
        arr3[k++] = arr1[i++];

    while (j < 7)
        arr3[k++] = arr2[j++];

    for (int i = 0; i < 12; i++)
        cout << arr3[i] << ' ';

    return 0;
}