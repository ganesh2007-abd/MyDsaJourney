/*

Approach

1)always take only small subtree into your imagination -- one parent and 2 children
2)Base case will be empty tree which we will return 1
3)so now lets stand on parant node and see if your left subtree exits if that exists we have to explore that also
4)same for right child but we have special case for this ,so now we should also handle if that right child is actually a leaf or not
5)check that condition and handle it then if or if not any way we have to traverse that right subtree also ,so if its a leaf we can return 1 from base case



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
    int ProductOfRightLeaves(Node *root)
    {
        // Write Your Code Here...
        if (root == NULL)
            return 1;
        int prod = 1;
        if (root->left != NULL)
        {
            prod = prod * ProductOfRightLeaves(root->left);
        }
        if (root->right != NULL && root->right->left == NULL && root->right->right == NULL)
        {
            prod = prod * root->right->data;
        }
        if (root->right != NULL)
        {
            prod = prod * ProductOfRightLeaves(root->right);
        }
        return prod;
    }
};