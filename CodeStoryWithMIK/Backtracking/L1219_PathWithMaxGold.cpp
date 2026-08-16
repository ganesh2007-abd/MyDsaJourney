// approach

/*

1)as we can start form any cell use 2 for loops and start from evry cell int he grid
2)in backtrack() function -- the def is maximum amount of gold can be captured in grid starting from (i,j)
3)we explore top,bottom,left,right and take max of them and return grid[i][j] + max(all surrounding cells)
4)as base conditions we check the indices are not out of bounds and grid value is not 0
5)we use state encoding to get rid of extra visited array

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m;
    int n;

    int backtrack(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
        {
            return 0;
        }
        // if(visited[i][j]) return 0;
        // if(visited[i][j]) return 0;
        if (grid[i][j] == -1)
            return 0;
        // visited[i][j] = 1;
        int temp = grid[i][j];
        grid[i][j] = -1;
        int top = backtrack(i - 1, j, grid);
        int left = backtrack(i, j - 1, grid);
        int right = backtrack(i, j + 1, grid);
        int bottom = backtrack(i + 1, j, grid);
        grid[i][j] = temp;

        return grid[i][j] + max(max(left, top), max(right, bottom));
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        // vector<vector<int>> visited(m,vector<int>(n,0));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    ans = max(ans, backtrack(i, j, grid));
                }
            }
        }
        return ans;
    }
};