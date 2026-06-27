/*
Approach

1)Just use string stream in cpp and fecth the strings one by one and stroe it in the array
2)by iterating the array in reverse we append each string with a space charater to ans
3)as we dont need the last space just siply pop_back() that character

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    string reverseWords(string text)
    {
        stringstream ss(text);
        string word;
        vector<string> words;
        while (ss >> word)
        {
            words.push_back(word);
        }
        int n = words.size();
        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            ans += words[i] + ' ';
        }
        ans.pop_back();
        return ans;
    }
};