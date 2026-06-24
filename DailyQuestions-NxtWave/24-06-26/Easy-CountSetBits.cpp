/*



Approach -- DP

1)the no of set bits for x is said to be as setbits in x/2 + (lastbit in x)
2)because when we do x/2 the last bit got eliminated and that value is giben by (i&1)
3)arr[x]=arr[x/2] + (x&1)


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> countSetBits(int n)
    {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};