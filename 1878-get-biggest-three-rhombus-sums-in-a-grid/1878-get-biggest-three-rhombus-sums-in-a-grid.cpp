class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        set<int> ans;
        for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        ans.insert(grid[i][j]); // Size 0

        for (int s = 1; i + 2 * s < row && j - s >= 0 && j + s < col; s++) {
            // Use long long if you're worried about overflow, 
            // though grid values here usually fit in int.
            int romSum = 0;

            // 1. Add the 4 corner vertices
            romSum += grid[i][j];               // Top
            romSum += grid[i + 2 * s][j];       // Bottom
            romSum += grid[i + s][j - s];       // Left
            romSum += grid[i + s][j + s];       // Right

            // 2. Add the edges (excluding the corners)
            for (int k = 1; k < s; k++) {
                romSum += grid[i + k][j + k];           // Top-right edge
                romSum += grid[i + k][j - k];           // Top-left edge
                romSum += grid[i + 2 * s - k][j + k];   // Bottom-right edge
                romSum += grid[i + 2 * s - k][j - k];   // Bottom-left edge
            }
            ans.insert(romSum);
        }
    }
}
        vector<int> finalans;
        auto it = ans.rbegin();
        while (finalans.size() < 3 && it != ans.rend()) {
            finalans.push_back(*it);
            it++;
        }
        return finalans;
    }
};