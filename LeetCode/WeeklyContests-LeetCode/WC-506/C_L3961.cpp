/*

Approach

1)to maximise the sum - we have to maximise the ratings
2)According to question -- to maximise the ratings we have an opprotunity of moving the minimums from 0/more rows to other rows
3)So to get max -- we move all min1's to row containing minimum min2
4)So basically we find the min1 and min2 of each row and also update the minofmin2 and minofmin1
5)so finally answer will be like (sum of all min2(beacasue we moved all rows min1's to row containing min min2)) - minofmin2 + minofmin1



*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxRatings(vector<vector<int>> &units)
    {
        // long long max_diff = INT_MIN;
        int m = units.size();
        int n = units[0].size();
        long long min2sum = 0;
        long long minofmin1 = INT_MAX;
        long long minofmin2 = INT_MAX;
        bool starting = true;
        long long sum = 0;
        if (n == 1)
        {
            for (int i = 0; i < m; i++)
            {
                sum += units[i][0];
            }
            return sum;
        }
        for (int i = 0; i < m; i++)
        {
            long long min1 = INT_MAX;
            long long min2 = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (units[i][j] <= min1)
                {
                    min2 = min1;
                    min1 = units[i][j];
                }
                else if (min1 < units[i][j] && min2 > units[i][j])
                {
                    min2 = units[i][j];
                }
            }
            if (starting)
            {
                minofmin1 = min1;
                minofmin2 = min2;
                starting = false;
            }
            else
            {
                minofmin1 = min(minofmin1, min1);
                minofmin2 = min(minofmin2, min2);
            }
            min2sum += min2;
        }
        return min2sum - minofmin2 + minofmin1;
    }
};