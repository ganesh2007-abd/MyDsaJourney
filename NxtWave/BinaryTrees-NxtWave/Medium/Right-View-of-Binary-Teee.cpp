/*

Approach

1)use bfs and while traversing every level keep only track of last element int hat level

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
    vector<int> rightView(Node *root)
    {
        // Write your code here...
        if (root == NULL)
            return {};
        queue<Node *> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty())
        {
            int len = q.size();
            int temp;
            for (int i = 0; i < len; i++)
            {
                Node *curr = q.front();
                q.pop();
                temp = curr->data;
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