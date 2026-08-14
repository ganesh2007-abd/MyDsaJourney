#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;

    int findmaxi(vector<int> &arr)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

    void backtrack(int idx, vector<int> &cookies, vector<int> &children, int &ans, int k)
    {
        if (idx == n)
        {
            ans = min(ans, findmaxi(children));
            return;
        }

        for (int i = 0; i < k; i++)
        {
            children[i] += cookies[idx];
            backtrack(idx + 1, cookies, children, ans, k);
            children[i] -= cookies[idx];
        }
    }

    int distributeCookies(vector<int> &cookies, int k)
    {
        n = cookies.size();
        int ans = INT_MAX;
        vector<int> children(k, 0);
        backtrack(0, cookies, children, ans, k);
        return ans;
    }
};