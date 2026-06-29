/*

Appraoch

1)we have a for loop in BFS to handle these type of problems only
2)so we create a vector called lvel which stroes that particular level elements and after for loop we push that level into ans


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
    vector<vector<int>> levelOrderBottom(Node *root)
    {
        vector<vector<int>> ans;
        queue<Node *> q;
        if (root == NULL)
            return {};
        q.push(root);

        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
                level.push_back(temp->data);
            }
            ans.push_back(level);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};