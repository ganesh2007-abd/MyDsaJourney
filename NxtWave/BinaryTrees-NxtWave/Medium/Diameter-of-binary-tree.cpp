/*


Approach

1)When we are at some node the possible diameter can be said as height of leftree+height of rigth tree
2)we update tha ans as we want the max at each recursive call


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
    int height(Node *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int lh = height(root->left, ans);
        int rh = height(root->right, ans);
        ans = max(ans, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(Node *root)
    {
        // Write your code here...
        int ans = INT_MIN;
        int ht = height(root, ans);
        return ans;
    }
};