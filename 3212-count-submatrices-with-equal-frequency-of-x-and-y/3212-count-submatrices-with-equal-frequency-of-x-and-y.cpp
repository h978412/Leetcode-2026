class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>> mat(grid.size(),vector<int>(grid[0].size(),0));
        //Let's replace x and y with 1 and -a
        map<char,int>m;
        m['X'] = 1;
        m['Y'] = -1;
        m['.'] = 0;
        mat[0][0] = m[grid[0][0]];
        for(int i=1;i<grid[0].size();i++){
            mat[0][i] = m[grid[0][i]] + mat[0][i-1];
        }

        for(int i=1;i<grid.size();i++){
            int prefix = m[grid[i][0]];
            mat[i][0] = prefix + mat[i-1][0];
            for(int j=1;j<grid[0].size();j++){
                prefix += m[grid[i][j]];
                mat[i][j] = mat[i-1][j] + prefix;
            }
        }
        int count = 0;
        int xFoundAt = INT_MAX;
        for(int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if(mat[i][j] == 0 && xFoundAt <= j){
                    count++;
                }else if(mat[i][j] != 0){
                    xFoundAt = std::min(xFoundAt,j);
                }

            }
        }
        return count;

        
    }
};