#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> createGrid(int m, int n)
    {
        vector<vector<char>> arr(m, vector<char>(n, '#'));
        int lastfilledi;
        int lastfilledj;
        for (int i = 0; i < m; i++)
        {
            if (i < n)
            {
                arr[i][i] = '.';
                lastfilledi = i;
                lastfilledj = i;
            }
            if (i + 1 < n)
            {
                arr[i][i + 1] = '.';
                lastfilledi = i;
                lastfilledj = i + 1;
            }
        }
        if (arr[m - 1][n - 1] != '.' && lastfilledj == n - 1)
        {
            for (int i = lastfilledi + 1; i < m; i++)
            {
                arr[i][n - 1] = '.';
            }
        }
        if (arr[m - 1][n - 1] != '.' && lastfilledi == m - 1)
        {
            for (int j = lastfilledj + 1; j < n; j++)
            {
                arr[m - 1][j] = '.';
            }
        }
        vector<string> ans;
        for (int i = 0; i < m; i++)
        {
            string str = "";
            for (int j = 0; j < n; j++)
            {
                str += arr[i][j];
            }
            ans.push_back(str);
        }
        return ans;
    }
};