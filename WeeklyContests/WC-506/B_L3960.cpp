#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLength(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            map<int, int> freq;
            vector<int> cntoffreq(n + 1, 0);
            int maxfrq = 0;
            for (int j = i; j < n; j++)
            {
                int x = nums[j];
                if (freq[x] > 0)
                {
                    cntoffreq[freq[x]]--;
                }
                freq[x]++;
                cntoffreq[freq[x]]++;
                maxfrq = max(maxfrq, freq[x]);
                if (freq.size() == 1)
                    ans = max(ans, j - i + 1);
                int half = maxfrq / 2;
                if (maxfrq % 2 == 0 && cntoffreq[half] + cntoffreq[maxfrq] == freq.size() && cntoffreq[half] > 0)
                {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};