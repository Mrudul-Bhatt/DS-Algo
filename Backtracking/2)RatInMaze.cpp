#include <bits/stdc++.h>
#define n 3
using namespace std;

void printsol(int sol[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int i, int j, int maze[n][n])
{
    return (i >= 0 && i < n && j >= 0 && j < n && maze[i][j] == 1);
}

bool solveMazeRecur(int maze[n][n], int sol[n][n], int i, int j)
{
    if (i == n - 1 && j == n - 1 && maze[i][j] == 1)
    {
        sol[i][j] = 1;
        return true;
    }
    if (isSafe(i, j, maze))
    {
        sol[i][j] = 1;
        if (solveMazeRecur(maze, sol, i + 1, j) == true)
            return true;
        else if (solveMazeRecur(maze, sol, i, j + 1) == true)
            return true;
        sol[i][j] = 0;
        return false;
    }
    return false;
}

void solveMaze(int maze[n][n])
{
    int sol[n][n] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    if (solveMazeRecur(maze, sol, 0, 0) == false)
    {
        cout << "Soln doesnt exist";
        return;
    }
    printsol(sol);
}

int main()
{
    int maze[n][n] = {{1, 0, 1}, {1, 1, 0}, {0, 1, 1}};
    solveMaze(maze);
    return 0;
}