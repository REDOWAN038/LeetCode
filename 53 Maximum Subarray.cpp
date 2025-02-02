class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx=nums[0];

        for(int i=1;i<nums.size();i++){
            nums[i] = max(nums[i],nums[i]+nums[i-1]);
            maxx = max(maxx,nums[i]);
        }

        return maxx;
    }
};