/*

Note:
& has less precedence than ==

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumOfGoodIntegers(int n, int k)
    {
        int ans = 0;
        for (int x = min(n - k, n + k); x <= max(n - k, n + k); x++)
        {
            if (((n & x) == 0) && (x > 0))
            {
                ans += x;
            }
        }
        return ans;
    }
};