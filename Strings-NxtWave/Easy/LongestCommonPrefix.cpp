/*

Approach

1)We place the pointers at start position of each string
2)at each position we check if all are equal
3)if yes add that common character to the ans
4)if not just return that ans

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    string longest_common_prefix(vector<string> &words)
    {
        string ans = "";
        int n = INT_MAX;
        if (words.size() == 0)
            return ans;
        for (auto str : words)
        {
            // n=min(n,str.length());
            if (n >= str.length())
                n = str.length();
        }
        for (int i = 0; i < n; i++)
        {
            char ch = words[0][i];
            bool common = true;
            for (int j = 1; j < words.size(); j++)
            {
                if (words[j][i] != ch)
                {
                    common = false;
                    return ans;
                }
            }
            if (common)
            {
                ans += ch;
            }
        }
        return ans;
    }
};