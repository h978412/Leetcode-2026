class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'.'));

        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                char item = boxGrid[i][j];
                if(item == '*' || item == '.'){
                    ans[j][n-i-1] = item;
                }else{
                    int row = j;
                    while(row < m){
                        if(row == m-1){
                            ans[row][n-i-1] = item;
                            break;
                        }
                        else{
                            if(ans[row+1][n-i-1] != '.'){
                                ans[row][n-i-1] = item;
                                break;   
                            }
                        }
                        row++;
                    }
                }
            }
        }


        return ans;
        
    }
};