/*

check out approach in my notebook

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> front(2, 0);
        vector<int> curr(2);

        for (int i = n - 1; i >= 0; i--)
        {
            curr[0] = max(arr[i] + front[1], front[0]);
            curr[1] = max(-arr[i] + front[0], front[1]);
            front = curr;
        }
        return front[1];
    }
};