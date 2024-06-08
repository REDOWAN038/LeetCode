class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int pref = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;

        for(int i=0;i<nums.size();i++){
            pref = (pref+nums[i])%k;

            if(mp.find(pref)!=mp.end()){
                if((i-mp[pref])>=2){
                    return true;
                }
            }else{
                mp[pref] = i;
            }
        }

        return false;
    }
};