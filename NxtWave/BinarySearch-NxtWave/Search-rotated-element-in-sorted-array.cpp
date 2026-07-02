/*


Approach

1)whenever we find a mid element one side is alway ssorted and another side alwas unsorted
2)so first check which half is sorted and which is not
3)in sorted half try cheking th etarget lies in that range .if goes go to that side else go to unsorted side


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int searchRotatedSorted(int arr[], int n, int x)
    {
        // Write your code here...
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
                return mid;
            else if (arr[mid] > arr[low])
            {
                if (x >= arr[low] && x <= arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (x >= arr[mid] && x <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};