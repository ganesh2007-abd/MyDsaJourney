/*

Approach

1)Instead of using another 2 1d arrays..lets just reuse the 1st row and 1st col of that matrix
2)but before reusing we first use 2 variables to check that wheather to fill the 1st row and 1st col to zeroes beacasue after the problem they may be overridden
3)then trvaerse the 1 to m-1 rows and from 1 to n-1 cols andif a cell is zero then set the coresponding row and col places to zero
4)from the marking later set the matrix elements to zero and also according to those 2 variables set the first row and col accordingly

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void zeroFill(vector<vector<int>> &matrix)
    {
        // Write your code here...
        int firstrow = -1;
        int firstcol = -1;

        int m = matrix.size();
        int n = matrix[0].size();

        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                firstrow = 0;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                firstcol = 0;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstrow == 0)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (firstcol == 0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};