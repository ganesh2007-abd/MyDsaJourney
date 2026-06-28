/*

Approach

1)As we want to find the max possible element in the array we always should be move towars +1 number groups
2)so if the arr[i] - arr[i-1] >= 1 that means the rule is violating so we should make the arr[i] to be arr[i-1]+1
3)always update the maxi at every iteration and return the maxi



*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        arr[0] = 1;
        int maxi = arr[0];
        int n = arr.size();

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] >= 1)
            {
                arr[i] = arr[i - 1] + 1;
            }
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
};