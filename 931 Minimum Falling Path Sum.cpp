class Solution {
public:
    int getMin(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp,int n){
        if(i<0 || j<0 || i>=n || j>=n){
            return INT_MAX;
        }

        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }

        if(i==n-1){
            return dp[i][j] = matrix[i][j];
        }

        int minn = INT_MAX;
        
        for(int k=j-1;k<=j+1;k++){
            minn = min(minn,getMin(i+1,k,matrix,dp,n));
        }

        return dp[i][j] = minn+matrix[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n, INT_MAX));
        int res = INT_MAX;

        for(int i=0;i<n;i++){
            res = min(res,getMin(0,i,matrix,dp,n));
        }

        return res;
    }
};