/*

Approach

1)the speed can goes freom eating 1 banana per hour or max(arr[]) perhour
2)so we do binary search on that array and find the hrs with that mid speed according ti tu move to left or right

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int minimumBananas(int arr[], int n, int h)
    {
        // Write your code here...
        int maxi;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
        }
        int ans = maxi;
        int low = 1;
        int high = maxi;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // int m=arr[mid];
            int hrs = 0;
            for (int i = 0; i < n; i++)
            {
                hrs += (arr[i] + mid - 1LL) / mid;
            }
            // if(hrs == h) return mid;
            if (hrs <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};