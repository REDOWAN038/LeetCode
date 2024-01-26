class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(int n, int m, int maxx, int i, int j) {
        if (j < 0 || j >= n || i < 0 || i >= m) {
            return 1;
        }

        if (maxx == 0) {
            return 0;
        }

        if (dp[i][j][maxx] != -1) {
            return dp[i][j][maxx];
        }

        int up = solve(n, m, maxx - 1, i - 1, j);
        int down = solve(n, m, maxx - 1, i + 1, j);
        int left = solve(n, m, maxx - 1, i, j - 1);
        int right = solve(n, m, maxx - 1, i, j + 1);

        return dp[i][j][maxx] = (((up+down)%mod) + ((left+right)%mod))%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return solve(n, m, maxMove, startRow, startColumn);
    }
};