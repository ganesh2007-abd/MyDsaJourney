/*

Approach

1)in this problem keep low as 1 and high as m
2)find the middle elelemnt check its nth power -- if its grater we have to move left otherwise we move right side
3)if its nth power is equal to m return mid other wise return -1

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int findNthrootofM(int n, int m)
    {
        // Write your code here...
        int low = 1;
        int high = m;
        while (low <= high)
        {
            int mid = low + high / 2;
            int num = pow(mid, n);
            if (num == m)
                return mid;
            else if (num < m)
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