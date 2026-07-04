/*

Approach

1)they mentioned to treat our tree like complete binary tree
2)so in complete binary tree the left and rights childs indices will be 2i+1,2i+2
3)but here we dont need the exach indices we just want the width ..so to avid overflow of left(2i+1) we make our starting node as 0 and then clculates th ewidth of each level

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
    int maxWidth(Node *root)
    {
        // Write your code here...
        if (root == NULL)
            return 0;
        queue<pair<Node *, long long>> q;
        int ans = -1;
        q.push({root, 0});

        while (!q.empty())
        {
            int len = q.size();
            // long long leftmost = INT_MAX;
            // long long rightmost = INT_MIN;
            int starting = q.front().second;
            int width;
            for (int i = 0; i < len; i++)
            {
                auto top = q.front();
                q.pop();
                Node *curr = top.first;
                long long col = top.second - starting;
                // long long col=top.second;
                width = (col) + 1;
                if (curr->left)
                {
                    // leftmost = min(leftmost,2*col+1);
                    q.push({curr->left, 2 * col + 1});
                }
                if (curr->right)
                {
                    // rightmost = max(rightmost,2*col+2);
                    q.push({curr->right, 2 * col + 2});
                }
            }
            // width = rightmost - leftmost + 1;
            ans = max(ans, width);
        }
        return ans;
    }
};