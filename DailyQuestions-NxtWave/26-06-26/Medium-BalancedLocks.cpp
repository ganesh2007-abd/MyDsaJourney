/*

Approach

1)If somthing question is on paranthesis always dont go to stack--Once just think of counter approach
2)We can try the recursive approach also for this -- refer notes
2)maintain counter count -- if '(' count++ -- if ')' count--
4)in this problem as * can serve 3 possibilties we can manage the counter as (low,high) range thing
5)if '(' low++,high++ --> if ')' low--,high-- --> if * low--,high++
6)finally afdter traversing th eenitre strign if we have a 0 in that (low,high) range -- that mean ssomewhere we
  have a scenario where counter is becoming 0 -- so retunr true -- lese false

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool balancedLocks(string s)
    {

        int n = s.size();
        // if(n==0) return true;
        int count = 0;
        int low = 0;
        int high = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                low += 1;
                high += 1;
            }
            else if (s[i] == ')')
            {
                low -= 1;
                high -= 1;
            }
            else
            {
                low -= 1;
                high += 1;
            }
            if (low == -1)
                low = 0;
            if (high == -1)
                return false;
        }
        return low == 0;
    }
};