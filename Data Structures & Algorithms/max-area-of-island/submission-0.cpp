class Solution {
public:
    int BFS(vector<vector<int>>& grid,vector<vector<bool>>&visited, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int ans = 0;
        visited[i][j] = true;
        q.push({i,j});
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            auto [x,y] = q.front();
            ans++;
            q.pop();
            for(int k = 0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();;
        int area = 0;
        vector<vector<bool>>visited(m,vector<bool>(n,false)); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int curr = BFS(grid, visited,i,j);
                    area = max(area,curr);
                }
            }
        }
        return area;
    }
};
