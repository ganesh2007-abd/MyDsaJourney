#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &grid, int count)
    {
        int m = grid.size();
        int n = grid[0].size();
        // if(grid[i][j] == -1){
        //     return 0;
        // }
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
        {
            return 0;
        }
        else if (grid[i][j] == 2)
        {
            return count == 0 ? 1 : 0;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        if (temp == 0)
        {
            count--;
        }
        int ans = f(i - 1, j, grid, count) + f(i, j - 1, grid, count) + f(i + 1, j, grid, count) + f(i, j + 1, grid, count);
        grid[i][j] = temp;
        return ans;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    count++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return f(i, j, grid, count);
                }
            }
        }
        return 0;
    }
};