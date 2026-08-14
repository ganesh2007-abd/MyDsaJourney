#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(int idx, vector<int> &nums, vector<int> &curr, vector<vector<int>> &res, int n)
    {
        if (curr.size() >= 2)
        {
            res.push_back(curr);
        }
        unordered_set<int> st;
        for (int i = idx; i < n; i++)
        {
            if ((curr.empty() || nums[i] >= curr.back()) && (st.find(nums[i]) == st.end()))
            {
                curr.push_back(nums[i]);
                f(i + 1, nums, curr, res, n);
                curr.pop_back();
                st.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        // int n=nums.size();
        vector<int> curr;
        f(0, nums, curr, res, n);
        // for(int i=0;i<n;i++){
        //     vector<int> curr;
        //     for(int j=i;j<n;j++){
        //         curr.push_back(nums[j]);
        //         if(curr.size() > 1){
        //             res.push_back(curr);
        //         }
        //     }
        // }
        return res;
    }
};