class Solution {
    int mod = 1000000007;
    vector<vector<vector<int>>>dp;

public:
    int backtrack(int i, int a, int l, int n) {
        if(a>=2 || l>=3){
            return 0;
        }

        if (i == n) {
            return 1;
        }

        if (dp[i][a][l] != -1) {
            return dp[i][a][l];
        }

        int cnt=0;
        cnt = backtrack(i+1,a,0,n);
        cnt = (cnt+backtrack(i+1,a+1,0,n))%mod;
        cnt = (cnt+backtrack(i+1,a,l+1,n))%mod;

        return dp[i][a][l]=cnt;
    }

    int checkRecord(int n) {
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return backtrack(0, 0, 0, n);
    }
};