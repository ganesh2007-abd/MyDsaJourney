#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int assignCookies(vector<int> &greed, vector<int> &sizes)
    {
        sort(greed.begin(), greed.end());
        sort(sizes.begin(), sizes.end());

        int i = 0;
        int j = 0;

        int m = greed.size();
        int n = sizes.size();
        int count = 0;

        while (i < m && j < n)
        {
            if (greed[i] <= sizes[j])
            {
                i++;
                j++;
                count++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};
