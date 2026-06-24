#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int maxProfit(vector<int> &arr, int k)
    {

        int n = arr.size();
        vector<vector<int>> front(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int trans = 1; trans <= k; trans++)
            {
                curr[0][trans] = max(arr[i] + front[1][trans - 1], front[0][trans]);
                curr[1][trans] = max(front[1][trans], -arr[i] + front[0][trans]);
            }
            front = curr;
        }

        return curr[1][k];
    }
};