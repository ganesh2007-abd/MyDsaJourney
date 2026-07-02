/*

Approach

1)we have to find the min element which is greater than or equal the given element
2)if our mid is smaller move right
3)else (mid >= x) -- then that elelemtn can be our potential answer -- and move left side


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int lowerBound(int arr[], int n, int x)
    {
        // Write your code here...
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] < x)
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