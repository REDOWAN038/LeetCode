class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int l=0,h=nums.size()-1,ans=nums.size();

        while(l<=h){
            int m = (l+h)/2;

            if(nums[m]>=target){
                ans=m;
                h = m-1;
            }else{
                l = m+1;
            }
        }

        return ans;
    }

    int upperBound(vector<int>& nums, int target){
        int l=0,h=nums.size()-1,ans=nums.size();

        while(l<=h){
            int m = (l+h)/2;

            if(nums[m]>target){
                ans=m;
                h = m-1;
            }else{
                l = m+1;
            }
        }

        return ans-1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        int fidx = lowerBound(nums,target);
        int sidx = upperBound(nums,target);

        if(fidx<nums.size() && nums[fidx]==target){
            res.push_back(fidx);
        }else{
            res.push_back(-1);
        }

        if(sidx>=0 && nums[sidx]==target){
            res.push_back(sidx);
        }else{
            res.push_back(-1);
        }

        return res;

    }
};