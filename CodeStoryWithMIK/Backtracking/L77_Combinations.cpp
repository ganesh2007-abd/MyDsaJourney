#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(int idx, int n, int k, vector<int> &curr, vector<vector<int>> &ans)
    {
        if (idx == n + 1)
        {
            if (curr.size() == k)
            {
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back(idx);
        backtrack(idx + 1, n, k, curr, ans);
        curr.pop_back();
        backtrack(idx + 1, n, k, curr, ans);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(1, n, k, curr, ans);
        return ans;
    }
};