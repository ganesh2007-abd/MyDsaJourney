#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void print1toNInAscendingOrder(int n)
    {
        if (n == 0)
            return;
        print1toNInAscendingOrder(n - 1);
        cout << n << endl;
    }
};