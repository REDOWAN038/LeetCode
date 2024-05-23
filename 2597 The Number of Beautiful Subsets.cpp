class Solution {
public:
    unordered_map<int,int>mp;

    int backtrack(int i, int k, vector<int>&nums){
        if(i==nums.size()){
            return 1;
        }

        int res = backtrack(i+1,k,nums);

        if(!mp[nums[i]-k] && !mp[nums[i]+k]){
            mp[nums[i]]+=1;
            res+=backtrack(i+1,k,nums);
            mp[nums[i]]-=1;
        }

        return res;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        return backtrack(0, k, nums)-1;
    }
};