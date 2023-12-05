// https://leetcode.com/problems/n-queens/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
void printSolution(vector<vector<char>> &board)
{
    for (vector<char> x : board)
    {
        for (char y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
// bool isSafe(int &row, int &col, vector<vector<char>> &board, int &n)
// {
//     int i = row;
//     int j = col;

//     // check for upper column
//     while (i >= 0)
//     {
//         if (board[i][j] == 'Q')
//         {
//             return false;
//         }
//         i--;
//     }

//     // check for upper left diagnol
//     i = row;
//     j = col;
//     while (i >= 0 && j >= 0)
//     {
//         if (board[i][j] == 'Q')
//         {
//             return false;
//         }
//         i--;
//         j--;
//     }

//     // check for upper right diagnol
//     i = row;
//     j = col;
//     while (i >= 0 && j < n)
//     {
//         if (board[i][j] == 'Q')
//         {
//             return false;
//         }
//         i--;
//         j++;
//     }
//     return true;
// }
// void solve(vector<vector<char>> &board, int row, int n)
// {
//     // base case -> if we reach the last row, it means we have placed all the queens
//     // considering we move out of the matrix now since index is one less than the actual row number
//     if (row >= n)
//     {
//         printSolution(board);
//         return;
//     }

//     // one case will be solved by us, rest will be handled by recursion
//     // Try to place the Queen on each column
//     for (int column = 0; column < n; column++)
//     {
//         if (isSafe(row, column, board, n))
//         {
//             // place the queen
//             board[row][column] = 'Q';

//             // rest of the queens will be placed by recursion in the next row
//             solve(board, row + 1, n);

//             // if we come back, we need to remove the currently placed queen from the current position and place it in the next column
//             board[row][column] = '.';
//         }
//     }
// }

unordered_map<int, bool> columnCheck;
unordered_map<int, bool> upperLeftDiagnolCheck;
unordered_map<int, bool> upperRightDiagnolCheck;

bool isSafe(int &row, int &col, vector<vector<char>> &board, int &n)
{
    if (columnCheck[col])
        return false;
    else if (upperLeftDiagnolCheck[n - 1 + col - row])
        return false;
    else if (upperRightDiagnolCheck[row + col])
        return false;
    return true;
}
void solve(vector<vector<char>> &board, int row, int n)
{
    // base case -> if we reach the last row, it means we have placed all the queens
    // considering we move out of the matrix now since index is one less than the actual row number
    if (row >= n)
    {
        printSolution(board);
        return;
    }

    // one case will be solved by us, rest will be handled by recursion
    // Try to place the Queen on each column
    for (int column = 0; column < n; column++)
    {
        if (isSafe(row, column, board, n))
        {
            // place the queen
            board[row][column] = 'Q';

            // Add the corresponding entry in the map
            columnCheck[column] = true;
            upperLeftDiagnolCheck[n - 1 + column - row] = true;
            upperRightDiagnolCheck[row + column] = true;

            // rest of the queens will be placed by recursion in the next row
            solve(board, row + 1, n);

            // if we come back, we need to remove the currently placed queen from the current position and place it in the next column
            board[row][column] = '.';

            // Remove the corresponding entry in the map
            columnCheck[column] = false;
            upperLeftDiagnolCheck[(n - 1) + column - row] = false;
            upperRightDiagnolCheck[row + column] = false;
        }
    }
}
int main()
{
    system("cls");
    int n = 4;
    vector<vector<char>> board(n, vector<char>(4, '.'));

    // denotes on which row we are initially
    int row = 0;

    // calling the recursive function to place n-queens on the board
    solve(board, row, n);

    return 0;
}