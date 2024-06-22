class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res=0,cnt=0,i=0,j=0,curr=0;

        while(j<nums.size()){
            if(nums[j]%2){
                curr+=1;
                cnt=0;
            }

            while(curr==k){
                if(nums[i]%2){
                    curr-=1;
                }
                i+=1;
                cnt+=1;
            }

            res+=cnt;
            j+=1;
        }

        return res;
    }
};