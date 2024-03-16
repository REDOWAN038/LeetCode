class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero=0,one=0,res=0;
        map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero+=1;
            }else{
                one+=1;
            }

            int diff = one-zero;

            if(mp.find(diff)==mp.end()){
                mp[diff] = i;
            }

            if(one==zero){
                res = max(res, one+zero);
            }else{
                res = max(res, i-mp[diff]);
            }
        }

        return res;
    }
};