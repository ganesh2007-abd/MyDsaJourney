
/*

Approach

1)Binary string ~ Backtracking
2)contonously go on and push_back('0') using recursion call
3)at base case i.e idx==n it will stop and got added to ans and got returned
4)that will be returned to latest call i.e last digit(i=n-1) so now we pop_back() it
5)now push_back('1') and make cost as cost+idx and call recurse through again to get checked by the conditions
6)according to the conditions it may be just returned or added to string and get returned
7)so in next line we again pop_back()


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;

    void dfs(int idx, int n, int k, int cost, bool prev, string &curr)
    {
        if (cost > k)
            return;
        if (idx == n)
        {
            ans.push_back(curr);
            return;
        }
        curr.push_back('0');
        dfs(idx + 1, n, k, cost, false, curr);
        curr.pop_back();

        if (!prev)
        {
            curr.push_back('1');
            dfs(idx + 1, n, k, cost + idx, true, curr);
            curr.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k)
    {
        string curr = "";
        dfs(0, n, k, 0, false, curr);
        return ans;
    }
};