/*

Approach

1)here we have to keep track of 1st node of each level and push that to ans

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
    vector<int> leftView(Node *root)
    {
        if (root == NULL)
            return {};
        // Write your code here...
        queue<Node *> q;
        vector<int> ans;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            bool starting = true;
            int temp;
            for (int i = 0; i < len; i++)
            {
                Node *curr = q.front();
                if (starting)
                {
                    temp = curr->data;
                    starting = false;
                }
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};