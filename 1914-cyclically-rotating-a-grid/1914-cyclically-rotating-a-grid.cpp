class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() - 1, n = grid[0].size() - 1;
        int T = 0, L = 0, B = m, R = n;
        while (T < B && L < R) {
            int p = k % (2 * (B-T) + 2 * (R-L));
            while (p-- > 0) {
                int temp = grid[T][L];
                for (int i = L; i < R; i++) {
                    grid[T][i] = grid[T][i + 1];
                }
                for (int i = T; i < B; i++) {
                    grid[i][R] = grid[i + 1][R];
                }
                for (int i = R ; i > L; i--) {
                    grid[B][i] = grid[B][i - 1];
                }
                for (int i = B; i > T; i--) {
                    grid[i][L] = grid[i - 1][L];
                }
                grid[T + 1][L] = temp;
            }
            T++;B--;L++;R--;
        }
        return grid;
    }
};