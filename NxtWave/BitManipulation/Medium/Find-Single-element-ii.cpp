/*

Approach

1)they said that every other numbrs are repeating 3 times
2)so lets think bitwise -- for each bit column of all those numbers lets bother about set bits
3)if the single element bit is 1 then bitsum of that bitcolumn will be of tee -- 3n+1 beacasue
4)if that bit is zero then bitsum will be of from 3n
5)So there are only 2 possibbilties for bitsum i.e 3n or 3n+1
6)we have count all the 32 bits if each number becase we want to trailing zeroes also
7)we run outer for loop of 32 times -- and start counting bitsum --
8)we can acces the bit of ith col as --> (thatnum >> i) & 1 -- then find the modulo of 3 -- and whatever it is that is the bit we want to add to answer
9)now how to add that bit to answer --> we got our ith bit ,now we do left shift by i bits -- and do or operation with answer
10)eg. if ans upto that point is 100 and we got the fourth bit as 1 -- so now we do left shift by 3 times and it will become -- 1000 -- so now do or blw them and again store ut in ans

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int singleNumber(vector<int> &arr)
    {
        // Write your code here...
        int ans = 0;
        int bit;
        for (int i = 0; i < 32; i++)
        {
            int bitsum = 0;
            for (auto num : arr)
            {
                bitsum += (num >> i) & 1;
            }
            bit = bitsum % 3;
            ans = ans | (bit << i);
        }
        return ans;
    }
};