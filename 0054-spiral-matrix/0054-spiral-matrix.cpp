class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rowStart = 0;int colStart = 0;
        int rowEnd = matrix.size()-1;
        int colEnd = matrix[0].size()-1;
        int i,j;
        while(rowStart < rowEnd && colStart < colEnd){
            i =rowStart;
            j = colStart;
            while(j<colEnd){
                ans.push_back(matrix[i][j]);
                j++;
            }
            while(i<rowEnd){
                ans.push_back(matrix[i][j]);
                i++;
            }
            while(j>colStart){
                ans.push_back(matrix[i][j]);
                j--;
            }
            while(i>rowStart){
                ans.push_back(matrix[i][j]);
                i--;
            }
            rowStart++;
            colStart++;
            rowEnd--;
            colEnd--;
        }
        if(rowStart == rowEnd){
            while(colStart <= colEnd){
                ans.push_back(matrix[rowStart][colStart]);
                colStart++;
            }
        }
        if(colStart == colEnd){
            while(rowStart <= rowEnd){
                ans.push_back(matrix[rowStart][colStart]);
                rowStart++;
            }
        }

        return ans;

    }
};