#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // string findlcs(string s1,string s2){
    //     int m=s1.size();
    //     int n=s2.size();
    //     vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    //     for(int i=1;i<=m;i++){
    //         for(int j=1;j<=n;j++){
    //             if(s1[i-1] == s2[j-1]){
    //                 dp[i][j] = 1+dp[i-1][j-1];
    //             }
    //             else{
    //                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    //             }
    //         }
    //     }
    //     int i=m;
    //     int j=n;
    //     string ans="";
    //     while(i>0 && j>0){
    //         if(s1[i-1]==s2[j-1]){
    //             ans.push_back(s1[i-1]);
    //             i--;
    //             j--;
    //         }
    //         else if(dp[i-1][j] > dp[i][j-1]){
    //             i--;
    //         }
    //         else{
    //             j--;
    //         }
    //     }
    //     return ans;
    // }

    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int startidx = 0;
        int maxlen = 1;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        for (int i = 0; i + 1 < n; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                startidx = i;
                maxlen = 2;
            }
        }
        for (int len = 3; len <= n; len++)
        {
            for (int st = 0; st + len - 1 < n; st++)
            {
                int end = st + len - 1;
                if (s[st] == s[end] && dp[st + 1][end - 1])
                {
                    dp[st][end] = true;
                    if (len > maxlen)
                    {
                        maxlen = max(len, maxlen);
                        startidx = st;
                    }
                }
            }
        }
        return s.substr(startidx, maxlen);
    }
};