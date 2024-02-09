class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxx = 1;
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    maxx = max(maxx,dp[i]);
                }
            }
        }

        vector<int>res;
        int prev = -1;

        for(int i=n-1;i>=0;i--){
            if(dp[i]==maxx && (prev==-1 || prev%nums[i]==0)){
                res.push_back(nums[i]);
                prev = nums[i];
                maxx-=1;
            }
        }

        return res;
    }
};