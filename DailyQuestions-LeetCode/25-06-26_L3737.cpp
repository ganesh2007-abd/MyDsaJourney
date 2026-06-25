
/*

Approach

1)sometimes you can solve the subarrays problem with checking all possible subarrays in O(n2)
2)that sometimes ->if  f([1,2,3]) == f([1,2]) + f([3]) then we solve that problem with 2 loops
3)all operations you can do in that inner for loop
4)in this problem -> majoritycount([1,2,3]) = majoritycount([1,2]) + majoritycount([3]) then we solve by iterating th enedpoint of that array

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i; j < n; j++)
            {

                if (nums[j] == target)
                    count++;

                if (count > ((j - i + 1) / 2))
                    ans++;
            }
        }
        return ans;
    }
};