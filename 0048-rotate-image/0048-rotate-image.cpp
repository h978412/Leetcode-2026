class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()/2;i++){
            this->rotateRow(i,matrix);
        }

    }

    void rotateRow(int row,vector<vector<int>>& m){
        for(int i=row;i<m.size()-1-row;i++){
            this->rotateAndSwap(row,i,m);
        }
    }

    void rotateAndSwap(int i, int j, vector<vector<int>>& m){
        int curr = m[i][j];
        for(int k=0;k<4;k++){
            int row = j;
            int col = m.size()-1-i;
            int temp = m[row][col];
            m[row][col] = curr;
            curr = temp;
            i =row;
            j = col;
        }
    }
};