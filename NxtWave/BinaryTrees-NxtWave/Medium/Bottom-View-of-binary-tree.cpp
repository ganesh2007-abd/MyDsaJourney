/*

Approach

1)same as top view question -- but here we have to keep track of last found node for one particular col

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Write your code here...
        queue<pair<Node *, int>> q;
        map<int, int> mpp;
        vector<int> ans;
        q.push({root, 0});
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            Node *curr = top.first;
            int col = top.second;
            mpp[col] = curr->data;
            if (curr->left)
                q.push({curr->left, col - 1});
            if (curr->right)
                q.push({curr->right, col + 1});
        }
        for (auto &ele : mpp)
        {
            ans.push_back(ele.second);
        }
        return ans;
    }
};