/*

Approach

1)Kadanes algorithm
2)start traversing the array -- add each element to the array
3)update the maxsum in each traversal
4)when we got a sum < 0 simply make the sum = 0 and continue traversal

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int largestSubarraySum(vector<int> &arr)
    {
        // Write your code here...
        int sum = 0;
        int n = arr.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (maxi < sum)
            {
                maxi = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
            // maxi = max(maxi,sum);
        }
        return maxi;
    }
};