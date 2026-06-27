#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool recursive(string s, int i, int j)
    {
        if (i >= j)
            return true;
        if (s[i] != s[j])
            return false;
        else
        {
            return recursive(s, i + 1, j - 1);
        }
    }

    bool checkPalindrome(string s)
    {
        int n = s.length();
        return recursive(s, 0, n - 1);
    }
};