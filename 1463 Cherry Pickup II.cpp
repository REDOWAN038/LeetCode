class Solution {
public:
    int row, col;

    int dfs(int i, int j, int k, vector<vector<int>>& grid,
            vector<vector<vector<int>>>& dp) {
        if (i < 0 || i >= row || j < 0 || j >= col || k < 0 || k >= col) {
            return 0;
        }

        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int cur = 0, maxx = 0;

        if (j != k) {
            cur = grid[i][j] + grid[i][k];
        } else {
            cur = grid[i][j];
        }

        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                maxx = max(maxx, cur + dfs(i + 1, j + x, k + y, grid, dp));
            }
        }

        return dp[i][j][k] = maxx;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<vector<int>>> dp(
            row, vector<vector<int>>(col, vector<int>(col, -1)));
        return dfs(0, 0, col - 1, grid, dp);
    }
};