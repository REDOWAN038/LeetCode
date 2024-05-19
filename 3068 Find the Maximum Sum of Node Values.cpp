class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0;
        int n = nums.size();
        vector<int> v(n);

        for(int i=0;i<n;i++){
            sum+=nums[i];
            v[i] = (nums[i]^k)-nums[i];
        }

        sort(v.begin(), v.end(), greater<int>());

        for(int i=0;i<n-1;i+=2){
            if(v[i]+v[i+1]>0){
                sum+=(v[i]+v[i+1]);
            }else{
                break;
            }
        }

        return sum;
    }
};