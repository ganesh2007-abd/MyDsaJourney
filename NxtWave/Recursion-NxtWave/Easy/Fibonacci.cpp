/*
Recuriosn with memoisation

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    long long fib(int n)
    {
        vector<long long> dp(n + 1, -1);
        return fibonacci(n, dp);
    }

    long long fibonacci(int n, vector<long long> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);

        return dp[n];
    }
};