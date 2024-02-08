//  tabulation method
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }

        return dp[n];
    }
};

// memoization
class Solution {
public:
    int getRes(int n,vector<int>&dp){
        if(n<=0){
            return 0;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        int minn = INT_MAX;

        for(int i=1;i*i<=n;i++){
            int cnt = 1+getRes(n-(i*i), dp);
            minn = min(minn,cnt);
        }

        return dp[n] = minn;
    }

    int numSquares(int n) {
        vector<int>dp(n+5,-1);
        return getRes(n,dp);
    }
};