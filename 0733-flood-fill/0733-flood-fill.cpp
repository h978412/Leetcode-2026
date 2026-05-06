class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(color == initialColor) return image;
        this->dfs(image,sr,sc,initialColor,color);

        return image;
    }

    void dfs(vector<vector<int>>& image, int row, int col, int initialColor, int color){
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size()) return;
        if(image[row][col] == initialColor){
            image[row][col] = color;
            this->dfs(image,row+1,col,initialColor,color);
            this->dfs(image,row-1,col,initialColor,color);
            this->dfs(image,row,col+1,initialColor,color);
            this->dfs(image,row,col-1,initialColor,color);
        }
        return;
    }
};