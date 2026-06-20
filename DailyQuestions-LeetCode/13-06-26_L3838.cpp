#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string out = "";
        for (auto word : words)
        {
            int total = 0;
            for (auto ch : word)
            {
                total += weights[ch - 97];
            }
            total = total % 26;
            // return to_string(total);
            out += char(97 + 26 - total - 1);
        }
        return out;
    }
};