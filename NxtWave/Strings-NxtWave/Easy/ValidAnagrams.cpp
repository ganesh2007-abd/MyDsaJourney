/*

Approach

1)we maintai a freq counter having length 26 for 26 alphabtes
2)iterate over the string 1 and increase the counter
3)on iterating the string 2 decrease the counter
4)iterate over the counter array and check if all elemtnsare 0,if yesreturn reu,else false

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool validAnagram(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;

        int arr[26] = {0};

        for (auto ch : s1)
        {
            arr[ch - 'a']++;
        }
        for (auto ch : s2)
        {
            arr[ch - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
                return false;
        }
        return true;
    }
};