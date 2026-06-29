/*

Approach

1)in this problem first we have to process the root val and then process the left and right subtress
2)which means its a preorder traversal problem
3)so do dfs(root,0) with sec param as curr sum so after encounterning every lead node you just sum up to the gloval var totalsum
4)so at every level we travel accross the binary number is left shift by one bit (means the number got multiplied by 2) and we add the curr node(root->val) to the currsum
5)after this processing of root do same for left and right subtrees by recursive calls


*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
    Node(int data, Node *left, Node *right) : data(data), left(left), right(right) {}
};

class solution
{
public:
    int totalsum = 0;

    void dfs(Node *root, int currsum)
    {
        if (root == NULL)
        {
            return;
        }
        currsum = (currsum * 2) + root->data;
        if (root->left == NULL && root->right == NULL)
        {
            totalsum += currsum;
            return;
        }

        dfs(root->left, currsum);
        dfs(root->right, currsum);
    }

    int sumRootToLeaf(Node *root)
    {
        // write your code here...
        dfs(root, 0);
        return totalsum;
    }
};