/*

Approach

1)upper bound is the least index element where that element is greater than target
2)if mid is lower or equal measn we have no use of left half because we trying to find the greater number that it so we move right
3)else that can be my potetial answer -- so stroe that and go left side

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int upperBound(int arr[], int n, int x)
    {
        // Write your code here...
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};