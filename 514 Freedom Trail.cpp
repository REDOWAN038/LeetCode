class Solution {
public:
    int n,m;
    
    int f(int i,int j,string& ring,string& key,vector<vector<int>>& dp){
        if(j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans =INT_MAX;
        for(int ind = 0; ind < n; ind++){
            if(ring[ind] == key[j]){
                int steps = min(abs(i - ind), n - abs(i - ind));
                ans = min(ans, steps + f(ind,j+1,ring,key,dp));
            }
        }

        return dp[i][j] = ans;
    }

    int findRotateSteps(string ring, string key) {
        n = ring.size();
        m = key.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,ring,key,dp) + m;
    }
};