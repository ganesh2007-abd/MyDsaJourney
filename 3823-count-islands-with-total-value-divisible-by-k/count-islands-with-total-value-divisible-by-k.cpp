class Solution {
public:

    vector<vector<bool>> visited;
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    long long bfs(int i,int j,vector<vector<int>>& grid,int &m,int &n){
        visited[i][j] = true;
        long long sum = grid[i][j];
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto tmp = q.front();
            int x = tmp.first;
            int y = tmp.second;
            q.pop();
            for(auto &dir : directions){
                int dx = dir.first;
                int dy = dir.second;
                int new_x = x + dx;
                int new_y = y + dy;
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y] && grid[new_x][new_y]!=0){
                    visited[new_x][new_y] = true;
                    q.push({new_x,new_y});
                    sum += grid[new_x][new_y];
                }
            }
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        visited.assign(m,vector<bool>(n,false));
        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] != 0){
                    long long val = bfs(i,j,grid,m,n);
                    if(val % k == 0){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};