#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        int cnt = 0;
        int prev = 0, curr = 0;
        while (cnt <= (m + n) / 2)
        {
            prev = curr;
            if (i < m && j < n)
            {
                if (nums1[i] <= nums2[j])
                {
                    curr = nums1[i];
                    i++;
                }
                else
                {
                    curr = nums2[j];
                    j++;
                }
            }
            else if (i < m)
            {
                curr = nums1[i];
                i++;
            }
            else
            {
                curr = nums2[j];
                j++;
            }
            cnt++;
        }
        if ((m + n) % 2 == 0)
            return (prev + curr) / 2.0;
        return curr;
    }
};