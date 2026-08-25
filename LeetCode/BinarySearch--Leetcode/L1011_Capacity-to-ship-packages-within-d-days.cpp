/*

Approach

1)low will be maximum of weights -- just think if the maximum wieght is 7 can the ship has wieght of 6,,the bare minimum wieght will be maximum weightest element
2)high will be ofcourse the sum of weights of alla elements as the ship may carry all packages in one go..


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool f(int capacity, vector<int> &weights, int days)
    {
        int n = weights.size();
        int currdays = 1;
        int wt = 0;
        for (int i = 0; i < n; i++)
        {
            if (wt + weights[i] > capacity)
            {
                wt = 0;
                currdays++;
            }
            wt += weights[i];
        }
        return currdays <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        // sort(weights.begin(),weights.end());
        int n = weights.size();
        int low = 0;
        int high = 0;
        for (int w : weights)
        {
            low = max(low, w);
            high += w;
        }
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (f(mid, weights, days))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};