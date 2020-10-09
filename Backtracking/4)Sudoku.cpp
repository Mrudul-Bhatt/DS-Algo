#include <bits/stdc++.h>
#define n 4
using namespace std;

void printsol(int grid[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int grid[n][n], int row, int col, int x)
{
    for (int k = 0; k < n; k++)
        if (grid[row][k] == x || grid[k][col] == x)
            return false;

    int s = sqrt(n);
    int rs = row - row % s;
    int cs = col - col % s;

    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            if (grid[i + rs][j + cs] == x)
                return false;

    return true;
}

bool sudokuRecur(int grid[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (grid[i][j] == 0)
                break;
    if (i == n && j == n)
        return true;
    //we have to fill values from 1 to n
    for (int x = 1; x <= n; x++)
    {
        if (isSafe(grid, x, i, j))
        {
            grid[i][j] = x;
            if (sudokuRecur(grid) == true)
                return true;
            grid[i][j] = 0;
        }
    }
    return false;
}

void sudoku(int grid[n][n])
{
    if (sudokuRecur(grid) == false)
    {
        cout << "Soln doesnt exist";
        return;
    }
    printsol(grid);
}

int main()
{
    int grid[n][n] = {{1, 0, 3, 0}, {0, 0, 2, 1}, {0, 1, 0, 2}, {2, 4, 0, 0}};
    sudoku(grid);
    return 0;
}