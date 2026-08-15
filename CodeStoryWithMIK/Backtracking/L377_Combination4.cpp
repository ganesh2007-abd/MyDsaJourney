#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int backtrack(int idx, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return 1;
        }
        if (target < 0 || idx == nums.size())
        {
            return 0;
        }
        if (dp[target][idx] != -1)
        {
            return dp[target][idx];
        }
        int take = backtrack(0, nums, target - nums[idx], dp);
        int not_take = backtrack(idx + 1, nums, target, dp);
        return dp[target][idx] = take + not_take;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        // int curr = 0;
        // int ans =0;
        vector<vector<int>> dp(target + 1, vector<int>(nums.size() + 1, -1));
        return backtrack(0, nums, target, dp);
        // return ans;
    }
};