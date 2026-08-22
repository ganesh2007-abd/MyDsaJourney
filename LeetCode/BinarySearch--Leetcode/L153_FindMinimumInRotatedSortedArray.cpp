/*

Approach

1)when ever you find the question on rotated sorted array always think of binary search
2)and first pattern to come to mid is checking wheather the left half is sorted or not
3)in this question we check the left half is sorted or not ..if yes the potential ans will be nums[low] and after that we dont want the left half of array
4)if the left half is not sorted then the potential answer will be nums[mid] and we dont want that right scrapp so eliminate it



*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else if (nums[mid] <= nums[high])
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};