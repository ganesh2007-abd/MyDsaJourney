/*

Approach

1)place 2 pointers i and j at last of each string
2)if i>= 0 add that char to ans and same if j>=0
3)carry is obtained by add/2
4)and theresult to be concatenated to string is add%2 which is same as add&1
5)every time canacatenate that char using while loop by ans = thatcha + ans


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    string addTwoBinaryStrings(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        int i = n1 - 1;
        int j = n2 - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0)
        {
            int add = carry;
            if (i >= 0)
            {
                add += (s1[i] - '0');
                i--;
            }
            if (j >= 0)
            {
                add += (s2[j] - '0');
                j--;
            }

            ans = char((add & 1) + '0') + ans;
            carry = (add >> 1);
        }
        if (carry == 1)
        {
            ans = '1' + ans;
        }
        return ans;
    }
};