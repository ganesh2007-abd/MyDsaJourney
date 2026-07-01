/*

Approach

1)to rotate a matrix by 90deg
2)first we transpose the matrix and then swap the 1st col and last col,sec col with last sec col, and so on..


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &matrix)
    {
        // Write your code here...
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }
        return matrix;
    }
};