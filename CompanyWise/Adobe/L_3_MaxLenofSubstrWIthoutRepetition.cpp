#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int maxcount = 1;
        int n = s.size();
        if (n == 0)
            return 0;
        unordered_map<char, int> mpp;
        int count = 0;
        int i = 0;
        int j = 0;
        while (i < n && j < n)
        {
            if (mpp.find(s[j]) != mpp.end())
            {
                if (mpp[s[j]] >= i)
                {
                    i = mpp[s[j]] + 1;
                }
                maxcount = max(maxcount, count);
                count = j - i + 1;
                mpp[s[j]] = j;
                j++;
                // unordered_map<char,int> mpp;
                // mpp[s[j]] = j;
                // j++;
            }

            else
            {
                count++;
                // st.insert(s[j]);
                mpp[s[j]] = j;
                j++;
            }
        }
        return max(maxcount, count);
    }
};