/*

Approach

1)initialise a matrix with given size all of '#'
2)start from 0th row and go on and make 2 consecutive dots in every row and for each row divert them by 1 pos in x-axis
3)after that you may get 2 edge case fails that is (i) rows may be remained (ii) cols may be remained
4)to identify which edge case failed -- maintain 2 vars -- lastfilledi and lastfilledj
5)if the bottom right cell is not '.' and check which of them (rows or cols) are remained and fill the one way '.' in there!
6)Convert them to vector of strings from vector of vector of chars

*/

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