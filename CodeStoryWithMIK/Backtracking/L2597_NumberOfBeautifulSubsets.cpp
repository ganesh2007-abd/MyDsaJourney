// approach

/*

1)we maintian a freq map to check the presentele+k and presentele-k are already seen
2)so we first consider not_take exploration
3)for take step -- we take that element only when that element+k and eleemnt-k are present in the map or not..if both are not present the only take the
  element and do "do and undo step"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    void backtrack(int idx, vector<int> &nums, unordered_map<int, int> &mpp, int &ans, int k)
    {
        if (idx == n)
        {
            ans += 1;
            return;
        }

        backtrack(idx + 1, nums, mpp, ans, k);

        if (!mpp[nums[idx] + k] && !mpp[nums[idx] - k])
        {
            mpp[nums[idx]]++;
            backtrack(idx + 1, nums, mpp, ans, k);
            mpp[nums[idx]]--;
        }

        // s.erase(nums[idx]+k);
        // s.erase(nums[idx]-k);
        // backtrack(idx+1,nums,s,ans,k);
    }

    int beautifulSubsets(vector<int> &nums, int k)
    {
        n = nums.size();
        unordered_map<int, int> mpp;
        int ans = 0;
        backtrack(0, nums, mpp, ans, k);
        return ans - 1;
    }
};