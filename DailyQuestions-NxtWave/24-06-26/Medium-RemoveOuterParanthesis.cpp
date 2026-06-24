/*


Approach

1)Maintain a variable cnt <--> if you encounter '(' do cnt++ <--> else cnt--
2)the count after traversing the entire primitive paranthesis is 0
3)while traversing if the (cnt!=0) add that into ans;
4)if leftbracket --> if cnt != 0 --> add to ans -->cnt++
5)if rightbracket --> cnt-- --> if cnt != 0 --> add to ans


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    string removeOutermostParentheses(string s)
    {
        // Write your code here...
        //  string ans="";
        //  int start;
        //  int end;
        //  int tp;
        //  stack<int> st;
        //  for(int i=0;i<s.size();i++){
        //      // cout<<"into loop"<<endl;
        //      if(s[i] == '('){
        //          // cout<<"added to stack"<<endl;
        //          st.push(i);
        //      }
        //      else if(s[i] == ')'){
        //          tp = st.top();
        //          end = i;
        //          // cout<<"Popped from stack"<<endl;
        //          st.pop();
        //          if(st.empty()){
        //              start = tp;
        //              end = i-1;
        //              ans += s.substr(start+1,end-start);
        //          }
        //      }

        // }

        string ans = "";
        int count = 0;
        for (auto ch : s)
        {
            if (ch == '(')
            {
                if (count != 0)
                {
                    ans += ch;
                }
                count++;
            }
            else if (ch == ')')
            {
                count--;
                if (count != 0)
                {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};