#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans(2);
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            if (mpp.find(target - nums[i]) != mpp.end())
            {
                ans[0] = i;
                ans[1] = mpp.find(target - nums[i])->second;
                return ans;
            }
            else
            {
                mpp[nums[i]] = i;
            }
        }
        return {};
    }
};