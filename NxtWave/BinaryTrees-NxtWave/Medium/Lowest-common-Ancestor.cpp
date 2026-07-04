/*

Approach

1)Use the classic DFS traversal and if we found p or q return it
2)for a node to be LCA it should be returned to ii the p and q as children
3)then that node will beLCA of p,q

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class solution
{
public:
    Node *lca(Node *root, Node *p, Node *q)
    {
        // Write your code here...
        if (root == NULL || root == q || root == p)
        {
            return root;
        }
        Node *left = lca(root->left, p, q);
        Node *right = lca(root->right, p, q);

        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        return root;
    }
};