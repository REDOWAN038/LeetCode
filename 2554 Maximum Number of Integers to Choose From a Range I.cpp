class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,bool>mp;

        for(int i=0;i<banned.size();i++){
            mp[banned[i]] = true;
        }

        int sum=0,cnt=0,curr=1;

        while(sum+curr<=maxSum && curr<=n){
            if(!mp[curr]){
                sum+=curr;
                cnt++;
            }
            curr++;
        }

        return cnt;
    }
};