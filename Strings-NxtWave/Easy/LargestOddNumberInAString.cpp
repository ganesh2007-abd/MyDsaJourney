/*

Approach

1)to be a odd number the last digit should be odd right!
2)to get the largest among them we have to let it as many digits on front of that last digit
3)so we traverse from last if its even pop_back() the last character adn if its odd simply return

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    string largestOddNumber(string s)
    {
        int n = s.length();
        int i = n - 1;
        string ans = s;
        while (i >= 0)
        {
            if (int(s[i]) % 2 == 1)
            {
                return ans;
            }
            else
            {
                ans.pop_back();
            }
            i--;
        }
        return "";
    }
};
