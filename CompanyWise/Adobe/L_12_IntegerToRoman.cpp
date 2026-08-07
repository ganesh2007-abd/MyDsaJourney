#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int n = nums.size();
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            while (num >= nums[i])
            {
                num -= nums[i];
                ans += symbols[i];
            }
        }
        return ans;
    }
};