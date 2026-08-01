#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int n = s.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                ans += mpp[s[i]];
            }
            else
            {
                if (mpp[s[i]] < mpp[s[i + 1]])
                {
                    ans -= mpp[s[i]];
                }
                else
                {
                    ans += mpp[s[i]];
                }
            }
        }
        return ans;
    }
};