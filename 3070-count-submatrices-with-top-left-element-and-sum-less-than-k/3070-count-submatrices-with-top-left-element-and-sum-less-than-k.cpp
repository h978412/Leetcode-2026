class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        for(int j=1;j<grid[0].size();j++){
                grid[0][j] += grid[0][j-1];
        }
        for(int i=1;i<grid.size();i++){
            int prefix = grid[i][0];
            grid[i][0] += grid[i-1][0];
            for(int j=1;j<grid[0].size();j++){
                prefix += grid[i][j];
                grid[i][j] = prefix + grid[i-1][j];
            }
        }

        int count=0;
        for(auto &row : grid){
            for(auto& el : row){
                if(el <= k) count++;
                else break;
            }
        }

        return count;

        
    }
};