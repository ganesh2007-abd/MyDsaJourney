#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cp(int r1, int c1, int r2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int n)
    {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n)
        {
            return INT_MIN;
        }
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            return INT_MIN;
        }
        if (r1 == n - 1 && c1 == n - 1)
        {
            return grid[r1][c1];
        }
        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];
        int cherries = 0;
        if (r1 == r2 && c1 == c2)
        {
            cherries += grid[r1][c1];
        }
        else
        {
            cherries += grid[r1][c1] + grid[r2][c2];
        }
        int f1 = cp(r1 + 1, c1, r2, grid, dp, n);
        int f2 = cp(r1, c1 + 1, r2 + 1, grid, dp, n);
        int f3 = cp(r1 + 1, c1, r2 + 1, grid, dp, n);
        int f4 = cp(r1, c1 + 1, r2, grid, dp, n);
        int best = max(max(f1, f2), max(f3, f4));

        if (best == INT_MIN)
            return dp[r1][c1][r2] = INT_MIN;

        return dp[r1][c1][r2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = cp(0, 0, 0, grid, dp, n);
        return max(0, ans);
    }
};