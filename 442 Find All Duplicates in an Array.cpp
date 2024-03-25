class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i:nums){
            int idx=abs(i)-1;
            if(nums[idx]<0)
                result.push_back(idx+1);
            else
                nums[idx]*=-1;
        }
        return result;
    }
};