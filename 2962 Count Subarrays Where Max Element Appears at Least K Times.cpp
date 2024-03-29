class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxx = *max_element(nums.begin(), nums.end());
        int left=0,right=0,cnt=0;
        long long res = 0;

        while(right < nums.size()){
            if(nums[right]==maxx){
                cnt+=1;
            }

            while(cnt==k){
                if(nums[left]==maxx){
                    cnt-=1;
                }
                left+=1;
            }

            res+=left;
            right+=1;
        }

        return res;
    }
};