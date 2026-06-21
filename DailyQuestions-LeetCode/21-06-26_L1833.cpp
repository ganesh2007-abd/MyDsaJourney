#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int count = 0;
        int tcost = 0;
        int n = costs.size();
        sort(costs.begin(), costs.end());
        for (int i = 0; i < n; i++)
        {
            tcost += costs[i];
            if (tcost <= coins)
                count++;
            else
            {
                break;
            }
        }
        return count;
    }
};