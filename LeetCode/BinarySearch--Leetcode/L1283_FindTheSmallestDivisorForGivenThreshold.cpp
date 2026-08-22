#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int func(int x, vector<int> &nums)
    {
        int res = 0;
        for (auto num : nums)
        {
            res += (num + x - 1) / x;
        }
        return res;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int high = INT_MIN;
        for (auto num : nums)
        {
            high = max(high, num);
        }
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int res = func(mid, nums);
            if (res <= threshold)
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