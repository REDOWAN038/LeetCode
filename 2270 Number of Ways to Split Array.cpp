class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        long long curr=0;
        int cnt=0;

        for(int i=0;i<nums.size()-1;i++){
            curr+=nums[i];
            long long rem = sum-curr;

            if(curr>=rem){
                cnt++;
            }
        }

        return cnt;
    }
};