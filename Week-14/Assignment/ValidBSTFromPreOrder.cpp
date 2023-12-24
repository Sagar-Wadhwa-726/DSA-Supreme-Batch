// https://www.interviewbit.com/problems/valid-bst-from-preorder/
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
#include <climits>
#include <stack>
using namespace std;
void build(int &i, int &min, int &max, vector<int> &A)
{
    if (i >= A.size())
        return;

    if (A[i] > min && A[i] < max)
    {
        int root_data = A[i++];
        build(i, min, root_data, A);
        build(i, root_data, max, A);
    }
}
int solve(vector<int> &A)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    build(i, min, max, A);
    return i == A.size();
}

int main()
{
    system("cls");

    return 0;
}