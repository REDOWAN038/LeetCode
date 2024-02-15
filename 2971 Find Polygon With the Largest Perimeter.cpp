class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0;

        for(int i=0;i<nums.size()-1;i++){
            sum+=nums[i];
        }

        int i = nums.size()-1;

        while(i>=1){
            if(sum>nums[i]){
                return sum+nums[i];
            }
            i-=1;
            sum-=nums[i];
        }

        return -1;
    }
};