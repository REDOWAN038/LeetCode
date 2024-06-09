class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pref = 0, cnt = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;

        for(int i=0;i<nums.size();i++){
            pref = (pref+nums[i]%k+k)%k;
            cnt+=mp[pref];
            mp[pref]+=1;
        }

        return cnt;
    }
};