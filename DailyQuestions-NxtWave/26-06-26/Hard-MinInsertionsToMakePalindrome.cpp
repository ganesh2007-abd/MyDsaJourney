/*

Approach

1)to know how many characters to insert first we should know how many things are alrady palindromic
2)which means first we have to know the longest palindromic sequence the string has
3)when we subtract the length of lps(longest palindromic sequence) from the total string length we know the
  how many characters we should insert in any position
4)LPS(S) = LCS(S,revserse(S))


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return n - dp[0][n - 1];
    }
};