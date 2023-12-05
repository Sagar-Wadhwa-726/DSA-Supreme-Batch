#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits>
#include <stack>
using namespace std;

char direction[] = {'D', 'L', 'R', 'U'};
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

bool isSafe(int x, int y, int maze[5][4], int row, int col, vector<vector<bool>> &isVisited)
{
    // Check if in bounds of the maze array
    if (!(x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1))
        return false;
    // Check if visited or not
    if (isVisited[x][y])
        return false;
    // Check if can be visited or not
    else if (maze[x][y] != 1)
        return false;
    return true;
}
void solveMaze(int maze[5][4], int row, int col, int srcx, int srcy, vector<vector<bool>> &isVisited, vector<string> &path, string &output)
{
    if (srcx == row - 1 && srcy == col - 1)
    {
        path.push_back(output);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int newx = srcx + dx[i];
        int newy = srcy + dy[i];
        char newchar = direction[i];

        if (isSafe(newx, newy, maze, row, col, isVisited))
        {
            output.push_back(newchar);
            isVisited[newx][newy] = true;

            solveMaze(maze, row, col, newx, newy, isVisited, path, output);

            output.pop_back();
            isVisited[newx][newy] = false;
        }
    }

    // // Solve for Down
    // if (isSafe(srcx + 1, srcy, maze, row, col, isVisited))
    // {
    //     isVisited[srcx + 1][srcy] = true;
    //     output.push_back('D');

    //     solveMaze(maze, row, col, srcx + 1, srcy, isVisited, path, output);

    //     output.pop_back();
    //     isVisited[srcx + 1][srcy] = false;
    // }

    // // Solve for Left
    // if (isSafe(srcx, srcy - 1, maze, row, col, isVisited))
    // {
    //     isVisited[srcx][srcy - 1] = true;
    //     output.push_back('L');

    //     solveMaze(maze, row, col, srcx, srcy - 1, isVisited, path, output);

    //     output.pop_back();
    //     isVisited[srcx][srcy - 1] = false;
    // }

    // // Solve for Right
    // if (isSafe(srcx, srcy + 1, maze, row, col, isVisited))
    // {
    //     isVisited[srcx][srcy + 1] = true;
    //     output.push_back('R');

    //     solveMaze(maze, row, col, srcx, srcy + 1, isVisited, path, output);

    //     output.pop_back();
    //     isVisited[srcx][srcy + 1] = false;
    // }

    // // Solve for Up
    // if (isSafe(srcx - 1, srcy, maze, row, col, isVisited))
    // {
    //     isVisited[srcx - 1][srcy] = true;
    //     output.push_back('U');

    //     solveMaze(maze, row, col, srcx - 1, srcy, isVisited, path, output);

    //     output.pop_back();
    //     isVisited[srcx - 1][srcy] = false;
    // }
}
int main()
{
    system("cls");

    // Original maze array
    int maze[5][4] = {{1, 0, 1, 0},
                      {1, 1, 1, 1},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 1, 1}};

    if (maze[0][0] == 0)
    {
        cout << "No path available";
        return 0;
    }

    int row = 5;
    int col = 4;

    // Visited array
    vector<vector<bool>> isVisited(row, vector<bool>(4, 0));

    // Source destinatoin is visited by default
    isVisited[0][0] = true;

    vector<string> path;
    string output = "";

    solveMaze(maze, row, col, 0, 0, isVisited, path, output);

    if (path.size() == 0)
    {
        cout << "No path exists";
        return 0;
    }

    for (string x : path)
        cout << x << "\n";

    return 0;
}