#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &curr, vector<int> &nums, vector<int> &visited, vector<vector<int>> &ans)
    {
        if (curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                curr.push_back(nums[i]);
                backtrack(curr, nums, visited, ans);
                visited[i] = 0;
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> curr;
        vector<vector<int>> ans;
        vector<int> visited(nums.size(), 0);
        backtrack(curr, nums, visited, ans);
        return ans;
    }
};