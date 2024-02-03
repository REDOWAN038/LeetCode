class Solution {
public:
    int dfs(int i,int n,int k,vector<int>&arr,vector<int>&dp){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int cur_max=0,res=0;

        for(int j=i;j<min(n,i+k);j++){
            cur_max = max(cur_max,arr[j]);
            res = max(res,((cur_max*(j-i+1)) + dfs(j+1,n,k,arr,dp)));
        }

        return dp[i] = res;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,-1);
        return dfs(0,arr.size(),k,arr,dp);
    }
};