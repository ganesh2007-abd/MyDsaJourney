/*

Approach

1)use BFS traversal and store the cols like col-1 and col+1 evry time we call left and right
2)for one particular col number we have to take the first number correspoding to that col number
3)So for that ,use map to store the col pairs

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
    vector<int> topView(Node *root)
    {
        // Write your code here...
        map<int, int> mpp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            Node *crr = x.first;
            int dist = x.second;
            if (mpp.find(dist) == mpp.end())
            {
                mpp[dist] = crr->data;
            }
            if (crr->left != NULL)
                q.push({crr->left, dist - 1});
            if (crr->right != NULL)
                q.push({crr->right, dist + 1});
        }
        vector<int> ans;
        for (auto c : mpp)
        {
            ans.push_back(c.second);
        }
        return ans;
    }
};