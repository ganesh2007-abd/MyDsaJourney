/*

Approach

1)given that array is already sorted then place 2 pointers at 2 ends
2)calculate their sum and comapre with target and move those 2 pointers accordingly
3)finally return those indices if their sum equal to target

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> twoSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            if (arr[i] + arr[j] < target)
            {
                i++;
            }
            else if (arr[i] + arr[j] > target)
            {
                j--;
            }
            else
            {
                return {i + 1, j + 1};
            }
        }
        return {-1, -1};
    }
};