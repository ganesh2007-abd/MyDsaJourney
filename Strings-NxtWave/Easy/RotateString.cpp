/*

Approach

1)we rotate the string by each character and at each itration check is its equal to target
2)to rotate a string we do iterate the start variable from 1 to length and slice it like s[start:] + s[:start]

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool rotateString(string s, string target)
    {
        if (s.length() != target.length())
            return false;
        if (s == target)
            return true;
        int n = s.size();
        int start;

        for (int i = 0; i < n - 1; i++)
        {
            start = i + 1;
            if ((s.substr(start) + s.substr(0, start)) == target)
                return true;
            ;
        }
        return false;
    }
};