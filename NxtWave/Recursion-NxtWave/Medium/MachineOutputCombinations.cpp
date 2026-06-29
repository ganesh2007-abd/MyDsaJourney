/*

Approach

1)if we want combs and there is an array alway think like each element picking or not picking
2)so initially we will be at 0th index if that num < target we will be at same index again and call another
  recursive call by decreasing the target by num
3)here we are making the i+1 recursive call every time
4)if target == 0,dont forget to increase the counter

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void recursive(int i, int n, int target, vector<int> &arr, int &count)
    {
        if (target == 0)
        {
            count++;
            return;
        }
        if (i == n)
            return;

        if (arr[i] <= target)
        {
            recursive(i, n, target - arr[i], arr, count);
        }

        recursive(i + 1, n, target, arr, count);
    }

    int countProductionCombinations(vector<int> &machines, int target)
    {
        int n = machines.size();
        int count = 0;
        recursive(0, n, target, machines, count);
        return count;
    }
};