class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long tot=0;
        
        for(int i=0;i<nums.size();i++){
            tot^=nums[i];
        }

        int mask = tot&(-tot);
        int a=0,b=0;

        for(int i=0;i<nums.size();i++){
            if(mask&nums[i]){
                a^=nums[i];
            }else{
                b^=nums[i];
            }
        }

        return {a,b};
    }
};