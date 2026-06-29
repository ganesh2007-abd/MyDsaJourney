#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void print1toNInDescendingOrder(int n)
    {
        if (n == 0)
            return;
        cout << n << endl;
        print1toNInDescendingOrder(n - 1);
    }
};