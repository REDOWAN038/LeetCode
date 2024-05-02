class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        sort(nums.begin(),nums.end());

        while(i<j){
            int curr = nums[i]*(-1);
            if(curr==nums[j]){
                return nums[j];
            }

            if(curr<nums[j]){
                j--;
            }

            if(curr>nums[j]){
                i++;
            }
        }

        return -1;
    }
};