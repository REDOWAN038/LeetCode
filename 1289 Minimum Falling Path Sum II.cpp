class Solution {
public:
    int getMin(int i, int j, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==n-1){
            return grid[i][j];
        }

        if(j<0 || j>=n){
            return INT_MAX;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int minn = INT_MAX;

        for(int k=0;k<n;k++){
            if(k!=j){
                minn = min(minn, grid[i][j] + getMin(i+1, k, n, grid, dp));
            }
        }

        return dp[i][j] = minn;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), res=INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j=0;j<n;j++){
            res = min(res, getMin(0, j, n, grid, dp));
        }

        return res;
    }
};