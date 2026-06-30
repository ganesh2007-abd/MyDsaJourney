/*


Approach

1)Keep track of arr[i] in the hash map becaue the look up in hash map is O(1)


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> twoSum(vector<int> &arr, int k)
    {
        unordered_map<int, int> mpp;
        int n = arr.size();
        int res;
        for (int i = 0; i < n; i++)
        {
            res = k - arr[i];
            if (mpp.find(res) != mpp.end())
            {
                return {mpp[res], i};
            }
            mpp[arr[i]] = i;
        }
        return {-1, -1};
    }
};