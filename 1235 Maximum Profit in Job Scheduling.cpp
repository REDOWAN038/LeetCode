class Solution {
public:
    int getProfit(int idx,vector<vector<int>>&v,vector<int>&startTime,vector<int>&dp){
        if(idx>=v.size()){
            return 0;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        int a = getProfit(idx+1,v,startTime,dp);
        int j = lower_bound(startTime.begin(),startTime.end(),v[idx][1])-startTime.begin();
        int b = v[idx][2]+getProfit(j,v,startTime,dp);
        return dp[idx] = max(a,b);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        for(int i=0;i<startTime.size();i++){
            v.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(v.begin(),v.end());
        sort(startTime.begin(),startTime.end());
        vector<int>dp(startTime.size()+1,-1);
        return getProfit(0,v,startTime,dp);
    }
};