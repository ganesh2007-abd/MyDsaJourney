/*

Approach

1)for each hour, hour hand rotates 30deg.So find total fractional hours and multiply with it and find angle with 12
2)Same for minute hand,it rotates 6deg permin.so find total angle made by it with 12
3)Subtract them to get angle containe din blw them!if > 360 return 360-ans


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double houroffset = hour + (double)minutes / 60.00;
        cout << (double)minutes / 60.00;
        double anglebyhourhand = (houroffset * 30);
        if (anglebyhourhand >= 360)
        {
            anglebyhourhand = anglebyhourhand - 360;
        }
        double anglebyminuteshand = (minutes * 6);
        cout << anglebyhourhand << anglebyminuteshand;
        return min(abs(anglebyhourhand - anglebyminuteshand), 360 - abs(anglebyhourhand - anglebyminuteshand));
    }
};