#include <bits/stdc++.h>
#define n 4
using namespace std;

void printsol(int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int board[n][n], int row, int col)
{
    //since columns are auto matically checked so we only check for rows
    //checking if previous gaps in same row already has a queen i.e 1
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;
    //checking upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; j--, i--)
        if (board[i][j] == 1)
            return false;
    //checking lower left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;
    return true;
}

bool nQueenRecur(int board[n][n], int col)
{
    if (col == n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (nQueenRecur(board, col + 1) == true)
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void nQueen(int board[n][n])
{
    if (nQueenRecur(board, 0) == false)
    {
        cout << "Soln doesnt exist";
        return;
    }
    printsol(board);
}

int main()
{
    int board[n][n] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    nQueen(board);
    return 0;
}