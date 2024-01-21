class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        
        int c1 = nums[0];
        int c2 = max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int curr = max(nums[i]+c1,c2);
            c1 = c2;
            c2 = curr;
        }

        return c2;
    }
};