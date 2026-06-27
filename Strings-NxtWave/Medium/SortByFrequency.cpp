/*

Approach

1)you first maintain a map and find al the characers frequencies
2)then copy them to vector and sory it in decreaing order
3)then iterate over and start producing answer

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    string mul(char c, int k)
    {
        string ans = "";
        while (k > 0)
        {
            ans += c;
            k--;
        }
        return ans;
    }
    string sortCharactersByFrequency(string s)
    {
        unordered_map<char, int> mpp;
        for (auto ch : s)
        {
            mpp[ch]++;
        }
        string res = "";
        vector<pair<char, int>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(), [](const auto &a, const auto &b)
             { return a.second > b.second; });
        for (auto &row : v)
        {
            res += mul(row.first, row.second);
        }
        return res;
    }
};