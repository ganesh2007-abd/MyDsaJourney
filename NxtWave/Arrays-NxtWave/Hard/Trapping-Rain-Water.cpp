/*

Approach

1)For finding tha mount of water on soem blick you just need the leftmax and rightamx upto to that point and calculate water according to min of thoses max's
2)So place the left and right pointers at 2 ends -- so at each iteration we update the left and right max values
3)So during updation -- we check if arr[left] < leftmax and its rightmax >= leftmax(means the water is decided by leftmax only) -- water = leftmax-arr[left]
  if arr[left] > leftmax we simply update the leftmax
4)same updation for rigthmax and returnwater

**********More explanation on notes

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int trapRainwater(vector<int> &arr)
    {
        // Write your code here...
        int n = arr.size();
        int water = 0;
        int left = 0;
        int right = n - 1;
        int leftmax = 0;
        int rightmax = 0;
        while (left <= right)
        {
            if (leftmax <= rightmax)
            {
                if (leftmax <= arr[left])
                {
                    leftmax = arr[left];
                }
                else
                {
                    water += leftmax - arr[left];
                }
                left++;
            }
            else
            {
                if (rightmax <= arr[right])
                {
                    rightmax = arr[right];
                }
                else
                {
                    water += rightmax - arr[right];
                }
                right--;
            }
        }
        return water;
    }
};