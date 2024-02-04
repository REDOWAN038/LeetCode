class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        if(sum<target){
            return 0;
        }

        sum = 0;
        int l=0,r=0,len=INT_MAX;

        while(r<nums.size()){
            if(sum<target){
                sum+=nums[r];
                r+=1;
            }else{
                len = min(len,r-l);
                sum-=nums[l];
                l+=1;
            }
        }

        while(sum-nums[l]>=target){
            sum-=nums[l];
            l+=1;
        }

        len = min(len,r-l);

        if(len==INT_MAX){
            return 0;
        }else{
            return len;
        }
    }
};