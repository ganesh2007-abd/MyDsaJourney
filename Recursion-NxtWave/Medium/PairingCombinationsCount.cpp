/*

Approach

1)always try to break down the problem -- for suppose we have to find the f(n) here so first try to find the base cases
2)if there is only 1 person(n=1) the event can be conducted in 1 way
3)if there are 2 persons (n=2),the event can be conducted in 2 ways -- i)both remaining single ii)they pai together
4)so now think of recursive relation
5)our aim is to write the f(n) inters of lower terms like f(n-1),..
6)SO first take small number n=3,f(3) can be said as (descision of 3rd person) + f(n-1) right
7)If his decision is to remain single then evnent simply let the remaining n-1 people to decide which mean f(n-1)
8)if he wants to pair -- if he pairs with one person the evnt will let remaining n-2 people to chose themseolves..
  like that that last person can choose n-1 persons to pairup -- so at each scenario combs are f(n-2) --
  So total -- f(n-2)*n-1
9)Recurrence relation -- f(n) = f(n-1) + (n-1)*f(n-2)

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    long long recursive(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        return recursive(n - 1) + (n - 1) * recursive(n - 2);
    }

    long long calculatePairingWays(int n)
    {
        return recursive(n);
    }
};