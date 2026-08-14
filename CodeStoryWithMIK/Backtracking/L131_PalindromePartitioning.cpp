#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispalindrome(string s, int start, int end)
    {
        int i = start;
        int j = end;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void backtrack(int idx, string &s, vector<string> &curr, vector<vector<string>> &res)
    {

        if (idx == s.size())
        {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (ispalindrome(s, idx, i))
            {
                curr.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, s, curr, res);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(0, s, curr, res);
        return res;
    }
};