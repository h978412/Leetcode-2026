class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size()));
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    this->dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;

        
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        if(row <0 || row >= grid.size() || col < 0 || col > grid[0].size()) return;
        if(!visited[row][col] && grid[row][col] == '1'){
            visited[row][col] = true;
            this->dfs(grid,visited,row+1,col);
            this->dfs(grid,visited,row-1,col);
            this->dfs(grid,visited,row,col+1);
            this->dfs(grid,visited,row,col-1);
        }
    }
};