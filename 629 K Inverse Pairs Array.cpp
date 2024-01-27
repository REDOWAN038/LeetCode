class Solution {
public:
    const int mod = 1e9+7;
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {1};
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int k=0;k<=min(j,i-1);k++){
                    if(j-k>=0){
                        dp[i][j] = (dp[i][j]+dp[i-1][j-k])%mod;
                    }
                }
            }
        }

        return dp[n][k];
    }
};