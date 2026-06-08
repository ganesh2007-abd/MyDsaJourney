/*

Approach - 1 (My Approach)

1)We have to place the elements less than pivot to the left side of pivot in same order they occured
2)We have to place the elements greater than pivot to the right side of pivot in same order they occured

3)So first we count how many elements equal to pivot are there?
4)Also find the pos(ep) by counting no of elements less than pivot

5)Then first place the pivot elements according to (ep) | -- | nums[ep++] = that element

6)Manintain a lp = 0 and make lp++ every time you insert it
6)Then by again traverse the array and if element is less than pivot place nums[lp++] = that element | -- | other wise nums[ep++] = that element

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &arr, int pivot)
    {

        vector<int> nums(arr.size());

        int lp = 0;
        int ep = 0;
        int count = 0;

        for (auto it : arr)
        {
            if (it < pivot)
            {
                ep++;
            }
            else if (it == pivot)
            {
                count++;
            }
        }

        for (int j = 0; j < count; j++)
        {
            nums[ep++] = pivot;
        }

        for (auto it : arr)
        {
            if (it < pivot)
            {
                nums[lp++] = it;
            }
            else if (it > pivot)
            {
                nums[ep++] = it;
            }
        }

        return nums;
    }
};