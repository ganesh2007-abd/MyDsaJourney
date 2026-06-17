/*

Approach

1)we do reverse simulation because we cant build entire string due to memory issues
2)To undo the effect of '#' will be searching in length (l/2) and now the effective k was (k-l/2)
3)to undo the effect of '%' which means befrep the effect of '%',we have same length l and k=L-K-1
4)To undo the effect of '*' theta means result before iterating over * the length increase by 1(l++) and k remains same
5)To undo the effect of letter we decrease the length by one and check if (k==l) we got our s[i] return it



*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char processStr(string s, long long k)
    {
        int n = s.length();

        long long L = 0;

        for (char &ch : s)
        {
            if (ch == '*')
            {
                if (L > 0)
                    L--;
            }
            else if (ch == '#')
            {
                L *= 2;
            }
            else if (ch == '%')
            {

                continue;
            }
            else
            {
                L++;
            }
        }

        if (k >= L)
        {
            return '.';
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '*')
            {
                L++;
            }
            else if (s[i] == '%')
            {

                k = L - k - 1;
            }
            else if (s[i] == '#')
            {
                L = L / 2;
                k = (k >= L) ? k - L : k;
            }
            else
            {
                L--;
            }

            if (k == L)
            {
                return s[i];
            }
        }

        return '.';
    }
};