/*

Approach


**need just intuition to move on
1)To handle the duplicate elements we first sort the array
2)we use backtracking method to cover all possibilitis
3)we first add one element using the forloop and check if its hitting the required conditions using recurisve call
4)then we pop that element and add another element and so on cntinue



*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void backtrack(int start, vector<int> &arr, vector<int> &templist, int remain, vector<vector<int>> &result)
    {
        if (remain < 0)
            return;
        if (remain == 0)
        {
            result.push_back(templist);
            return;
        }

        for (int i = start; i < arr.size(); i++)
        {
            if (i > start && arr[i] == arr[i - 1])
                continue;
            templist.push_back(arr[i]);
            backtrack(i + 1, arr, templist, remain - arr[i], result);
            templist.pop_back();
        }
    }

    vector<vector<int>> findUniqueCombinations(int n, vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        vector<int> templist;
        vector<vector<int>> result;
        backtrack(0, arr, templist, target, result);
        return result;
    }
};