/*

Approach

1)maintain a alt variable refering to altitude
2)add each gain to the altitude and find the max in that loop itself
3)at last as alt cant be zero return max(0,maximum)


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        if (gain.size() == 0)
            return 0;
        int alt = 0;
        int maximum = INT_MIN;
        for (auto g : gain)
        {
            alt += g;
            maximum = max(maximum, alt);
        }
        return max(0, maximum);
    }
};