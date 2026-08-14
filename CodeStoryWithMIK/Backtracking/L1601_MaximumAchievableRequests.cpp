#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isfull(vector<int> &buildings)
    {
        for (int i = 0; i < buildings.size(); i++)
        {
            if (buildings[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    void backtrack(int idx, vector<vector<int>> &requests, vector<int> &buildings, int cnt, int &ans)
    {
        if (idx == requests.size())
        {
            if (isfull(buildings))
            {
                // cnt += 1;
                ans = max(ans, cnt);
            }
            return;
        }
        int s = requests[idx][0];
        int e = requests[idx][1];

        buildings[s]--;
        buildings[e]++;
        backtrack(idx + 1, requests, buildings, cnt + 1, ans);
        buildings[s]++;
        buildings[e]--;
        backtrack(idx + 1, requests, buildings, cnt, ans);
    }

    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        vector<int> buildings(n, 0);
        int ans = INT_MIN;
        int cnt = 0;
        backtrack(0, requests, buildings, cnt, ans);
        return ans;
    }
};