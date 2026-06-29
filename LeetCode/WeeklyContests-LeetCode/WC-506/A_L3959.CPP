#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkGoodInteger(int n)
    {
        long long ds = 0;
        long long ss = 0;
        while (n > 0)
        {
            ds += n % 10;
            ss += pow((n % 10), 2);
            n = n / 10;
        }
        return (ss - ds) >= 50 ? true : false;
    }
};