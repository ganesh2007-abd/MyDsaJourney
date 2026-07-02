/*

Approach

1)so whenever we got sorted type of array thing first we have to encounter wheather bs is applicable
2)so every time returning mig is almost common whats dificult if after finding arr[mid] in which side we have to go is main problem
3)in this problem the deciding is based on position of mid element and position of its duplicate


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int findSingleElement(int arr[], int n)
    {
        // Write your code here...
        if (n == 1)
            return arr[0];
        int low = 1;
        int high = n - 2;
        if (arr[0] != arr[1])
            return arr[0];
        if (arr[n - 1] != arr[n - 2])
            return arr[n - 1];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
                return arr[mid];
            if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
                (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};