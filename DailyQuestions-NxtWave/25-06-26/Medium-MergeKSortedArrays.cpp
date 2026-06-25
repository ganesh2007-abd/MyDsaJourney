
/*

Approach

**in merginf 2 sorted arrays -- we compare which element to be pushed in O(1) time..so here also try to find that min in O(1) time
1)when its compulsory to use some space and its a min/max type of question always first try to use minheap/maxheap
2)Beacause the insertion just takes logn and retreival takes O(1) time
3)in min heap we store the elemetns like {element,{cord_row,cord_col}}
4)first we push all the elements in 1st col
5)then we take the top element and push the next elemtn in that row i.e (arr[i][j+1])
6)in that way its same as merging the 2 sorted arrays


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
    {
        using pp = pair<int, pair<int, int>>;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i][0], {i, 0}});
        }
        int i, j;
        while (!pq.empty())
        {
            ans.push_back(pq.top().first);
            i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();

            if (j < k - 1)
            {
                pq.push({arr[i][j + 1], {i, j + 1}});
            }
        }
        return ans;
    }
};