/*

Approach

1)if there is a peak element means the slope tren will be like inc and then dec
2)first check if mid element is grater than adjacent 2 elements if yeas return that
3)otherwise with go will the slope direction
4)slope direction can be decided by arr[mid] ,arr[mid+1],arr[mid-1] in whihc path its value is increasing we see that half

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int findPeakElement(int arr[], int n)
    {
        // Write your code here..
        if (n == 1)
            return 0;
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;

        int low = 1;
        int high = n - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            {
                return mid;
            }
            else if (arr[mid] > arr[mid + 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};