#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void recursive(int i, int n, vector<int> &arr, vector<int> &curr, vector<vector<int>> &ans)
    {
        if (i == n)
        {
            ans.push_back(curr);
            return;
        }
        curr.push_back(arr[i]);
        recursive(i + 1, n, arr, curr, ans);
        curr.pop_back();
        recursive(i + 1, n, arr, curr, ans);
    }

    vector<vector<int>> powerSet(vector<int> &arr)
    {
        // Write your code here...
        vector<vector<int>> ans;
        vector<int> curr;
        int n = arr.size();
        recursive(0, n, arr, curr, ans);
        return ans;
    }
};