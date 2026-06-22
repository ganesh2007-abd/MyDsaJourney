/*

Approach

1)use map and insert initially the letters 'balon' to 0
2)iterate over the the given string and if that ch is found in map then only increament the number in map
3)do half the counter of letters 'l' and 'o' because they repeat twice
4)now in those 5 elements find the min one and return it

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        map<char, int> mpp;
        mpp['a'] = 0;
        mpp['b'] = 0;
        mpp['l'] = 0;
        mpp['n'] = 0;
        mpp['o'] = 0;
        // for(int i=0;i<5;i++){
        //     cout<<mpp[i]<<endl;
        // }
        for (int i = 0; i < text.size(); i++)
        {
            if (mpp.find(text[i]) != mpp.end())
            {
                mpp[text[i]]++;
            }
        }
        // for(int i=0;i<5;i++){
        //     cout<<mpp[i]<<endl;
        // }
        mpp['l'] /= 2;
        mpp['o'] /= 2;
        string word = "balon";
        int mini = mpp['a'];
        for (auto ch : word)
        {
            cout << "entered";
            mini = min(mini, mpp[ch]);
        }
        return mini;
    }
};