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
void printBoard(int board[9][9], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
bool isSafe(int board[9][9], int &n, int &value, int &rowToPlace, int &colToPlace)
{
    // Check for row
    for (int col = 0; col < 9; col++)
        if (board[rowToPlace][col] == value)
            return false;

    // Check for column
    for (int row = 0; row < 9; row++)
        if (board[row][colToPlace] == value)
            return false;

    // Check for 3x3 board
    for (int i = 0; i < 9; i++)
        if (board[3 * (rowToPlace / 3) + (i / 3)][3 * (colToPlace / 3) + (i % 3)] == value)
            return false;
    return true;
}
// This function returns true or false basis on we found a solution or not
bool solve(int board[9][9], int n)
{
    // This recursive functoin does not requires a base case
    // Since we need to fill all the cells, need to traverse on all the cells
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Now we have a cell, try to fill it with values from [1-9] if it is empty and is safe
            // to place that number
            if (board[i][j] == 0)
            {
                // Place values from [1-9]
                for (int value = 1; value <= 9; value++)
                {
                    if (isSafe(board, n, value, i, j))
                    {
                        board[i][j] = value;

                        // Recursive call to fill the next cells, either we will be able to place the next cells (returns true), then no backtracking needed, else need to backtrack.
                        bool futureSolution = solve(board, n);

                        if (futureSolution)
                            return true;

                        board[i][j] = 0;
                    }
                }
                // If we are not able to place any value from [1-9] in any cell, need to backtrack
                // and change the value of the previous call
                return false;
            }
        }
    }
    // If we come here that means we would have found atleast one solution hence return true.
    return true;
}
int main()
{
    system("cls");
    // https://leetcode.com/problems/sudoku-solver/
    const int n = 9;

    int board[n][n] =
        {
            {4, 5, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 2, 0, 7, 0, 6, 3, 0},
            {0, 0, 0, 0, 0, 0, 0, 2, 8},
            {0, 0, 0, 9, 5, 0, 0, 0, 0},
            {0, 8, 6, 0, 0, 0, 2, 0, 0},
            {0, 2, 0, 6, 0, 0, 7, 5, 0},
            {0, 0, 0, 0, 0, 0, 4, 7, 6},
            {0, 7, 0, 0, 4, 5, 0, 0, 0},
            {0, 0, 8, 0, 0, 9, 0, 0, 0}};

    bool solution = solve(board, n);

    if (!solution)
    {
        cout << "No solution exists !";
        return 0;
    }
    printBoard(board, n);
    return 0;
}