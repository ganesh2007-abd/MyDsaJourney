#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class solution
{
public:
    Node *buildtree(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int, int> mpp)
    {
        if (prestart > preend || instart > inend)
            return NULL;
        Node *root = new Node(preorder[prestart]);
        int inroot = mpp[root->data];
        int numsleft = inroot - instart;
        root->left = buildtree(preorder, prestart + 1, prestart + numsleft, inorder, instart, inroot - 1, mpp);
        root->right = buildtree(preorder, prestart + numsleft + 1, preend, inorder, inroot + 1, inend, mpp);

        return root;
    }

    Node *buildBinaryTree(vector<int> &preorder, vector<int> &inorder)
    {
        // Write your code here...
        map<int, int> mpp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mpp[inorder[i]] = i;
        }
        Node *root = buildtree(preorder, 0, n - 1, inorder, 0, n - 1, mpp);
        return root;
    }
};