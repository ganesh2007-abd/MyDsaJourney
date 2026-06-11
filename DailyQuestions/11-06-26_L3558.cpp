/*

Approach

1)Find the no of edges from root to node at depp level by using dfs
2)there is no need of checking 2's,,we just need the parity count of ones which is
  nc1+nc3+nc5+---- = 2power(n-1)
3)Note:During finding that 2 power,we must need to compute using loop -- at every iteration we do modulo
  for multiplying

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long mod = 1000000007;
    int getMaxEdgesToDeepestNode(const vector<vector<int>> &edges, int root)
    {
        if (edges.empty())
            return 0;

        // Find the max node index to create a perfectly sized vector array
        int maxNode = root;
        for (const auto &edge : edges)
        {
            maxNode = max({maxNode, edge[0], edge[1]});
        }

        // 1. Build adjacency list
        vector<vector<int>> adj(maxNode + 1);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // 2. Queue for BFS tracking only the node ID
        queue<int> q;
        vector<bool> visited(maxNode + 1, false);

        q.push(root);
        visited[root] = true;

        int edgeCount = -1; // Root starts at -1 so the first layer makes it 0 edges

        // 3. Process level by level
        while (!q.empty())
        {
            int nodesInCurrentLayer = q.size();
            edgeCount++; // Moving down to the next level of edges

            for (int i = 0; i < nodesInCurrentLayer; ++i)
            {
                int current = q.front();
                q.pop();

                for (int neighbor : adj[current])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }

        return edgeCount;
    }

    long long factorial(long long n)
    {
        return (n == 1 || n == 0) ? 1 : ((factorial(n - 1) % mod) * (n % mod)) % mod;
    }

    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        int n = getMaxEdgesToDeepestNode(edges, 1);

        // int count2 = n-1;
        // int count1 = 1;
        // long long tc=0;
        // while(count2 >= 0 && count1<=n){
        //     tc += factorial(n)/(factorial(count2)*factorial(count1));
        //     count2 -= 2;
        //     count1 += 2;
        // }
        // return tc%mod
        long long tc = 1;
        for (int i = 0; i < n - 1; i++)
        {
            tc = (tc * 2) % mod;
        }
        return tc;
    }
};