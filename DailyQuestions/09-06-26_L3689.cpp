

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int maxidx = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[maxidx])
            {
                maxidx = i;
            }
        }
        long long l = maxidx - 1;
        long long r = maxidx + 1;
        long long minidxleft = l;
        long long minidxright = r;
        long long leftdiff = 0;
        long long rightdiff = 0;
        while (l >= 0)
        {
            if (nums[minidxleft] > nums[l])
            {
                minidxleft = l;
            }
            l--;
        }
        if (minidxleft >= 0)
        {
            leftdiff = nums[maxidx] - nums[minidxleft];
        }
        while (r < nums.size())
        {
            if (nums[minidxright] > nums[r])
            {
                minidxright = r;
            }
            r++;
        }
        if (minidxright < nums.size())
        {
            rightdiff = nums[maxidx] - nums[minidxright];
        }
        return max(leftdiff, rightdiff) * k;
    }
};