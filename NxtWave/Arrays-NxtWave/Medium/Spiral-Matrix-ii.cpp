/*

Approach

1)here you just need gto fill the nsquare elements into the matrix in spiaral order--same approach as spiral matrix question


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // Write your code here...
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int row = 0;
        int col = 0;
        int pos = 0;
        int next_row, next_col;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int i = 1;
        while (i <= n * n)
        {
            matrix[row][col] = i;
            next_row = row + dx[pos];
            next_col = col + dy[pos];
            if (next_row >= n || next_row < 0 || next_col >= n || next_col < 0 || matrix[next_row][next_col] != 0)
            {
                pos = (pos + 1) % 4;
            }
            row = row + dx[pos];
            col = col + dy[pos];
            i++;
        }
        return matrix;
    }
};