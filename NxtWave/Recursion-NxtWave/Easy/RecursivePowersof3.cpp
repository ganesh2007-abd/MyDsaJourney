/*

Approach

1)recurive multiply the number by 3 and check base case -- if > goal return
2)before recursive call add it to the vector
3)then call rersuve call


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void recursive(int goal, int num, vector<int> &ans)
    {
        if (num > goal)
            return;
        ans.push_back(num);
        recursive(goal, num * 3, ans);
    }

    vector<int> generatePowersOf3(int n)
    {
        vector<int> ans;
        recursive(n, 1, ans);
        return ans;
    }
};