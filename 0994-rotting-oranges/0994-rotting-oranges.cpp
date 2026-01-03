class Solution {
public:
    int n,m;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>>q;
        // vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) q.push(vector<int>{i,j,0});
            }
        }
        int t = 0;
        while(!q.empty()){
            int i = q.front()[0];
            int j = q.front()[1];
            t = q.front()[2];
            if(i+1 < n && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                q.push(vector<int>{i+1,j,t+1});
            }
            if(i-1 >= 0 && grid[i-1][j] == 1){
                grid[i-1][j] = 2;
                q.push(vector<int>{i-1,j,t+1});
            }
            if(j+1 < m && grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                q.push(vector<int>{i,j+1,t+1});
            }
            if(j-1 >=0 && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                q.push(vector<int>{i,j-1,t+1});
            }
            q.pop();
        }
        for(auto i : grid){
            for (auto j : i){
                if(j == 1) return -1;
            }
        }


        return t;
    }
};