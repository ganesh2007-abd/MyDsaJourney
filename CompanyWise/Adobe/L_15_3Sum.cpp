#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            unordered_set<int> s;
            for (int j = i + 1; j < n; j++)
            {
                int x = -(arr[i] + arr[j]);
                if (s.find(x) != s.end())
                {
                    ans.insert({arr[i], x, arr[j]});
                }
                s.insert(arr[j]);
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};