/*

Approach

1)use queue and in that keep track of pair like node,its parent
2)so at each node processing we push its left amd itself(as parent) into the queue


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
    bool areColleagues(Node *root, int x, int y)
    {
        // Write Your Code Here...
        if (root == NULL)
            return false;
        Node *x_parent = NULL;
        Node *y_parent = NULL;

        queue<pair<Node *, Node *>> q;

        q.push({root, NULL});

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto temp = q.front();
                q.pop();
                Node *node = temp.first;
                Node *parent = temp.second;

                if (node->data == x)
                {
                    x_parent = parent;
                }
                if (node->data == y)
                {
                    y_parent = parent;
                }

                if (node->left != NULL)
                    q.push({node->left, node});
                if (node->right != NULL)
                    q.push({node->right, node});
            }
            if (x_parent != NULL && y_parent != NULL)
            {
                if (x_parent == y_parent)
                    return false;
                else
                {
                    return true;
                }
            }
            if (x_parent || y_parent)
            {
                return false;
            }
        }
        return false;
    }
};