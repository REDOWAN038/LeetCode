class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool>v(n,false);
        int dup;

        for(int i=0;i<n;i++){
            if(v[nums[i]]){
                dup = nums[i];
            }else{
                v[nums[i]] = true;
            }
        }

        for(int i=1;i<=n;i++){
            if(!v[i]){
                return {dup,i};
            }
        }

        return {};
    }
};