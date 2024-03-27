class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }

        int left=0,right=0,curr=1,cnt=0;

        while(right<nums.size()){
            curr*=nums[right];

            while(curr>=k){
                curr/=nums[left];
                left+=1;
            }
            
            cnt+=(right-left+1);
            right+=1;
        }

        return cnt;
    }
};