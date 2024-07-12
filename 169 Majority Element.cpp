class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,curr=0;

        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                curr=nums[i];
            }else if(nums[i]==curr){
                cnt+=1;
            }else{
                cnt-=1;
            }
        }

        return curr;
    }
};
