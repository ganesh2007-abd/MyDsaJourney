/*

Approach

1)two strigns are isomorphic if s1 is isomorphic to s2 and s2 is isomorphic to s1 too
2)to check each scenaria maintain a map and iterate over s1 and s2 sametime and if store t=in map like mpp[s1[i]] = s2[i]
3)at any iteration if mpp[s1[i]] exists and its not equal to s2[i] just return false
4)after repeat same process with s2 in map and s1 for checking
5)if both are valid then return true;

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool isomorphic(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        unordered_map<char, char> mpp;
        unordered_map<char, char> mpp2;
        for (int i = 0; i < s1.size(); i++)
        {
            if (mpp.find(s1[i]) == mpp.end())
            {
                mpp[s1[i]] = s2[i];
            }
            else if (mpp.find(s1[i]) != mpp.end())
            {
                char ch = mpp[s1[i]];
                if (ch != s2[i])
                    return false;
            }
        }
        for (int i = 0; i < s1.size(); i++)
        {
            if (mpp2.find(s2[i]) == mpp2.end())
            {
                mpp2[s2[i]] = s1[i];
            }
            else if (mpp2.find(s2[i]) != mpp2.end())
            {
                char ch = mpp2[s2[i]];
                if (ch != s1[i])
                    return false;
            }
        }

        return true;
    }
};