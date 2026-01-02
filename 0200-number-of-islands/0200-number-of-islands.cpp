class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        // vector<vector<bool>(grid[0].size(),false)> visited(grid.size());
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(visited[i][j] || grid[i][j] == '0') continue;
                else{
                    this->dsf(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
    void dsf(int i, int j,vector<vector<char>>& grid,vector<vector<bool>>& visited){
        if(i<0 || i>= grid.size() || j<0 || j >= grid[i].size()) return;
        if(visited[i][j] || grid[i][j] == '0') return;
        // cout << i << " " << j << endl;
        visited[i][j] = true;
        this->dsf(i+1,j,grid,visited);
        this->dsf(i-1,j,grid,visited);
        this->dsf(i,j+1,grid,visited);
        this->dsf(i,j-1,grid,visited);
    }
};