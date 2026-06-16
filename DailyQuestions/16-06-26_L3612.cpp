#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string processStr(string s)
    {
        string res;
        for (auto ch : s)
        {
            if (ch >= 97 && ch <= 122)
            {
                res += ch;
            }
            else if (ch == '*')
            {
                if (res.size() != 0)
                {
                    res.pop_back();
                }
            }
            else if (ch == '#')
            {
                res += res;
            }
            else if (ch == '%')
            {
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};