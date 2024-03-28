class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int left=0,right=0,cnt=0;

        while(right<nums.size()){
            mp[nums[right]]+=1;

            while(mp[nums[right]]>k){
                mp[nums[left]]-=1;
                left+=1;
            }

            cnt = std::max(cnt, right-left+1);
            right+=1;
        }

        return cnt;
    }
};