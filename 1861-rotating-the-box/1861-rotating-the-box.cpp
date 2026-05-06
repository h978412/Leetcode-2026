class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'.'));

        for(int i=0;i<n;i++){
            int lastIndex = m-1;
            for(int j=m-1;j>=0;j--){
                char item = boxGrid[i][j];
                if(item == '*'){
                    lastIndex = j-1;
                    ans[j][n-i-1] = '*';
                }
                else if(item == '#'){
                    ans[lastIndex][n-i-1] = item;
                    lastIndex -= 1;
                }
            }
        }


        return ans;
        
    }
};