#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int recursionSum(int n)
    {
        if (n == 1)
            return 1;
        return n + recursionSum(n - 1);
    }
};