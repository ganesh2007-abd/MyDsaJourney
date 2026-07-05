/*

Approach

1)you dont need all bits at a time..to check no of flips we just want that corresponding x bit,y bit,and z bit
2)so run nitmanipulation forloop -- means accessing rightmost bit and rightshifing th number -- lastbit = x&1 then x=x>>1;
3)so firt take the rightmost bits of 3 numbers -- then check if z bit is 1 then the probem comes only when x any y bits are 0..so we handle only that case -- and increment count for that case
4)if z bit is 0..we have to flip if even one of the otherbits is 1 -- so we do count += x + y;

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int minBitFlips(int x, int y, int z)
    {
        // Write your code here...
        int count = 0;
        while (x != 0 || y != 0 || z != 0)
        {
            int xb = x & 1;
            int yb = y & 1;
            int zb = z & 1;

            if (zb == 1)
            {
                if (xb == 0 && yb == 0)
                {
                    count++;
                }
            }
            else
            {
                count += xb + yb;
            }

            x = x >> 1;
            y = y >> 1;
            z = z >> 1;
        }
        return count;
    }
};