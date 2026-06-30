/*

Approach


we take the max(leftheight,rightheight) and increment by one (for root node) and then just return it


*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class solution
{
public:
    int heightOfBinaryTree(Node *root)
    {
        // Write your code here...
        if (root == NULL)
            return 0;
        int l = heightOfBinaryTree(root->left);
        int r = heightOfBinaryTree(root->right);
        return 1 + max(l, r);
    }
};